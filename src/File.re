type t;

[@bs.send] external exists : (t, Callback.callback(bool)) => unit = "";
