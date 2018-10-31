#include "../includes/mcu.h"

void	init(t_memory *memory)
{
	memory->memory_pull = (char *)malloc((sizeof (char) * MEMORY_SIZE));

	memory->start = &memory->memory_pull[0];
	memory->current_block_position = &memory->memory_pull[0];
	memory->end = &memory->memory_pull[0];

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

// void	write(t_memory *memory, char *str)
// {

// }

// memory capacity diagnostics (kind of graphics);