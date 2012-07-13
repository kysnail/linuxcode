## Transforming your CAPS-LOCK key into a third control key
While strolling across digg, I found an entry on **How to transform your caps-lock into a third Control key**. It basically introduces a program, called waNOCAPS, that modifies some entries in the Windows registry to do its deed.

But, can you do that in Linux/X? The answer is yes, and you don't even need to download a program, poke into undocumented area of your operating system.

Unlike Windows, all the infrastructures to remap the keyboard is already embedded in the X11 server. The program to modify key and button in X11 is called "xmodmap", and comes pre-installed. All you have to do is to open a terminal window and type:

	# xmodmap -e 'remove Lock = Caps_Lock'
	# xmodmap -e 'remove Caps_Lock = Control_L'
	# xmodmap -e 'add Control = Control_L'

From this point on, your "Caps-Lock" key should behave just like another "Control" key.

But wait, what does that mean? **THAT YOU SHOULD HAVE TO HOLD SHIFT TO YELL ONLINE**? Only if you want! You can remap the right Control key to be your new cap lock:

	# xmodmap -e 'remove Control = Control_R'
	# xmodmap -e 'keysym Control_R = Caps_Lock'
	# xmodmap -e 'add Lock = Caps_Lock'

If you prefer to leave the right Control key alone and use the right "Windows" key as your new Caps-Lock key, use the command below instead:

	# xmodmap -e 'keysym Super_R = Caps_Lock'
	# xmodmap -e 'add Lock = Caps_Lock'

Needless to say, this will only work if your keyboard has a "Windows" key (a distant relative of the infamous "any" key) :)

Note that none of the changes above is permanent. The method to make them permanent will vary according to your distribution of Linux and how you invoke X11. In Ubuntu, for instance, all you have to do is to use "pico", "nano", "vi", or your editor of choice to add the lines below to a file called `.profile` under your home directory (create the file, if necessary):

	if [ $DISPLAY ]
	then
		# Add the 3 lines below to Convert caps-locks into Control
		xmodmap -e 'remove Lock = Caps_Lock'
		xmodmap -e 'keysym Caps_Lock = Control_L'
		xmodmap -e 'add Control = Control_L'

		# Add the 3 lines below to use the Right-Control as Caps-Lock
		xmodmap -e 'remove Control = Control_R'
		xmodmap -e 'keysym Control_R = Caps_Lock'
		xmodmap -e 'add Lock = Caps_Lock'

		# Or add the 3 lines below to use the right Windows key as Caps-Lock
		xmodmap -e 'keysym Super_R = Caps_Lock'
		xmodmap -e 'add Lock = Caps_Lock'
	fi

Log out of your session and log back in. You should now be able to enjoy your new keyboard layout.
