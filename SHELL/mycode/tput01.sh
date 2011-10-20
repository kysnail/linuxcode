#!/bin/sh

# Get number of columns and rows in a terminal.
tput cols
tput lines

# Print the current terminal name.
tput longname

# Generate a newline.
echo -n  "\n"

# Move the cursor to a position 100,100.
tput cup 50 50

# Set the background color for terminal.
# value range from 0 to 7
tput setb 5

# Set the foreground color for text.
# value range from 0 to 7
tput setf 6

# Make the text bold.
tput bold
