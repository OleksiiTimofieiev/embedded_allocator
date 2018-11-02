#include "../includes/mcu.h"

void	init(t_memory *memory) /* configure the program infrastructure */
{
	memory->memory_pull = (char *)malloc((sizeof(char) * MEMORY_SIZE));

	memory->current_block_position = memory->memory_pull;
	memory->end = memory->memory_pull + MEMORY_SIZE; /* last available block */
	memory->read_address =  memory->memory_pull;
	memory->current_block_size = 0;
	memory->blocks_total = 0;
	memory->block_limit = BLOCK_SIZE;
	memory->start_init =  memory->memory_pull;
	
	memset(memory->current_block_position, ' ', MEMORY_SIZE); /* for the char memory space */
}

void	print_memory(char *str) /* simple print func which doesn`t needs '\0' */
{
	int i = 0;

	printf("%s", "Memory contents: ");

	while (i < MEMORY_SIZE)
		printf("%c", str[i++]);
	printf(".\n");
}	

void	print_blocks_available(t_memory *memory) /* active block available in memory */
{
	printf("Memory available: %ld block(s).\n", memory->end - memory->current_block_position); /* till the end of the block when the start remains unchanged */
}
