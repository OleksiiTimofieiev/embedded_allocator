#include "../includes/mcu.h"

// leaks management;

int		main(void)
{
	t_memory memory;

	init(&memory);
	
	embedded_write(&memory, "test1");
	embedded_write(&memory, "test2");
	embedded_write(&memory, "test3");



	printf("%s\n", memory.memory_pull);

	return (0);
}