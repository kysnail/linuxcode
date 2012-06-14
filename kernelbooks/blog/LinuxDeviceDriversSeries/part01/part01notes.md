## Device Drivers, Part 1: Linux Device Drivers for Your Girl Friend

### Drivers have two parts
Driver 从高层看分为两部分：

  * OS-specific 
  * Device-specific

其中 Device-specific 这部分内容在所有的操作系统上都是一致的。

    The device-specific portion of a device driver remains the same
    across all operating systems, and is more about understanding and
    decoding the device data sheet that software programming.
    A data sheet for a device is a document with technical details of the
    device, including its operation, performance, programming, etc. - in 
    short a device user manual.

### Vertical
在 Linux 中根据驱动 OS-specific 接口的不同，可以分成下面三种类型：

  * Packet-oriented or the network vertical
  * Block-oriented or the storage vertical
  * Byte-oriented or the character vertical

上述三种类型的设备，可以更细化的划分为下面的类型：

#### The network vertical

    The netword vertical consists of two parts:
    a) the network protocol stack;
    b) the network interface card (NIC) device drivers, or simply network device drivers, 
       which could be Ethernet, Wi-Fi, or any other network horizontals.

#### The storage vertical

    The storage vertical consists of two parts:
    a) File-system drivers, to decode the various formats on the different partition.
    b) Block device drivers for various storage (hardware) protocols, i.e., horizontals
       like IDE, SCSI, MTD, etc.

#### The character vertical
实际中设备多样性，上述两种描述方式并不能完整的描述。往往会将多样的设备归类到字节导向类的驱动中。

    tty drivers
    input drivers
    ....

### Multiple-vertical drivers
TODO


