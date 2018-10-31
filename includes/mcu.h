#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	MEMORY_SIZE		100
#define	BLOCKS_LIMIT	20

// add initial address pointer start value

typedef	struct	s_memory
{
	/* read / write pointers */
	char		*start;
	char		*current_block_position;
	char		*end;
	
	/* block processing
	   for the absence of the data break */
	int			current_block_size;
	int			block_limit;

	/* memory pointer for testing */
	char		*memory_pull;

	/* just for testing */
	long long int start_address;

}				t_memory;

void	init(t_memory *memory);
void	embedded_write(t_memory *memory, char *str);