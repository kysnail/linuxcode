#Script标签与访问HTML页面

## script 标签
早期写法

    <script language="javascript"></script>
    <script language="jscript">alert("JScript")</script>
    <script language="vbscript">msgbox("VBscript")</script>
    <script></script>       // 默认 javascript

现在标准写法

    <script type="text/javascript></script>
    <script type="text/javascript1.7></script>      // ie not support
    <script type="application/javascript></script>  // ie not support

### src 属性

    <script type="text/javascript" src="demo.js">

早期的一种写法

    <input type="button" onclick="alert('Alert"!"')" />

