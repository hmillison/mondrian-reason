type gridPixel = {
  color: string,
  isSelected: bool
};

let renderPixel = (onSelect, pixelSize, x, y, {isSelected, color}) =>
  <Pixel key={j|$x-$y|j} x y pixelSize onSelect isSelected color />;

let renderColumns = (onSelect, pixelSize, x, rows) =>
  ReasonReact.arrayToElement(Array.mapi(renderPixel(onSelect, pixelSize, x), rows));

let makeGrid = (gridRows) =>
  Array.make_matrix(
    gridRows,
    gridRows,
    {color: Constants.mondrianColors.white, isSelected: false}
  );

type action =
  | Select(int, int)
  | ChangeColor;

type state = array(array(gridPixel));

let make = (~gridSize, ~gridRows, _children) => {
  ...ReasonReact.reducerComponent("Canvas"),
  initialState: () => makeGrid(gridRows),
  reducer: (action, state) =>
    switch action {
    | Select(x, y) =>
      let pixelData = state[x][y];
      let updatedPixel = {...pixelData, isSelected: ! pixelData.isSelected};
      state[x][y] = updatedPixel;
      ReasonReact.Update(state)
    | ChangeColor => ReasonReact.NoUpdate
    },
  render: ({state, reduce}) => {
    let pixelSize = gridSize / gridRows;
    let onSelect = (x, y) => reduce((_event) => Select(x, y));
    <svg width=(string_of_int(gridSize)) height=(string_of_int(gridSize))>
      (ReasonReact.arrayToElement(Array.mapi(renderColumns(onSelect, pixelSize), state)))
    </svg>
  }
};