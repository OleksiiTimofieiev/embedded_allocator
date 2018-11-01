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
	write(&memory, "7");
	write(&memory, "7");
	write(&memory, "7");
	write(&memory, "7");
	write(&memory, "7");
	write(&memory, "7");
	write(&memory, "7");
	write(&memory, "7");
	write(&memory, "9");
	write(&memory, "8");
	write(&memory, "7");
	write(&memory, "6");







	print_memory(memory.memory_pull);
	// print_blocks_available(&memory);

	return (0);
}