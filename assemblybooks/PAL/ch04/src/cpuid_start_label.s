#cpuid.s Sample program to extract the processor Vendor ID
# # as -o cpuid.o cpuid.s
# # ld -o cpuid cpuid.o
.section .data

# First, in the data section, a string value is declared:
## The .ascii declarative is used to declare a text string using ASCII
## characters. The string elements are predefined and placed in memory,
## with the starting memory location denoted by the label output. The
## x's are used as placeholders in the memory area reserved for the
## data variable. When the vendor ID string is extraced from the
## processor, it will be placed in the data at those memory locations.
output:
        .ascii "The processor Vendor ID is 'xxxxxxxxxxxx'\n"

# You should recognize the next section of the program form the template.
# It declares the instruction code section, and the normal starting label
# of the application.
.section .text
# The _start label is used to indicate the instruction from which the 
# program should start running. If the linker cannot find this label,
# it will produce an error message.
#
# You can use a different label besides _start as the starting point.
# You can use the -e parameter of the linker to define what the new 
# starting point is called.
#
# Besides declaring the starting label in the application, you also need
# to make the entry point available for external applications. This is
# done with the .global directive.
#
# The .global directive declares program labels that are accessible from 
# external programs. If you are writing a bunch of utilities that are
# being used by external assembly or C language programs, each function
# section label should be declared with a .global directive.
.globl _start
_start:

# The first thing the program does is load the EAX register with a value
# of zero, and then run the CPUID instruction:
	nop
        movl $0, %eax
        cpuid
# The zero value in EAX defines the CPUID output option (the Vendor ID
# string in this case). After the CPUID is run, you must clloect the
# response that is divided up between the three output registers:

# The first instruction creates a pointer to use when working with the
# output variable declared in memory. The momory location of the output
# label is loaded into the EDI register.
movl $output, %edi

# Next, the contents of the three registers containing the Vendor ID
# string pieces are placed in the appropriate locations in the data
# memory, based on the EDI pointer.
# The number outside the parentheses represent the location relative
# to the output label where the data is placed. This number is added
# to the address in the EDI register to determine what address the
# register's value is written to. This process replaces the x's that
# were used as placeholders with the actual Vendor ID string pieces (
# note that the Vendor ID string was divided into the registers in the
# string order EBX, EDX, and ECX).
movl %ebx, 28(%edi)
movl %edx, 32(%edi)
movl %ecx, 36(%edi)

# When all the Vendor ID string pieces are placed in memory, it's time
# to display the information:
# This program uses a Linux system call (int $0x80) to access the console
# display from the Linux kernel. The Linux kernel provides many preset
# functions that can be easily accessed from assembly applications. To
# access these kernel functions, you must use the int instruction code,
# when generates a software interruput, with a value of 0x80. The specific
# function that is performed is determined by the value of the EAX
# register. Without this kernel function, you would have to send each outpu
# character yourself to the proper I/O address of the display. The Linux
# system calls are a great time-save for assembly language programmers.
movl $4, %eax
movl $1, %ebx
movl $output, %ecx
movl $42, %edx
int $0x80
# The Linux write system call is used to write bytes to a file. Following
# are the parameters for the write system call:
# - EAX contains the system call value.
# - EBX contains the file descriptor to write to.
# - ECX contains the start of the string.
# - EDX contains the length of the string.
# If you are familiar with UNIX, you know that just about everything is
# handdled as a file. The standard output (STDOUT) represents the display
# terminal of the current session, and has a file descriptor of 1. Writing
# to this file descriptor displays the information on the console screen.
#
# The bytes to display are defined as a memory location to read the information
# from, and the number of bytes to display. The ECX register is loaded with
# the memory location of the output label, which defines the start of the
# string. Because the size of the output string is always the same, we can
# hard-code the size value in the EDX register.
#

# After the Vendor ID information is displayed, it's time to cleanly exit
# the program. Again, a Linux system call can help. By using system call 1
# (the exit function), the program is properly terminated, and returns to
# the command prompt. The EBX register contains the exit code value returned
# by the program to the shell. This can be used to produce different results
# in a shell script program, depending on situations within the assembly
# language program. A value of zero indicates the program executed successfully.
movl $1, %eax
movl $0, %ebx
int $0x80

