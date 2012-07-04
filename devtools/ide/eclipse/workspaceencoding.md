## Workspace 编码类型指定
在向 Eclipse 中导入项目时，发生了编码混乱的情况，查看相应的编码类型：

    项目编码类型：  ShiftJIS
    当前Workspace： Cp1252

可以通过下面方式查看当前 Workspace 所使用的编码类型：

    Window -> Preferences -> Text file encoding -> Default (Cp1252)

查看 Other 中的编码列表有

    ISO-8859-1
    US-ASCII
    UTF-16
    UTF-16BE
    UTF-16LE
    UTF-8

尝试了一下 UTF-8 编码，同样出现乱码。而如果直接在其中输入 `Shift-JIS` 则会报错。没办法，查看了一下服务器上正确导入项目的版本，发现

    Inherited from container (MS932)

联想到，应该尝试一下使用日文系统的 `codepage 932` 。于是将下面的代码填入

    Window -> Preferences -> Text file encoding -> Other (MS932)
    
系统不报错，并且正确导入项目。

问题正常解决。
