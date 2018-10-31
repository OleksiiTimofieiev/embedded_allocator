#include "../includes/mcu.h"

// leaks management;

int		main(void)
{
	t_memory memory;

	init(&memory);
	
	write(&memory, "1");
	write(&memory, "2");
	write(&memory, "3");
	write(&memory, "4");
	write(&memory, "5");
	write(&memory, "6");
	write(&memory, "7");
	write(&memory, "8");






	// printf("%s\n", memory.memory_pull);

	// write(&memory, "12345678910");
	// write(&memory, "123456789");

	// write(&memory, "aaa");
	// write(&memory, "bbb");
	// write(&memory, "ccc");






	printf("%s\n", memory.memory_pull);


	printf("%ld\n", memory.end - memory.current_block_position); /* till the end of the block when the start remains unchanged */



	return (0);
}