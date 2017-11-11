/* This is the basic component. */
type colors = {
  red: string,
  blue: string,
  yellow: string,
  black: string,
  white: string
};

type gridPixel =
  | Some(colors);

let mondrianColors = {
  red: "D20A0F",
  blue: "3D477D",
  yellow: "FDD200",
  black: "030001",
  white: "FFFFF"
};

let gridRows = 16;

let gridSize = 500;

let grid = Array.make_matrix(gridRows, gridRows, mondrianColors.white);

/* Your familiar handleClick from ReactJS. This mandatorily takes the payload,
   then the `self` record, which contains state (none here), `handle`, `reduce`
   and other utilities */
let handleClick = (_event, _self) => Js.log("clicked!");

let renderPixel = (x, y, color) => {
  let pixelSize = gridSize / gridRows;
  <rect
    x=(string_of_int(x*pixelSize))
    y=(string_of_int(y*pixelSize))
    width=(string_of_int(pixelSize))
    height=(string_of_int(pixelSize))
    style=(ReactDOMRe.Style.make(~color, ()))
  />;
};

let renderColumns = (x, rows) =>
  ReasonReact.arrayToElement(Array.mapi((y, color) => renderPixel(x, y, color), rows));

let make = (_children) => {
  ...ReasonReact.statelessComponent("Canvas"),
  render: (_self) => <svg
    width=(string_of_int(gridSize)) height=(string_of_int(gridSize)) viewBox={j|0 0 $gridSize $gridSize|j}
  > (ReasonReact.arrayToElement(Array.mapi(renderColumns, grid))) </svg>
};