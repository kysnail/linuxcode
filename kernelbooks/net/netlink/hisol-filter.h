extern int timer_delay;
extern char *interface;
extern int dev_group_id;

#define SET_TIMER_DELAY
#define SET_ADD_DEVICE
#define SET_GET_DEVICE_GROUP_ID

struct device_list {
	char* 	interface;
	int	ntlink_group_id;
	struct	device_list *next;
	skb	*skb;
	int	count;
}

struct device_list *st_device;

