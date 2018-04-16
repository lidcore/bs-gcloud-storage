type t;

[@bs.send]
external exists : (t, (Js.nullable(exn), bool) => unit) => unit = "";
