"use strict"

function showTileExplorerSpinner() {
    document.getElementById('tileexplorerloader').style.display = 'block';
}
  
function hideTileExplorerSpinner() {
    document.getElementById('tileexplorerloader').style.display = 'none';
}

var tile_explorer_data = {};

async function cache_tile_section_explorer_map() {
    showTileExplorerSpinner();
    var file = document.querySelector('#tilesectionexplorerfileselect').files[0];
    var buffer = await file.arrayBuffer().then((buffer) => new InterpretationBuffer(buffer));
    var map = new Map().deserialize_from(buffer);
    map.unpack();

    tile_explorer_data.map = map;

    populate_section_selection();

    hideTileExplorerSpinner();

    return map;
}

function populate_section_selection() {
    var opts = document.getElementById("tile_explorer_section_selection");

    while(opts.length > 0) {
        opts.remove(0);
    }

    var map = tile_explorer_data.map;

    for(var i = 0; i < map.directory.section_indices.length; i++) {
        var index = map.directory.section_indices[i];
        var uncompressed_length = map.directory.section_uncompressed_lengths[i];
        if(uncompressed_length % 80400 == 0 & uncompressed_length != 0) {
            var option = document.createElement("option");
            option.value = index ;
            option.text = index ;
            opts.add(option)
        }
    }

}

async function load_tilesection(section_index) {

    showTileExplorerSpinner();

    var section_index = section_index || document.getElementById("tile_explorer_section_selection").value;

    section_index = parseInt(section_index);

    var section = tile_explorer_data.map.directory.sections[tile_explorer_data.map.directory.section_indices.indexOf(section_index)];

    var buffer = new InterpretationBuffer(section.get_data().buffer);

    var denominator = 80400;
    var datasize = buffer.size / denominator;
    
    
    if(datasize == 2) {
        var data = buffer.readShorts(80400);
    } else if(datasize == 1) {
        var data = buffer.readBytes(80400);
    } else if(datasize == 4) {
        var data = buffer.readInts(80400);
    } else {
        if(datasize == 9) {
            alert("Sorry, this explorer currently does not support this section")
        }
        throw `invalid datasize, are you sure it is a proper tilesection? ${datasize}`
    }

    var d_value = Array(400).fill().map(()=>Array(400).fill());
    var d_serialized_i = Array(400).fill().map(()=>Array(400).fill(0));
    var d_serialized_j = Array(400).fill().map(()=>Array(400).fill(0));
    var d_serialized_tile_index = Array(400).fill().map(()=>Array(400).fill(0));
    var d_adjusted_tile_number = Array(400).fill().map(()=>Array(400).fill(0));

    if(!document.getElementById("explorer_color_mode").checked) {

        data.forEach(function(value, index) {
            var p = new TileIndex(index).to_serialized_point().to_adjusted_point();
            d_value[p.i][p.j] = value;
            d_serialized_i[p.i][p.j] = new TileIndex(index).to_serialized_point().i
            d_serialized_j[p.i][p.j] = new TileIndex(index).to_serialized_point().j
            d_serialized_tile_index[p.i][p.j] = index;
            d_adjusted_tile_number[p.i][p.j] = Math.floor((p.i * 400) + p.j);
        })
    
        var dp = [
            {
              z: d_value,
              type: 'heatmap',
              colorscale: "Rainbow",
              zmin: 0,
              zmax: (2**(datasize*8))-1,
              name: "",
              customdata: nj.stack([d_serialized_i, d_serialized_j, d_serialized_tile_index, d_adjusted_tile_number], 2).tolist(),
              hovertemplate: ([ "i (serialized):%{customdata[0]:0f}",
                                "j (serialized):%{customdata[1]:0f}",
                                "j (game):%{x:0f}",
                                "tile index (serialized):%{customdata[2]:0f}",
                                "tile index (game):%{customdata[3]:0f}",
                                "value:%{z:0f}",]).join("<br>"),
            }
          ];
    } else {
        var unique_values = Array.from(new Set(data)).sort();

        var d_value = Array(400).fill().map(()=>Array(400).fill(0));
        var d_value_indexed = Array(400).fill().map(()=>Array(400).fill());

        data.forEach(function(value, index) {
            var p = new TileIndex(index).to_serialized_point().to_adjusted_point();
            d_value[p.i][p.j] = value
            d_value_indexed[p.i][p.j] = unique_values.indexOf(value);
            d_serialized_i[p.i][p.j] = new TileIndex(index).to_serialized_point().i
            d_serialized_j[p.i][p.j] = new TileIndex(index).to_serialized_point().j
            d_serialized_tile_index[p.i][p.j] = index;
            d_adjusted_tile_number[p.i][p.j] = Math.floor((p.i * 400) + p.j);
        })

        var dp = [
            {
            z: d_value_indexed,
            type: 'heatmap',
            colorscale: "Rainbow",
            zmin: 0,
            zmax: unique_values.length,
            name: "",
            customdata: nj.stack([d_serialized_i, d_serialized_j, d_serialized_tile_index, d_adjusted_tile_number, d_value], 2).tolist(),
            hovertemplate: ([ "i (serialized):%{customdata[0]:0f}",
                                "j (serialized):%{customdata[1]:0f}",
                                "j (game):%{x:0f}",
                                "tile index (serialized):%{customdata[2]:0f}",
                                "tile index (game):%{customdata[3]:0f}",
                                "value:%{customdata[4]:0f}",]).join("<br>"),
            }
        ];
        }
        
        
        var layout = {yaxis: {autorange: "reversed", scaleanchor:"x", scaleratio:1}};
        Plotly.newPlot('paper', dp, layout);
 
    hideTileExplorerSpinner();

}


class SerializedPoint {
    constructor(i, j, size = 400) {
        this.i = i;
        this.j = j;
        this.size = size;
        this.n_serialized_tiles = (2*((this.size/2)*((this.size/2)+1)));
    }

    to_tile_index() {
        if(this.i < (this.size / 2)) {
            return new TileIndex((this.i*(this.i+1)) + this.j)
        } else {
            return new TileIndex((this.n_serialized_tiles - ((this.size - this.i)*(this.size-this.i+1))) + this.j)
        }
    }

    to_adjusted_point() {
        if(this.i < this.size/2) {
            return new AdjustedPoint(this.i, this.j + Math.abs(((this.size/2)-1) - this.i));
        } else {
            return new AdjustedPoint(this.i, this.j + Math.abs((this.size/2) - this.i));
        }
    }

    to_screen_point() {

        if(this.i < this.size/2) {
            var tx = (this.i*2) + 1 - this.j
        } else {
            var tx = this.size - this.j
        }

        if(this.i < this.size/2) {
            var ty = this.j;
        } else {
            var ty = (this.i - (this.size/2)) * 2 + 1 + this.j
        }

        return new ScreenPoint(tx, ty)
    }

}

class AdjustedPoint {
    constructor(i, j, size=400) {
        this.i = i;
        this.j = j;
        this.size = size;
        this.n_serialized_tiles = (2*((this.size/2)*((this.size/2)+1)));
    }



}

class TileIndex {

    constructor(index, size=400) {
        this.index = index;
        this.size = size;
        this.n_serialized_tiles = (2*((this.size/2)*((this.size/2)+1)));
    }

    to_serialized_point() {
        if(this.index < this.n_serialized_tiles/2) {
            var i = Math.floor(0.5 * ((Math.sqrt((4*this.index) + 1)) - 1));
        } else {
            var i = Math.floor(this.size - (0.5 * ((Math.sqrt((4 * ((2 * ((this.size / 2) * ((this.size / 2) + 1))) - this.index)) + 1)) - 1)))
        }
        var index = (new SerializedPoint(i, 0)).to_tile_index().index;
        var j = this.index - index;

        return new SerializedPoint(i, j)
    }

}


class ScreenPoint {

    constructor(x, y, size=400) {
        this.x = x
        this.y = y
        this.size = size;
    }

    get_diamond(tile_width=32, tile_height=16, x_offset=16, y_offset=16) {
        var x = this.x * (tile_width/2)
        var y = this.y * (tile_height/2)

        var xoff = x + x_offset
        var yoff = y + y_offset

        var full_width = Math.floor((this.size+1) * tile_width * 0.5)
        full_width = Math.sqrt(this.size**2 + this.size**2) * tile_width
        var full_height = Math.floor(this.size * tile_height * 0.5)

        return [
            [xoff, yoff],
            [xoff + (tile_width/2), yoff + (tile_height/2)],
            [xoff, yoff + tile_height],
            [xoff - (tile_width/2), yoff + (tile_height/2)]
        ]
    }
}


class DiamondSystem {
    constructor(size = 400) {
        this.size = size;
    }

    to_screen_system(i, j) {
        
        var x = i;
        var y = j;

        if(x < this.size/2) {
            var tx = (x*2) + 1 - y
        } else {
            var tx = this.size - y
        }

        if(x < this.size/2) {
            var ty = y;
        } else {
            var ty = (x - cut) * 2 + 1 + y
        }


    }
}