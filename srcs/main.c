#include "../includes/mcu.h"

// leaks management;

int		main(void)
{
	t_memory memory;

	init(&memory);
	
	write(&memory, "12");
	print_memory(memory.memory_pull);
	write(&memory, "56");
	print_memory(memory.memory_pull);

	// write(&memory, "3");
	// write(&memory, "4");
	// write(&memory, "5");
	// write(&memory, "6");
	write(&memory, "34");


	// write(&memory, "0");

	print_memory(memory.memory_pull);

	printf("total blocks -> %d\n", memory.blocks_total);

	read_one_block(&memory);
	read_one_block(&memory);

	print_memory(memory.memory_pull);

	// printf("%s\n", "->>>>>>>>>>>>>>>>>>");

	write(&memory, "88");
	print_memory(memory.memory_pull);

	// printf("%s\n", "->>>>>>>>>>>>>>>>>>");

	// write(&memory, "b");

	write(&memory, "c");
	print_memory(memory.memory_pull);

	write(&memory, "d");

	print_memory(memory.memory_pull);


	write(&memory, "e");
	write(&memory, "f");

	write(&memory, "g");
	write(&memory, "q");


	print_memory(memory.memory_pull);
	
	// read_one_block(&memory);
	// read_one_block(&memory);
	// read_one_block(&memory);
	// read_one_block(&memory);


	// print_memory(memory.memory_pull);

	// printf("%s\n", "->>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	write(&memory, "k");
	write(&memory, "l");
	// printf("%s\n", "->>>>>>>>>>>>>>>>>>>>>>>>>>>>>");

	print_memory(memory.memory_pull);


	// read_one_block(&memory);

	write(&memory, "1");
	write(&memory, "2");

	print_memory(memory.memory_pull);

	printf("total blocks -> %d\n", memory.blocks_total);

	read_one_block(&memory);

	print_memory(memory.memory_pull);
	printf("total blocks -> %d\n", memory.blocks_total);

	write(&memory, "55");
	print_memory(memory.memory_pull);

	write(&memory, "55");
	print_memory(memory.memory_pull);

	write(&memory, "55");
	print_memory(memory.memory_pull);

	write(&memory, "55");
	print_memory(memory.memory_pull);

	write(&memory, "55");

	print_memory(memory.memory_pull);
	printf("total blocks -> %d\n", memory.blocks_total);

	read_one_block(&memory);
	print_memory(memory.memory_pull);

	read_one_block(&memory);
	print_memory(memory.memory_pull);

	read_one_block(&memory);
	print_memory(memory.memory_pull);

	read_one_block(&memory);
	// read_all_blocks(&memory);
	print_memory(memory.memory_pull);
	printf("total blocks -> %d\n", memory.blocks_total);
	// print_blocks_available(&memory);

	write(&memory, "77");

	print_memory(memory.memory_pull);
	printf("total blocks -> %d\n", memory.blocks_total);

	write(&memory, "11");
	print_memory(memory.memory_pull);

	write(&memory, "22");
	print_memory(memory.memory_pull);

	write(&memory, "33");
	print_memory(memory.memory_pull);

	write(&memory, "44");
	print_memory(memory.memory_pull);

	write(&memory, "55");
	print_memory(memory.memory_pull);
	
	write(&memory, "66");

	print_memory(memory.memory_pull);
	printf("total blocks -> %d\n", memory.blocks_total);
	
	read_one_block(&memory);

	print_memory(memory.memory_pull);
	printf("total blocks -> %d\n", memory.blocks_total);

	return (0);
}