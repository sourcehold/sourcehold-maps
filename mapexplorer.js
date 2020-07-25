
tile_explorer_data = {};

async function cache_tile_section_explorer_map() {
    var file = document.querySelector('#tilesectionexplorerfileselect').files[0];
    var buffer = await file.arrayBuffer().then((buffer) => new InterpretationBuffer(buffer));
    var map = new Map().deserialize_from(buffer);
    map.unpack();

    tile_explorer_data.map = map;

    populate_section_selection();

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

    var unique_values = Array.from(new Set(data)).sort()
    var n = unique_values.length + 1

    var palette = create_palette(n);

    paper.clear()
    
    top_left_text = paper.text(1, 10, "x: , y: , index: , value: ").attr({'text-anchor': 'start', 'font-size': 14});


    var first_row = Math.min(document.getElementById("load_tiles_from_row").value)
    var last_row = Math.min(400, first_row + parseInt(document.getElementById("load_tiles_n_rows").value))

    var tile_width = parseInt(document.getElementById("load_tiles_tile_width").value)
    var tile_height = parseInt(document.getElementById("load_tiles_tile_height").value)

    for(var index = 0; index < 80400; index++) {
        var ti = new TileIndex(index)
        var value = data[index];
        var colour = palette[unique_values.indexOf(value)]

        var sp = ti.to_serialized_point()
        if(sp.i < first_row) {
            continue
        }
        if(sp.i >= last_row) {
            break
        }
        var screenpoint= sp.to_screen_point()
        var diamond = screenpoint.get_diamond(tile_width = tile_width, tile_height = tile_height).map((pair) => [paper.width - pair[0], pair[1]]);
        var coords = "M" + diamond.map((value) => value.join(",")).join("L") + "Z";

        var el = paper.path(coords).attr({fill: colour, stroke: colour}).data('serialized_point', sp).data('value', value).data('index', index);
        el.hover(function onEnter(ctx) {
            top_left_text.attr({text: `section: ${section_index}, x: ${this.data('serialized_point').i}, y: ${this.data('serialized_point').j}, serialized index: ${this.data('index')}, value: ${this.data('value')}`})
        }, function onLeave(ctx) {

        });
    }

    

}

function rgbToHex(r, g, b) {
    return "#" + ((1 << 24) + (r << 16) + (g << 8) + b).toString(16).slice(1);
  }
  


/* accepts parameters
 * h  Object = {h:x, s:y, v:z}
 * OR 
 * h, s, v
*/
function HSVtoRGB(h, s, v) {
    var r, g, b, i, f, p, q, t;
    if (arguments.length === 1) {
        s = h.s, v = h.v, h = h.h;
    }
    i = Math.floor(h * 6);
    f = h * 6 - i;
    p = v * (1 - s);
    q = v * (1 - f * s);
    t = v * (1 - (1 - f) * s);
    switch (i % 6) {
        case 0: r = v, g = t, b = p; break;
        case 1: r = q, g = v, b = p; break;
        case 2: r = p, g = v, b = t; break;
        case 3: r = p, g = q, b = v; break;
        case 4: r = t, g = p, b = v; break;
        case 5: r = v, g = p, b = q; break;
    }
    return {
        r: Math.round(r * 255),
        g: Math.round(g * 255),
        b: Math.round(b * 255)
    };
}

function create_palette(n) {
    var s = 0.9 / n
    var pal = [];
    for(var i = 0; i < n; i++) {
        var col = HSVtoRGB(i * s, 1, 1)
        pal.push(col);
    }
    return pal.map((el) => rgbToHex(Math.round(el.r), Math.round(el.g), Math.round(el.b)));
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