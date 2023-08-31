import React, { useRef } from 'react'

// https://github.com/kylejlin/react-isometric-projection
function MapV3 () {
  const canvasRef = useRef<HTMLCanvasElement | null>(null)

  // Set up our canvas
  const canvasMaybe = canvasRef.current

  if (canvasMaybe !== null) {
    const canvas = canvasMaybe
    canvas.width = 1900
    canvas.height = 800
    const ctx2d = canvas.getContext('2d')

    if (ctx2d === null) {
      return (
        <div>
          No canvas!
        </div>
      )
    }

    const ctx = ctx2d

    // Pick out the form elements for easy access later
    const x1 = { value: 10 }
    const x2 = { value: 10 }
    const y = { value: 10 }
    const color = { value: '#ff8d4b' }

    // Animation function
    function draw () {
    // clear the canvas
      ctx.clearRect(0, 0, canvas.width, canvas.height)

      // Wobble the cube using a sine wave
      // const wobble = Math.sin(Date.now() / 250) * window.innerHeight / 50

      // draw the cube
      drawCube(
        window.innerWidth / 2,
        window.innerHeight / 2 + y.value / 2,
        Number(x1.value),
        Number(x2.value),
        Number(y.value),
        color.value
      )
    }
    draw()

    // Colour adjustment function
    // Nicked from http://stackoverflow.com/questions/5560248
    function shadeColor (color: string, percent: number) {
      color = color.substr(1)
      const num = parseInt(color, 16)
      const amt = Math.round(2.55 * percent)
      const R = (num >> 16) + amt
      const G = (num >> 8 & 0x00FF) + amt
      const B = (num & 0x0000FF) + amt
      return '#' + (0x1000000 + (R < 255 ? R < 1 ? 0 : R : 255) * 0x10000 + (G < 255 ? G < 1 ? 0 : G : 255) * 0x100 + (B < 255 ? B < 1 ? 0 : B : 255)).toString(16).slice(1)
    }

    // Draw a cube to the specified specs
    function drawCube (x: number, y: number, wx: number, wy: number, h: number, color: string) {
      ctx.beginPath()
      ctx.moveTo(x, y)
      ctx.lineTo(x - wx, y - wx * 0.5)
      ctx.lineTo(x - wx, y - h - wx * 0.5)
      ctx.lineTo(x, y - h * 1)
      ctx.closePath()
      ctx.fillStyle = shadeColor(color, -10)
      ctx.strokeStyle = color
      ctx.stroke()
      ctx.fill()

      ctx.beginPath()
      ctx.moveTo(x, y)
      ctx.lineTo(x + wy, y - wy * 0.5)
      ctx.lineTo(x + wy, y - h - wy * 0.5)
      ctx.lineTo(x, y - h * 1)
      ctx.closePath()
      ctx.fillStyle = shadeColor(color, 10)
      ctx.strokeStyle = shadeColor(color, 50)
      ctx.stroke()
      ctx.fill()

      ctx.beginPath()
      ctx.moveTo(x, y - h)
      ctx.lineTo(x - wx, y - h - wx * 0.5)
      ctx.lineTo(x - wx + wy, y - h - (wx * 0.5 + wy * 0.5))
      ctx.lineTo(x + wy, y - h - wy * 0.5)
      ctx.closePath()
      ctx.fillStyle = shadeColor(color, 20)
      ctx.strokeStyle = shadeColor(color, 60)
      ctx.stroke()
      ctx.fill()
    }
  }

  return (
    <canvas ref={(ref) => { canvasRef.current = ref }}>

    </canvas>
  )
}

export default MapV3
