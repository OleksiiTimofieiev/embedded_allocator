#include <stdio.h>

#define	memory_limit	100
#define	block_limit		20

typedef	struct	s_memory
{
	/* read / write pointers */

	int			*start;
	int			*end;
	
	/* block processing */

	int			*current_block_position;
	int			current_block_size;
	int			current_block_limit;

	/* memory pointer for testing */

	int			*memory_pull;
	
}				t_memory;