# awk tutorial

## Why awk?
The Awk text-processing programming language is a useful tool for manipulating text.

    awk 语言可以用下面的五句进行概括：

 * Awk recognizes the concepts of "file", "record", and "field".
 * A file consists of records, which by default are the lines of the line. One line becomes one record.
 * Awk operates on one record at a time.
 * A record consists of fileds, which by default are seperated by any number of spaces or tabs.
 * Field number 1 is accessed with $1, filed 2 with $2, and so forth. $0 refers to the whole record.

Now, for an explanation of the `{ print }` code block. In awk, curly braces are used to group blocks of code blocks of code together, similar to C. Inside of our block of code, we have a single print command. In awk, when a print command appears by itself, the full contents of the current line are printed.

	$ awk '{ print $0 }' /etc/passwd
	root:x:0:0:root:/root:/bin/bash
	daemon:x:1:1:daemon:/usr/sbin:/bin/sh
	bin:x:2:2:bin:/bin:/bin/sh
	sys:x:3:3:sys:/dev:/bin/sh
	sync:x:4:65534:sync:/bin:/bin/sync
	...

	or

	$ awk '{ print }' /etc/passwd
	root:x:0:0:root:/root:/bin/bash
	daemon:x:1:1:daemon:/usr/sbin:/bin/sh
	bin:x:2:2:bin:/bin:/bin/sh
	sys:x:3:3:sys:/dev:/bin/sh

In awk, the `$0` variable represents the current line, so print and print $0 do exactly the same thing.

	kysnail@mydebianwork:~$ awk '{ print "" }' /etc/passwd
	intentionally left blank

Running this script will fill your screen with "hello's".

	$ awk '{ print "hello" }' /etc/passwd
	hello
	hello
	hello
	hello

## AWK Variables
awk variables are initialized to either zero or the empty string the first time they are used.

### Variables

 * Variable declaration is not required
 * May contain any type of data, their data type may change over the life of the program
 * Must begin with a letter and continuing with letters, digits and underscores
 * Are case sensitive
 * Some of the commonly used built-in variable are:

	NR -- The current line's sequential number
	NF -- The number of fields in the current line
	FS -- The input field separator; defaults to whitespace and is reset by the -F command line parameter










**Refs**

 * [awk tutorial](http://www.awktutorial.com/)
 * []()
 * []()


