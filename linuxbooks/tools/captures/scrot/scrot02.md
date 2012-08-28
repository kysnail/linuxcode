## 抓图并移动

	# scrot -s '%Y-%m-%d--%s_$wx$h_strings.png' -q 80 -e 'mv $f /home/kangyushi/Pictures'

此命令抓取窗体，并将其移动到指定目录中。

 * -s  -> specify the window you want to capture
 * %Y  -> year
 * %m  -> month
 * %d  -> day
 * %s  -> second
 * $wx -> $w - image width; x - symbol
 * $h  -> $h - image height
 * $f  -> image path/filename (ignored when used in the filename)
 * -q  -> adjusting the quality
 * -e  -> additional operations
