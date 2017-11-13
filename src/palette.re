let renderColor = (onSelect, color, number) => {
  let scale = 10;
  <Pixel
    x=0
    y=(scale * number / 2)
    pixelSize=(scale + 10)
    color
    onSelect=(onSelect(color))
    isSelected=false
  />
};

let make = (~onSelect, _children) => {
  ...ReasonReact.statelessComponent("Palette"),
  render: (_self) => {
    let renderColorWithCallback = renderColor(onSelect);
    <svg height="500" width="50">
      (renderColorWithCallback(Constants.mondrianColors.red, 0))
      (renderColorWithCallback(Constants.mondrianColors.blue, 1))
      (renderColorWithCallback(Constants.mondrianColors.yellow, 2))
      (renderColorWithCallback(Constants.mondrianColors.black, 3))
      (renderColorWithCallback(Constants.mondrianColors.white, 4))
    </svg>
  }
};