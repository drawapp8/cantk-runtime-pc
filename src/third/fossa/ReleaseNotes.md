# Fossa Release Notes

## Release 2.0, 2015-01-19

- Project renamed to Fossa
- Simplifications
- Modularisation
- Lots of examples (Raspberry Pi, load balancer, RPC, ...)
- Many HTTP improvements forward ported from Mongoose.
- Embed dependencies (to https://github.com/cesanta/frozen[frozen])
- Async DNS client
- DNS server
- MQTT client (only QoS 0)
- MQTT broker (in progress)
- HTTP digest auth (#184)
- API documentation
- Build system overhaul
- Continuous integration with CircleCI
- Increased test coverage (97%) and report on coveralls.io
- Changed wildcard bind syntax to `:<port>`
- Added `ns_connect_http()` helper function (#132)
- Added `query_string` to parsed HTTP message (#99)
- Added websocket defragmentation capability (02717d4)
- Auto-PING idle websocket connections (#46)
- Introduced ns_connection::proto_handler (87d46da)
- Redefine SSL API (ee7847a)
- Changed HTTP API to let setting HTTP to e.g. serial connection (ac02967)
- QNX SSL upload fix (909df4f)
- Fix binding to ipv6 wildcard (#2)
- Set http_message::message.len correctly for replies with no Content-Length (#135)
- Correct ID generation in RPC reply (#73)
- Fix handling of incorrectly encoded URIs (#44)
- Fix unintuitive order of NS_CLOSE and NS_HTTP_REPLY (#20)

[issues resolved](https://github.com/cesanta/fossa/issues?q=milestone%3A"Release+2.0") |
[pull requests](https://github.com/cesanta/fossa/pulls?q=created%3A>%3D2014-05-22++merged%3A<%3D2015-01-19) |
[git tag](https://github.com/cesanta/fossa/releases/tag/2.0) |
[full diff](https://github.com/cesanta/fossa/compare/1.1...2.0)

## Release 1.1, 2014-05-22

[pull requests](https://github.com/cesanta/fossa/pulls?q=created%3A>%3D2014-03-03++merged%3A<%3D2014-05-22) |
[git tag](https://github.com/cesanta/fossa/releases/tag/1.1) |
[full diff](https://github.com/cesanta/fossa/compare/1.0...1.1)
