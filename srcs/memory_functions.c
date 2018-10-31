#include "../includes/mcu.h"

void	init(t_memory *memory) /* configure the memory */
{
	memory->memory_pull = (char *)malloc((sizeof (char) * MEMORY_SIZE));

	memory->start = memory->memory_pull; /* start to read func */
	memory->current_block_position = memory->memory_pull;
	memory->end = memory->memory_pull + (MEMORY_SIZE - 1); /* last available block */

	/* initial addresses diagnostics */
	// printf("memory_pull_start -> %p\n",(void*)&memory->memory_pull[0]);

	// printf("start -> %p\n",(void*)memory->start);
	// printf("current -> %p\n",(void*)memory->current_block_position);
	// printf("end -> %p\n",(void*)memory->end);

	memory->current_block_size = 0;
	memory->block_limit = BLOCKS_LIMIT;

	/* diagnostics of contiguous memory allocation */
	// for(int i = 0; i < MEMORY_SIZE; i++)
	// {
	// 	printf("memory_pull_start -> %p\n",(void*)&memory->memory_pull[i]);
	// }
}

/* case: no sufficient space: 1. when the start address is 0x00 */
/* case: no sufficient space: 2. when the start address is not 0x00 -> random */
/* case: according to the block size */

void	write_possibility() /* according to the address and the block size */
{

}

void	embedded_write(t_memory *memory, char *str) /* memory wryte routine */
{
	/* memory capacity chacking function */
	int		len;

	len = strlen(str);
	sprintf(memory->current_block_position, "%s", str);

	memory->current_block_position += len;
	memory->current_block_size += len;

	// if no sufficient block move to other block
	// if move to other block -> check the capacity of other block;
}

// memory capacity diagnostics (kind of graphics);

// void	embedded_read(...) read and delete the data from the memory within the specified address; 
// check the operation arithmetics;

// erase the whole memory;