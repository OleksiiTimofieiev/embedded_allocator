#include "../includes/mcu.h"

// leaks management;

int		main(void)
{
	t_memory memory;

	init(&memory);
	
	write(&memory, "11111");
	write(&memory, "22222");
	// printf("%s\n", memory.memory_pull);

	// write(&memory, "12345678910");
	// write(&memory, "123456789");

	// write(&memory, "aaa");
	// write(&memory, "bbb");
	// write(&memory, "ccc");
	write(&memory, "dddddddddddddddddddd");
	write(&memory, "dddddddddddddddddddd");
	write(&memory, "dddddddddddddddddddd");
	write(&memory, "ddddddddddddddddddd");




	printf("%s\n", memory.memory_pull);


	printf("%ld\n", memory.end - memory.current_block_position); /* till the end of the block when the start remains unchanged */



	return (0);
}