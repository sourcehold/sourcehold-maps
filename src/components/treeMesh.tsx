import React from 'react'
import { meshLib } from 'react-isometric-projection'

const { jsxToObj, Group, Pyramid, Rect } = meshLib

// The comment below tells the transpiler to use jsxToObj()
//   instead of React.createElement() when transpiling JSX to function calls
/** @jsxRuntime classic */
/** @jsx jsxToObj */
export default <Group dimensions="0 0 0" viewBoxDimensions="2 2 2">
      <Rect
        position=".375 0 .375"
        dimensions=".25 1 .25"
        colors={['#420', '#420', '#301A00']}
      />
      <Pyramid
        tipPoint=".5 3 .5"
        basePoints={[
          '.125 1 .125',
          '.125 1 .875',
          '.875 1 .875',
          '.875 1 .125'
        ]}
        colors={['#050', '#050', '#060', '#058000', '#050']}
      />
</Group>
