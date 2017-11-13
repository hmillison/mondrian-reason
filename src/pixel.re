let make = (~onSelect, ~isSelected, ~color, ~pixelSize, ~x, ~y, _children) => {
  ...ReasonReact.statelessComponent("Pixel"),
  render: (_self) => {
    let strokeColor = isSelected ? "orange" : "black";
    <rect
      x=(string_of_int(x * pixelSize))
      y=(string_of_int(y * pixelSize))
      width=(string_of_int(pixelSize))
      height=(string_of_int(pixelSize))
      style=(ReactDOMRe.Style.make(~fill=color, ~stroke=strokeColor, ~strokeWidth="1px", ()))
      onClick=onSelect
    />
  }
};