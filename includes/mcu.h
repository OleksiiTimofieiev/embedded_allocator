#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define	MEMORY_SIZE		8
#define	BLOCKS_LIMIT	2

// add initial address pointer start value

typedef	struct	s_memory
{
	/* read / write pointers */
	char			*start;
	char			*current_block_position;
	char			*end;
	
	/* block processing
	   for the absence of the data break */
	int				current_block_size;
	int				block_limit;

	/* memory pointer for testing */
	char			*memory_pull;

	/* just for testing */
	// long long int	start_address;
	// long long int	end_address;
	char			*start_init;

}				t_memory;

void			init(t_memory *memory);
void			write(t_memory *memory, char *str);
void			print_memory(char *str);
void			print_blocks_available(t_memory *memory);