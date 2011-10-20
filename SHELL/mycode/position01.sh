#!/bin/sh
position()
{
	_R=$1
	_C=$2
	_TEXT=$3

	tput cup $_R $_C
	echo -n $_TEXT	
}




position
#if [ "$1" = "-h" ]; then
#fi
