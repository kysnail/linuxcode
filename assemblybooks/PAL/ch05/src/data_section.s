# demo of data section
ascii:
	# Text string
	.ascii "this is demo message.\n"
asciz:
	# Null-terminated text string
	.asciz "this is demo message.\n"
byte:
	# Byte value
	.byte 1
double:
	# Double-precision floating-point number
	.double 3.1415
float:
	# Single-precision floating-point number
	.float 3.1415
int:
	# 32-bit integer number
	.int 10
long:
	# 32-bit integer number (same as .int)
	.long 100
octa:
	# 16-byte integer number
	.octa 10
quad:
	# 8-byte integer number
	.quad 10
short:
	# 16-bit integer number
	.short 10
single:
	# Single-precision floating-point number (same as .float)
	.single 10
