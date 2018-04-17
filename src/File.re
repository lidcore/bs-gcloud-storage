open LidcoreBsNode;

type t;

[@bs.send] external createReadStream : t => LidcoreBsNode.Stream.readable = "";

[@bs.send]
external createWriteStream : t => LidcoreBsNode.Stream.writable = "";

[@bs.send] external exists : (t, Callback.callback(bool)) => unit = "";

let download = (f, path) => {
  let readable = createReadStream(f);
  let writeable = Fs.createWriteStream(~path, ());
  Stream.pipe(readable, writeable);
  Stream.on(writeable, `Finish(() => Js.log("finished")));
};
