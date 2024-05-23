# ULib
[![workflow status](https://github.com/vhexl/ULib/actions/workflows/cmake-multi-platform.yml/badge.svg)](https://github.com/vhexl/ULib/actions)

This repository has some common business layer implementations, that implement in the form of a module usage.

> **This repository main for my job and my own projects.**

You can use these modules via `#include`, there is a macro like `XXX_DEBUG` in all modules, and you can enable debugging logging via `#define XXX_DEBUG 1`.

Modules:
+ [uconfig](#uconfig)
+ [uprotocol](#uprotocol)

**WARNING**: That modules are not thread safe, and you should not use them in a multi-threaded environment or you must add mutexes.

## uconfig
This is config manager for embedded system
### Usage
1. Implement your config interface file(uconfig_if.c and uconfig_if.h)
2. Your need include uconfig header`#include "uconfig.h"`
3. First you must call `uconfig_init()`, this function will load config

File example:
+ Refer header: [./test/test_uconfig_if.h](./test/test_uconfig_if.h)
+ Refer source: [./test/test_uconfig_if.c](./test/test_uconfig_if.c)

## uprotocol
This easy protocol for point to point communication, look like RPC protocol, is application layer protocol

1. Each request must response(segment request may be response later)
2. The next request can only be sent after the response is received
2. Each request is independent of the other

> Timeout feature need user implementation

### Usage

1. Implement your transport interface file(uprotocol_if.c and uprotocol_if.h)
2. Your need include uconfig header`#include "uprotocol.h"`
3. Use `uptl_send` function to send request, and `uptl_process` function to handle request

File example:
+ Refer header: [./test/test_uprotocol_if.h](./test/test_uprotocol_if.h)
+ Refer source: [./test/test_uprotocol_if.c](./test/test_uprotocol_if.c)

TODO: Secure feature, for macro switch, predefine cmd handler
