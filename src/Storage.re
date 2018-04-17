open Callback;

type t;

type config = {. [@bs.get nullable] "projectId": string};

[@bs.module] external make : option(config) => t = "@google-cloud/storage";

let make = (~config=?, ()) => make(config);

[@bs.send] external bucket : (t, string) => Bucket.t = "";

let s = make();

let b = bucket(s, "m.lidco.io");

let f =
  Bucket.file(
    b,
    "4eef6f7783b8b708080c8f2f7d7087ed62eda9b1/9a07a146-6fcb-3531-bfd2-d46bbe4cecbd.wav",
  );

let checkFile =
  File.exists(f)
  >> (
    e => {
      Js.log(e);
      Callback.return();
    }
  );

let () = Callback.finish(checkFile);

/*File.exists(f, (. _, e) => Js.log(e)); */
File.download(f, "/me/test.file");
