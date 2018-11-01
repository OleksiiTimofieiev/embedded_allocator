#include "../includes/mcu.h"

void	init(t_memory *memory) /* configure the memory */
{
	memory->memory_pull = (char *) malloc( ( sizeof(char) * MEMORY_SIZE) );

	memory->start = memory->memory_pull; /* start to read func */

	// save to some hex value;

	memory->current_block_position = memory->memory_pull;
	memory->end = memory->memory_pull + MEMORY_SIZE; /* last available block */

	// /* initial addresses diagnostics */
	// printf("memory_pull_start -> %p\n",(void*)&memory->memory_pull[0]);

	// printf("start -> %p\n",(void*)memory->start);
	// printf("current -> %p\n",(void*)memory->current_block_position);
	// printf("end -> %p\n",(void*)memory->end);

	memory->current_block_size = 0;
	memory->total_blocks = 1;
	memory->block_limit = BLOCKS_LIMIT;

	/* diagnostics of contiguous memory allocation */
	// for(int i = 0; i < MEMORY_SIZE; i++)
	// {
	// 	printf("memory_pull_start -> %p\n",(void*)&memory->memory_pull[i]);
	// }

	// memory->start_address = (long long int)memory->start;
	// memory->start_address = (long long int)memory->end;

	memory->start_init = memory->memory_pull;

	memset(memory->current_block_position, ' ', MEMORY_SIZE); /* what character to use ? */
}

void	print_memory(char *str)
{
	int i = 0;

	printf("%s", "Memory contents: ");

	while (i < MEMORY_SIZE)
		printf("%c", str[i++]);
	printf(".\n");
}	

void	print_blocks_available(t_memory *memory)
{
	printf("Memory available: %ld block(s).\n", memory->end - memory->current_block_position); /* till the end of the block when the start remains unchanged */
}
