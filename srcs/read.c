#include "../includes/mcu.h"

// read active block: move the start pointer, decrease the total len of the blocks;


void	read_one_block(t_memory *memory) /* read the memory sector */
{
	if (memory->blocks_total)
	{
		int i = 0;

		while (i < BLOCK_SIZE)
			printf("%c", memory->read_address[i++]);
		printf("\n");
		memory->blocks_total -= 1;
		memory->read_address += BLOCK_SIZE;
	}
	else
		printf("%s\n", "no available block");
}

// void	read_all_blocks(t_memory *memory)
// {

// }