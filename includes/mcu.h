#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define	MEMORY_SIZE		10
#define	BLOCK_SIZE		2

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
	int				blocks_total;

	/* memory pointer for testing */
	char			*memory_pull;

	/* just for testing */
	// long long int	start_address;
	// long long int	end_address;
	char			*start_init;
	char			*read_address;

}				t_memory;

void			init(t_memory *memory);
void			write(t_memory *memory, char *str);
void			print_memory(char *str);
void			print_blocks_available(t_memory *memory);
bool			read_one_block(t_memory *memory);
void			read_all_blocks(t_memory *memory);