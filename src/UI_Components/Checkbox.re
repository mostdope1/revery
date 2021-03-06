open Revery_UI;
open Revery_Core;

let component = React.component("Checkbox");

let defaultStyle =
  Style.[
    width(50),
    height(50),
    border(~width=5, ~color=Colors.dodgerBlue),
  ];

let noop = _c => ();

let createElement =
    (
      ~children as _,
      ~checked=false,
      ~checkedColor=Colors.dodgerBlue,
      ~style=defaultStyle,
      ~onChange=noop,
      (),
    ) =>
  component(slots => {
    let (isChecked, checkBox, slots) = React.Hooks.state(checked, slots);

    let stylesToUse = Style.merge(~source=defaultStyle, ~target=style);
    let bgColor = isChecked ? checkedColor : Colors.transparentWhite;
    let checkedContent = isChecked ? {||} : "";

    (
      slots,
      <Clickable
        onClick={() => {
          checkBox(!isChecked);
          onChange(!isChecked);
        }}>
        <View
          style=Style.(
            merge(
              ~source=[
                backgroundColor(bgColor),
                justifyContent(`Center),
                alignItems(`Center),
              ],
              ~target=stylesToUse,
            )
          )>
          <Text
            text=checkedContent
            style=Style.[
              color(isChecked ? Colors.white : Colors.black),
              fontSize(30),
              fontFamily("FontAwesome5FreeSolid.otf"),
            ]
          />
        </View>
      </Clickable>,
    );
  });
