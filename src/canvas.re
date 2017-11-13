type action =
  | Select(int, int)
  | ChangeColor(string);

type gridPixel = {
  color: string,
  isSelected: bool
};

type state = {
  grid: array(array(gridPixel)),
  selectedColor: string
};

let renderPixel = (onSelect, pixelSize, x, y, {isSelected, color}) =>
  <Pixel key={j|$x-$y|j} x y pixelSize onSelect=(onSelect(x, y)) isSelected color />;

let renderColumns = (onSelect, pixelSize, x, rows) =>
  ReasonReact.arrayToElement(Array.mapi(renderPixel(onSelect, pixelSize, x), rows));

let makeGrid = (gridRows) =>
  Array.make_matrix(
    gridRows,
    gridRows,
    {color: Constants.mondrianColors.white, isSelected: false}
  );

let make = (~gridSize, ~gridRows, _children) => {
  ...ReasonReact.reducerComponent("Canvas"),
  initialState: () => {
    let grid = makeGrid(gridRows);
    {selectedColor: Constants.mondrianColors.black, grid}
  },
  reducer: (action, state) =>
    switch action {
    | Select(x, y) =>
      let grid = Array.copy(state.grid);
      let pixelData = grid[x][y];
      let updatedPixel = {color: state.selectedColor, isSelected: ! pixelData.isSelected};
      grid[x][y] = updatedPixel;
      ReasonReact.Update({...state, grid})
    | ChangeColor(color) => ReasonReact.Update({...state, selectedColor: color})
    },
  render: ({state, reduce}) => {
    let pixelSize = gridSize / gridRows;
    let onSelect = (x, y) => reduce((_event) => Select(x, y));
    let onSelectColor = (color) => reduce((_event) => ChangeColor(color));
    <div>
      <Palette onSelect=onSelectColor />
      <svg width=(string_of_int(gridSize)) height=(string_of_int(gridSize))>
        (ReasonReact.arrayToElement(Array.mapi(renderColumns(onSelect, pixelSize), state.grid)))
      </svg>
    </div>
  }
};