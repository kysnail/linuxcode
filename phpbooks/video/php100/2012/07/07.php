<?php
    echo filetype("c://").'<br>';
    echo filetype("c:/").'<br>';
    echo filetype("c:\\").'<br>';

    echo filetype("07.php").'<br>';

    $arr=scandir("c:\\");
        print_r($arr);

    # print dir
    $arr1=scandir("c:/");
        foreach($arr1 as $v)
            if (is_dir("c:/".$v)) {
            echo $v."<br>";
        }
       
    # print file
    $arr1=scandir("c:/");
        foreach($arr1 as $v)
            if (!is_dir("c:/".$v)) {
            echo $v."<br>";
        }
    
    // 下面的例子演示文字计数器的使用
    # @ - 屏蔽错误
        if (!@$f=fopen("num.txt", "r")) {
            echo "文件不存在！";
            $num = 0;
        }else{
            $num = fgets($f, 10);  // 活得 9
            fclose($f);
        }

        $num++;
        $ff = fopen("num.txt", "w");
        fwrite($ff, $num);
        fclose($ff);

        echo $num;

    // 十以内图片计数器
    echo "<br>";
    echo "<img src='img/".$num.".jpg'>";

    // 任意数字的图片计数器
    // 首先拆分数组 str_split() 函数
    echo "<br>";
    $numarr = str_split($num);
    print_r($numarr);

    echo "<br>";
    foreach($numarr as $v) {
        echo "<img src='img/".$v.".jpg'>";
    }
?>
