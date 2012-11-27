# movtest3.s - Another example of using indexed meomory locations
# compile & link & run
# as -o movtest3.o movtest3.s
# ld -dynamic-linker /lib/ld-linx.so.2 -lc -o movtest3 movtest3.o
# ./movtest3
.section .data
output:
	.asciz "The value is %d\n"

values:
	.int 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60

.section .text
.globl _start
_start:
	nop
	movl $0, %edi
loop:
	movl values(, %edi, 4), %eax
	pushl %eax
	pushl $output
	call printf
	add $8, %esp
	inc %edi
	cmpl $11, %edi
	jne loop
	movl $0, %ebx
	movl $1, %eax
	int 0x80

