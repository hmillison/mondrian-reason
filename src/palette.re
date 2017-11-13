let renderColor = (color, onSelect) =>
  <Pixel x=0 y=0 pixelSize=10 color onSelect=(onSelect(color)) isSelected=false />;

let make = (~onSelect, _children) => {
  ...ReasonReact.statelessComponent("Palette"),
  render: (_self) =>
    <svg>
      (renderColor(Constants.mondrianColors.red, onSelect))
      (renderColor(Constants.mondrianColors.blue, onSelect))
      (renderColor(Constants.mondrianColors.yellow, onSelect))
      (renderColor(Constants.mondrianColors.black, onSelect))
      (renderColor(Constants.mondrianColors.white, onSelect))
    </svg>
};