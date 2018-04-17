type t;

let exists: t => Callback.t(bool);

let download: (t, string) => unit;
