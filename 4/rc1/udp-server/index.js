const dgram = require("dgram");

const port = 19420;
const host = "localhost";

const server = dgram.createSocket("udp4");

server.on("listening", () => {
  const address = server.address();
  console.log(
    `Server listening on ${address.address}:${address.port} ${address.family}`
  );
});

server.on("message", (data, info) => {
  console.log(data.toString("utf-8"));
  console.log(info);
});

server.bind(port, host);
