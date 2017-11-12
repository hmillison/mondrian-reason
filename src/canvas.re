type coordinate = {
    x: int,
    y: int
};

type action =
  | Select(int, int)
  | ChangeColor;

type state = {
    grid: array(array(string)),
    selected: {
        ..,
        
    }
}

let isSelected = (x, y, item) => item.x === x && item.y === y;

let renderPixel = (onSelect, selected, pixelSize, x, y, color) => {
    let isSelected = switch selected {
    | _ => false
    | { startPixel } => isSelected(x, y, startPixel)
    | { startPixel, endPixel } => isSelected(x, y, startPixel) && isSelected(x, y, endPixel)
    };
    /* isSelected(x, y, selected.startPixel) || isSelected(x, y, selected.endPixel); */
    <Pixel
    key={j|$x-$y|j}
    x={x}
    y={y}
    pixelSize={pixelSize}
    color={color}
    onSelect={onSelect}
    isSelected={isSelected}
    />;
};

let renderColumns = (onSelect, selected, pixelSize, x, rows) =>
  (ReasonReact.arrayToElement(Array.mapi(renderPixel(onSelect, selected, pixelSize, x), rows)));

let makeGrid = (gridRows) => Array.make_matrix(
    gridRows, gridRows, Constants.mondrianColors.white
);

let make = (~gridSize, ~gridRows, _children) => {
  ...ReasonReact.reducerComponent("Canvas"),
  initialState: () => {
      grid: makeGrid(gridRows),
      selected: {}
  },
  reducer: (action, state) =>
    switch action {
    | Select(x, y) => {
        ReasonReact.NoUpdate
    }
    | ChangeColor => ReasonReact.NoUpdate
  },
  render: ({ state, reduce }) => {
    let pixelSize = gridSize / gridRows;
    let onSelect = (x, y) => reduce((_event) => Select(x, y));
    <svg
        width=(string_of_int(gridSize))
        height=(string_of_int(gridSize))
    >
        (ReasonReact.arrayToElement(
            Array.mapi(renderColumns(onSelect, state.selected, pixelSize), state.grid)
        ))
    </svg>
  }
};