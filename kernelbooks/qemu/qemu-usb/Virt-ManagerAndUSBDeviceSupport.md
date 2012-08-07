## Virt-Manager and USB device support
Quite a few readers have been asking about support for usb device using the virt-manager management tool so I thought I'd write a short post about it. The bad news is that virt-manager currently does not support usb device passthrough. The reason is because virt-manager uses the libvirt C library for access to these hypervisor features and teh current version of libvirt (0.4.4) does not support usb device passthrough.

The only consolation is that since 0.4.4, support for usb device is being baked so the next realease of libvirt will be supporting USB devices. In fact there's already syntax that can be used with your xml configuration files describing your domains. The syntax is as follows:

	<hostdev mode='subsystem' type='usb'>
		<source>
			<vendor id='0x1234'/>
			<product id='0x1234'/>
		</source>
	</disk>

Until then, the only way to use the usb device passthrough is directly from the command line or via the monitor interface. From the command line you need the **-usb** and **-usbdevice** options when starting up your virtual machine like so:

	qemu-system-x86_64 -m 400 -hda windows.img -usb -usbdevice host:1234:5678

Go to your monitor using **Ctrl-Alt-2** and from within the monitory with your usb device connected run the following command to get the id of your usb device.	

	(qemu) info usbhost

You'll see a list of useb devices connected to your host. Now add your usb device to your guest with the following command.

	(qemu) usb_add host:1234:5678

Your usb device will now show up in your guest virtual machine.

**Refs**

[Virt-Manager and usb device support](http://www.linux-kvm.com/content/virt-manager-and-usb-device-support)
