#include "../includes/mcu.h"

// when the block is fully read and the current in the diapason of read -> move the current to the start of the new block;

bool	read_one_block(t_memory *memory) /* read the memory sector */
{
	if (memory->blocks_total)
	{
		// if (memory->current_block_position >= memory->read_address && memory->current_block_position <= (memory->read_address += BLOCK_SIZE))
		// 	memory->current_block_position = (memory->read_address += BLOCK_SIZE);
		
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

		if (memory->read_address == memory->end)
			memory->read_address = memory->start_init;


		return (true);
	}
	else
	{
		printf("%s\n", "no available block");
		return (false);
	}
}
