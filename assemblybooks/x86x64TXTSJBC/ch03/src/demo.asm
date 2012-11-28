; 建立一个 1.44MB 的 floppy 映像文件，名为：demo.img
;
; 生成命令： nasm demo.asm -o demo.img

;
; 用 0 填满 1.44MB floppy 的空间
times 0x168000 - ($ - $$) db 0
