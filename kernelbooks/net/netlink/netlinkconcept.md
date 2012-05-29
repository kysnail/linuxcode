##Netlink
**Netlink** is a socket-like mechanism for IPC between the kernel and user space processes, as well as between user space processes alone (like e.g., UNIX sockets) or a mixture of multiple user space and kernel space processes.

However, unlike INET sockets, it cannot traverse host boundaries, as it addresses processes by their (inherently local) PIDs.

