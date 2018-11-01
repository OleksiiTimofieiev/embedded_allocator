#include "../includes/mcu.h"

// leaks management;
// commands from the command line: menu(available memory,commands), read, write, memory usage;

int		main(void)
{
	t_memory memory;

	init(&memory);
	
	write(&memory, "11");
	write(&memory, "22");
	write(&memory, "3");
	write(&memory, "4");
	write(&memory, "5");
	write(&memory, "6");
	write(&memory, "7");
	write(&memory, "8");
	write(&memory, "xx");
	write(&memory, "aa");
	write(&memory, "bb");
	write(&memory, "cc");
	// write(&memory, "7");
	// write(&memory, "7");
	// write(&memory, "7");
	// write(&memory, "9");
	// write(&memory, "8");
	// write(&memory, "7");
	// write(&memory, "6");
	// write(&memory, "6");
	// write(&memory, "5");

	print_memory(memory.memory_pull);

	printf("total blocks -> %d\n", memory.blocks_total);

	read_one_block(&memory);
	read_one_block(&memory);
	read_one_block(&memory);
	read_one_block(&memory);
	read_one_block(&memory);
	read_one_block(&memory);
	read_one_block(&memory);
	

	printf("total blocks -> %d\n", memory.blocks_total);
	// print_blocks_available(&memory);

	return (0);
}