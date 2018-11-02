#include "../includes/mcu.h"

bool	read_one_block(t_memory *memory) /* read the memory sector */
{
	if (memory->blocks_total) /* no block left -> nothing to read in the address space */
	{	
		int i = 0;

		printf("%s", "read -> ");

		while (i < BLOCK_SIZE)
			printf("%c", memory->read_address[i++]);

		i = 0;

		while (i < BLOCK_SIZE)
			memory->read_address[i++] = ' ';
		printf("\n");

		memory->blocks_total -= 1;
		memory->read_address += BLOCK_SIZE;

		/* in order to start the read from the address of the address space */
		if (memory->read_address == memory->end)
			memory->read_address = memory->start_init;
		else if ((memory->end - memory->read_address) < BLOCK_SIZE)
			memory->read_address = memory->start_init;
		return (true);
	}
	else
	{
		printf("%s\n", "no available block");
		return (false);
	}
}
