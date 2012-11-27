# How to defining static symbols
.section .data
static:
	.equ factor, 3
	.equ Linux_SYS_CALL, 0x80

.section .text
.globl _start
_start:
	movl $LINUX_SYS_CALL, %eax
