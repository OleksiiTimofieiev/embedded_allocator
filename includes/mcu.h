#include <stdio.h>
#include <stdlib.h>

#define	MEMORY_SIZE		100
#define	BLOCKS_LIMIT	20

typedef	struct	s_memory
{
	/* read / write pointers */

	char		*start;
	char		*current_block_position;
	char		*end;
	
	/* block processing */
	int			current_block_size;
	int			block_limit;

	/* memory pointer for testing */

	char		*memory_pull;

}				t_memory;

void	init(t_memory *memory);