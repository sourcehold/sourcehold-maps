import React, { useRef } from 'react'
import { IsometricProjection } from 'react-isometric-projection'
import TileMesh from './TileMesh'

// https://github.com/kylejlin/react-isometric-projection
function MapV2 () {
  const svgRef = useRef<SVGSVGElement | null>(null)
  return (
    <svg ref={((r) => { svgRef.current = r })} width="100%" height="100%" viewBox="0 0 1900 800"
    // onMouseDown={e => svgRef.current?.beginScroll(e.clientX, e.clientY)}
    // onMouseMove={e => this.state.isMouseDown && this.scroll(e.clientX, e.clientY)}
    // onMouseUp={() => this.endScroll()}

    // onTouchStart={({ changedTouches: [touch] }) => this.beginScroll(touch.clientX, touch.clientY)}
    // onTouchMove={({ changedTouches: [touch] }) => this.scroll(touch.clientX, touch.clientY)}
    // onTouchEnd={() => this.endScroll()}
    >
      <rect x="0" y="0" width="100%" height="100%" fill="black" />
      <IsometricProjection x={450} y={50} size={25} mesh={TileMesh()} />
    </svg>
  )
}

export default MapV2
