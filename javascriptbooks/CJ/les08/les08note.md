# Script标签与访问HTML页面
JavaScript 加载顺序的问题很重要。

## window.onload

## 或者将 script 标签放置在页面最后

## javascript 函数可以嵌套

## 遍历 html 对象的属性值

    var obj=document.getElementById("img1");
    for (var i in obj) {
        alert(i + ":" + obj[i]);
    }   

## html 的 class 标签
在 JS 脚本中如果要修改 class 标签，则需要写为 className

    this.className = "xxx";

## 伪协议

    <a href="javascript:alert('ABC')">Gogle</a>

这个 href 地址值会被传递到浏览器到地址栏被解析。
