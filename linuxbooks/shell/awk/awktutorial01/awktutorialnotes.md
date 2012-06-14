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

测试例子：

	kysnail@mydebianwork:/work$ cat calc
	3 56
	567 89
	kysnail@mydebianwork:/work$ awk '{d=($2-($1-4)); s=($2+$1); print d/sqrt(s), d*d/s }' calc 
	7.42077 55.0678
	-18.5066 342.494
	kysnail@mydebianwork:/work$ 

in above example we have a file calc with two rows and two columns. **Note that the final statement, a "print" in this case, does not need a semicolon. It doesn't hurt to put it in, though.** 

Integer variales can be used to refer to fields. If one field contains information about which other field is important, this script will print only the important field:

	kysnail@mydebianwork:/work$ awk '{ imp=$1; print $imp }' calc 
	the output is left blank.

上面这句话的意思是，可以通过这种方式实现类似指针的效果。

The special variable `NF` tells you how many fields are in this record. This script prints the first and last field from each record, regardless how many fields there are:

if now calc file is:

	3 56 abd
	567 89 xyz

using following script:

	kysnail@mydebianwork:/work$ awk '{ print $1, $NF }' calc
	3 abd
	567 xyz

### Begin and End
Any action associated with the BEGIN pattern will happen before any line-by-line processing is done. Actions with END pattern will happen after all lines are processed.

	$ cat filename
	1.One is to just mash them together, like so:
	>
	$ awk 'BEGIN { print "fee" } $1 == "foo" { print "fi" } END { print "fo fum" }' filename
	fee
	fo fum
	$ 

### AWK Arrays
awk has arrays, but they are only indexed by strings. This can be very useful, but it can also be annoying. For example, we can count frequency of words in a document (ignoring the icky part about printing them out):

	awk '{ for(i=1; i <= NF; i++) freq[$i]++ }' filename

The array will hold an integer value for each word that occured in the file. Unfortunately, this treats "foo", "Foo", and "foo," as different words. Oh well. How do we print out these frequencies? awk has a special "for" construct that loops over the values in an array. This script is longer than most command lines, so it will be expressed as an executable script:

	$ cat arraydemo01 
	#!/usr/bin/awk -f
	{for(i=1; i<=NF; i++) freq[$i]++}
	END{for(word in freq) print word, freq[word]}
	$ cat calc 
	3 56 abd
	567 89 xyz
	$ ./arraydemo01 calc 
	xyz 1
	abd 1
	56 1
	89 1
	3 1
	567 1
	$ 

### AWK Regular expressions and blocks
配合 pattern 的使用方式

	==> 1
	awk '/pattern_to_match/ {actions}' input_file
	==> 2
	awk '/foo/ { print }' abc.txt
	==> 3
	cat abc.txt | awk '/[0-9]+.[0-9]*/ { print }'

#### Expressions and blocks
fredprint
	
	$1 == "fred" { print $3 }

root

	$5 ~ /root/ { print $3 }

#### AWK Conditional statements

	awk '{
		if($1 ~ /root/)
		{
		print $1
		}
	}' /etc/password

Both scripts function identically. In the first example, the boolean expression is placed outside the block, while in the second example, the block is executed for every input line, and we selectively perform the print command by using an if statement. Both methods are available, and you can choose the one that best meshes with the other parts of your script.

	if
	{
		if($1 == "foo") {
			if($2 == "foo") {
				print "uno"
			} else {
				print "one"
			}
		} else if ($1 == "bar") {
			print "two"
		} else {
			print "three"
		}
	}

	if
	! /matchme/ { print $1 $3 $4 }
	{
		if($0 !~ /matchme/) {
			print $1 $3 $4
		}
	}

Both scripts will output only those lines that don't contains a metchme character sequence. Again, you can choose the method that works best for your code. They both do the same thing.

	( $1 == "foo" ) && ( $2 == "bar" ) { print }

This example will print only those lines where field one equals foo and field two equals bar.

## Examles
Print every line after erasing the 2nd field

	awk '{ $2 = ""; print } file

Print hi 48 times

	yes | head-48 | awk '{ print "hi" }'

Print hi.0010 to hi.0099

	$ yes | head -90 | awk '{ printf("hi00%2.0f\n", NR+9)}'
	hi0010
	hi0011
	...
	hi0099

print when column 3 is < 1900 (in myfile.txt). If a value is not numeric, it doesn't complain

	$ cat myfile.txt 
	1 2 3		4 5 6 7 8 9
	1 2 9		4 5 6 7 8 9
	1 2 10000	4 5 6 7 8 9
	1 2 900		4 5 6 7 8 9
	1 2 2000	4 5 6 7 8 9
	1 2 800		4 5 6 7 8 9
	1 2 1900	4 5 6 7 8 9
	1 2 1901	4 5 6 7 8 9
	1 2 string	4 5 6 7 8 9
	$ cat myfile.txt | awk '{if ($3 < 1900) print $3, " ", $5, $7, $8}'
	3   5 7 8
	9   5 7 8
	900   5 7 8
	800   5 7 8
	$ 

Count number of lines where col 3 > col 1

	awk '$3 > $1 { print i + "1"; i++ }' file

print only lines of less than 65 characters

	awk 'length < 64'
	
**Refs**

 * [awk tutorial](http://www.awktutorial.com/)
