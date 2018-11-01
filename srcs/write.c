#include "../includes/mcu.h"

void	write_string(char *dst, char *src, int len) /* standard func leave in the end '\0' */
{
	int i = 0;

	while (i < len)
	{
		dst[i]=src[i];
		i++;
	}
}

void	embedded_write(t_memory *memory, char *str, int len)
{
	write_string(memory->current_block_position, str, len);
		
	memory->current_block_position += len;
	memory->current_block_size += len;
}

bool	block_capacity(int len, int current_block_size, int block_limit) /* block capacity */
{
	if ( ( block_limit - current_block_size - len ) >= 0 )
		return (true);
	return (false);
}

bool	memory_availability(t_memory *memory)
{
	// printf("cur address -> %p\n",(void*)memory->current_block_position);
	// printf("end address -> %p\n",(void*)memory->end);

	// printf("memory start -> %p\n", (void*)memory->start);
	// printf("start_init%p\n", (void*)memory->start_init); // str compare method

	// printf("\n");
 	
 	// 1. works;
	if (memory->current_block_position == memory->end /*&& memory->start == memory->start_init*/)
	{
		memory->current_block_size = 0;
		memory->current_block_position = memory->start_init;
		// printf("%s\n", "here");
		return (false);
	}
	// 2. to test;
		// else if (current == end && start != start)
		// space = start - current_position
		// if o.k. -> write
	// 3. to test;
		// else if (start != start)
		// 	write
	// 4. to test;
		// else if (start==current)
		// block_size = 0; current = start;
	return (true);

	
}

void	write(t_memory *memory, char *str)
{
	int		len;

	len = strlen(str);

	if (block_capacity(len, memory->current_block_size, memory->block_limit))
	{
		// printf("cur address -> %p\n",(void*)memory->current_block_position);
		// printf("end address -> %p\n",(void*)memory->end);
		// printf("\n");
		embedded_write(memory, str, len);

		if (memory->blocks_total < MEMORY_SIZE / BLOCK_SIZE)	
			memory->blocks_total += 1;
		// printf("%s\n", "here1");
	}
	else
	{
		// printf("%s\n", "here2");
		if (!memory_availability(memory))
		{
			embedded_write(memory, str, len);
			if (memory->blocks_total < MEMORY_SIZE / BLOCK_SIZE)	
				memory->blocks_total += 1;
		}
		else
		{
			if (memory->blocks_total < MEMORY_SIZE / BLOCK_SIZE)
				memory->blocks_total += 1;

			memory->current_block_position = memory->current_block_position + (memory->block_limit - memory->current_block_size);
			memory->current_block_size = 0;
	
			embedded_write(memory, str, len);
		}
	}
	// printf("%s\n", "here3");
}