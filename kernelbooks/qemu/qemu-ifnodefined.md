## if !defined

### `#if defined()` syntax
	
	// Vl.c (in qemu)
	#if defined(__OpenBSD__)
	#include <util.h>
	#endif

### `#if !defined()` || `#ifnodef` syntax
此条件编译语法主要用于

 * 需要移植的程序模块
 * 调试的时候

	// Vl.c (in qemu)
	#ifndef CONFIG_LINUX
		/* only the linux version is qdev-ified, usb-bsd still needs this */
		if (strstart(devname, "host:", &p)) {
			dev = usb_host_device_open(usb_bus_find(-1), p);
		} else
	#endif
	
	------------------------------------------------------------------------------
	
	// Translate_init.c (target-pcc in qemu)
	#if !defined(CONFIG_USER_ONLY)
	static void spr_read_decr (void *opaque, int gprn, int aprn)
	{
		if (use_icount) {
			gen_io_start();
		}
		gen_helper_load_decr(cpu_gpr[gprn]);
		if (use_icount) {
			gen_io_end();
			gen_stop_execution(opaque);
		}
	}

	static void spr_write_decr (void *opaque, int sprn, int gprn)
	{
		if (use_icount) {
			gen_io_start();
		}
		gen_helper_store_decr (cpu_gpr[gprn]);
		if (use_icount) {
			gen_io_end();
			gen_stop_execution(opaque);
		}
	}
	#endif

