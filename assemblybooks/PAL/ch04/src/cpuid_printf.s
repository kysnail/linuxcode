# cpuid_printf.s View the CPUID Vendor ID starting using C library calls
# using following command to compile & run :
# # as -o cpuid_printf.o cpuid_printf.s
# # ld -o cpuid_printf cpuid_printf.o
# cpuid_printf.o(.text+0x1f): In function `_start':
# : undefined reference to `printf'
# cpuid_printf.o(.text+0x29): In function `_start':
# : undefined reference to `exit'
# # ld -o cpuid_printf -lc cpuid_printf.o
# # ./cpuid_printf
# -bash: ./cpuid_printf: /usr/lib/libc.so.1: bad ELF interpreter: No such file or directory
# # ld -dynamic-linker /lib/ld-linux.so.2 -o cpuid_printf -lc cpuid_printf.o
# # ./cpuid_printf
# The processor Vendor ID is 'GenuineIntel'
.section .data
output:
        .asciz "The processor Vendor ID is '%s'\n"

.section .bss
        .lcomm buffer, 12

.section .text
.globl _start
_start:
        movl $0, %eax
        cpuid
        movl $buffer, %edi
        movl %ebx, (%edi)
        movl %edx, 4(%edi)
        movl %ecx, 8(%edi)
        pushl $buffer
        pushl $output
        call printf
        addl $8, %esp
        pushl $0
        call exit

