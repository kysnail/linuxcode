## QMP - QEMU Monitor Protocol
The QEMU Monitor Protocol (QMP) is a JSON-based protocol which allows applications to communicate with a QEMU insance.

有趣，终于找到一个 JSON 在 JS 之外施展能力的地方，此协议的特点如下：

QMP's main features ares:

 * Lightweight, text-based, easy to parse data format
 * Asynchronous messages support (ie. events)
 * Capabilities negotiation
 * API/ABI stability guarantees

### readconfig
最近这两天在 Mingw 平台上做了一些调查，内容主要是关于 QEMU 为什么不能够支持配置文件中的 cpu ? 在源码的阅读过程中发现，原来是需要指定 `-readconfig` 选项，并配以相应的参数文件即可。

让我感到有趣的是，配置文件的居然也采用了 JSON 格式，这样的知识点实际上是很容易帮助我拓展知识面的。


**Ref**

 * [QMP](http://wiki.qemu.org/QMP)
