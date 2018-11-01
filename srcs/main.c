#include "../includes/mcu.h"

// leaks management;
// commands from the command line: menu(available memory,commands), read, write, memory usage;

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
	write(&memory, "9");
	write(&memory, "0");

	print_memory(memory.memory_pull);

	printf("total blocks -> %d\n", memory.blocks_total);

	read_one_block(&memory);
	read_one_block(&memory);
	read_one_block(&memory);
	read_one_block(&memory);
	read_one_block(&memory);

	print_memory(memory.memory_pull);

	write(&memory, "a");
	write(&memory, "b");

	write(&memory, "c");
	write(&memory, "d");

	write(&memory, "e");
	write(&memory, "f");

	write(&memory, "g");
	write(&memory, "q");


	print_memory(memory.memory_pull);
	
	read_one_block(&memory);
	read_one_block(&memory);
	read_one_block(&memory);
	read_one_block(&memory);


	print_memory(memory.memory_pull);


	write(&memory, "k");
	write(&memory, "l");

	print_memory(memory.memory_pull);
	

	read_one_block(&memory);

	write(&memory, "1");
	write(&memory, "2");

	print_memory(memory.memory_pull);

	printf("total blocks -> %d\n", memory.blocks_total);

	read_one_block(&memory);

	print_memory(memory.memory_pull);
	printf("total blocks -> %d\n", memory.blocks_total);

	// read_all_blocks(&memory);
	// print_blocks_available(&memory);

	return (0);
}