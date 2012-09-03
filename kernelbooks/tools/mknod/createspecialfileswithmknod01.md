# Create Special Files With 'mknod'
启动系统时，发现提示 /dev/sda 文件不存在。尝试通过 mknod 工具创建此文件。

	mknod /dev/sda b 8 0
	mknod /dev/sda1 b 8 1

## lost /dev/sda and /dev/sda1
找到了一篇较好的讨论贴。为了防止以后不见了，准备留个备份。

### Lightyear

	Hi,

	I finally managed to access the mass storage of my digital camera (Sony DSC-T1), only to find that
	after I switch off the camera, the associated devices /dev/sda and /dev/sda1 were gone forever, 
	even after reboot. Now I can't mount the device, even though /var/log/messages prompt that the 
	camera is associated with data.

	May anyone enlighten me to get the device file back?

	Thanks in advance,

	Lightyear

### anton

	Lightyear writes:
	> May anyone enlighten me to get the device file back?

	Try

	mknod /dev/sda b 8 0 
	mknod /dev/sda1 b 8 1

	-anton

### Lightyear

	> mknod /dev/sda b 8 0
	> mknod /dev/sda1 b 8 1

	Thanks a million! That works!

	However, those files are removed everytime I plug off the camera. Any
	better solutions than running mknod in rc.local?

	Also, from 'man mknod' I learn that the 'b' option refers to a block
	device, and the two numbers are major and minor device numbers,
	respectively. Do the minor numbers always refer to the number of the
	filename? What about the major number? How did you know sda's major number
	is 8?

	Once again, thanks a lot Smile


	Lightyear

### Dances With Crows

	> On Sun, 11 Jul 2004 21:36:33 +0000, Anton Ertl wrote:
	>> mknod /dev/sda b 8 0
	>> mknod /dev/sda1 b 8 1
	>
	> Thanks a million! That works!

	Something's wrong if it did. Device nodes are not deleted by anything
	that would be running. Are you using devfs? Mandrake and Gentoo use
	devfs by default. You should always say which version of which distro
	you're using, since some things vary by distro.

	> However, those files are removed everytime I unplug the camera. Any
	> better solutions than running mknod in rc.local?

	Figure out what's really going on and fix it. If you're using devfs,
	device nodes should be automatically created when you plug new devices
	in and appropriate kernel modules are loaded, then destroyed when you
	unplug the devices or unload the kernel modules. I've never seen this
	sort of thing happen on my devfs-using Gentoo systems; USB storage
	devices always take the first available SCSI device name.

	> Do the minor numbers always refer to the number of the filename? What
	> about the major number? How did you know sda's major number is 8?

	/usr/src/linux/Documentation/devices.txt is the place to go for
	information about device numbers in Linux. Major 8 minor 16 is the
	second SCSI disk, /dev/sdb. 

### Doug Laidlaw

	Dances With Crows wrote:

	> On Mon, 12 Jul 2004 06:50:10 +0800, Lightyear staggered into the Black
	> Sun and said:
	>> On Sun, 11 Jul 2004 21:36:33 +0000, Anton Ertl wrote:
	>>> mknod /dev/sda b 8 0
	>>> mknod /dev/sda1 b 8 1
	>>
	>> Thanks a million! That works!
	> 
	> Something's wrong if it did.  Device nodes are not deleted by anything
	> that would be running.  Are you using devfs?  Mandrake and Gentoo use
	> devfs by default.  You should always say which version of which distro
	> you're using, since some things vary by distro.
	> 
	>> However, those files are removed everytime I unplug the camera. Any
	>> better solutions than running mknod in rc.local?
	> 
	> Figure out what's really going on and fix it.  If you're using devfs,
	> device nodes should be automatically created when you plug new devices
	> in and appropriate kernel modules are loaded, then destroyed when you
	> unplug the devices or unload the kernel modules.  I've never seen this
	> sort of thing happen on my devfs-using Gentoo systems; USB storage
	> devices always take the first available SCSI device name.
	> 
	>> Do the minor numbers always refer to the number of the filename? What
	>> about the major number? How did you know sda's major number is 8?
	> 
	> /usr/src/linux/Documentation/devices.txt is the place to go for
	> information about device numbers in Linux.  Major 8 minor 16 is the
	> second SCSI disk, /dev/sdb.
	> 
	My MDK 10 Community keeps wanting to change /dev/scd0 to /dev/hdd and back
	again. Whatever it was last time, it will be swapped to the other on the
	next boot. Are you using Mandrake?

	Doug.
	-- 
	ICQ Number 178748389. Registered Linux User No. 277548.
	You should never put on your best trousers when you go out to fight for
	freedom and truth.
	--Henrik Ibsen.

### Lightyear

	On Fri, 16 Jul 2004 22:19:50 +1000, Doug Laidlaw wrote:
	> My MDK 10 Community keeps wanting to change /dev/scd0 to /dev/hdd and back
	> again.  Whatever it was last time, it will be swapped to the other on the
	> next boot.  Are you using Mandrake?

	I'm using Slackware 10. It's working alright now, and I'm not sure what I
	did. I reinstall many packages, and also reconfig-ed the kernel a bit and
	recompiled.

	As Anton Ertl pointed out, it was devfs messing up for some reasons. I
	looked at the log, and it removed my /dev/sda and /dev/sda1 after I
	switched off the digicam. But it never created those files when I switched
	them on again.

	I'm glad that it works now. I thought I could never be able to access my
	digicam from Linux Razz

	Thanks for all the help! Linux is wonderful.


	Lightyear
