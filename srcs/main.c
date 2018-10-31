#include "../includes/mcu.h"

// leaks management;

int		main(void)
{
	t_memory memory;

	init(&memory);
	
	embedded_write(&memory, "11111");
	embedded_write(&memory, "22222");
	embedded_write(&memory, "33333");
	embedded_write(&memory, "44444");
	embedded_write(&memory, "55555");

	printf("%s\n", memory.memory_pull);

	return (0);
}