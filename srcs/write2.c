#include "../includes/mcu.h"

void	write_string(char *dst, char *src, int len) /* standard func leaves in the end '\0' */
{
	int i = 0;

	while (i < len)
	{
		dst[i]=src[i];
		i++;
	}
}

void	embedded_write(t_memory *memory, char *str, int len) /* write and move the current pointer */
{
	write_string(memory->current_block_position, str, len);
		
	memory->current_block_position += len;
	memory->current_block_size += len;
}

bool	block_capacity(int len, int current_block_size, int block_limit) /* checks if the data fit to the sublock */
{
	if ((block_limit - current_block_size - len) >= 0) 
		return (true);
	return (false);
}

bool	memory_availability(t_memory *memory)
{
	if (memory->current_block_position == memory->end /*&& memory->start == memory->start_init*/)
	{
		printf("%s\n", "end");

		memory->current_block_size = 0;
		memory->current_block_position = memory->start_init;
		return (false);
	}

	// int remaining_size = MEMORY_SIZE - (memory->blocks_total * BLOCK_SIZE);


	// remianing < block_size
	if ((memory->end - memory->current_block_position) < BLOCK_SIZE) // check ab condition // calculus is 0 or below zero; !!!!!
	{
		printf("%s\n", "calculus");
		memory->current_block_size = 0;
		memory->current_block_position = memory->start_init;
		return (false);
	}
		// printf("%s\n", "good");

	return (true);
}

void	write(t_memory *memory, char *str)
{
	int		len;

	len = strlen(str);

	printf("write -> %s\n", str);

	if (block_capacity(len, memory->current_block_size, memory->block_limit))
	{
		embedded_write(memory, str, len);

		if (memory->blocks_total == 0)	
			memory->blocks_total += 1;
		printf("%s\n", "here1");
	}
	else
	{
		printf("%s\n", "here2");

		if (memory_availability(memory))
		{
			printf("%s\n", "here3");

			if (memory->blocks_total < (MEMORY_SIZE / BLOCK_SIZE))
				memory->blocks_total += 1;

			if (memory->current_block_position != memory->start_init)
			{
				printf("%s\n", "here3.1");

				memory->current_block_position = memory->current_block_position + (memory->block_limit - memory->current_block_size);
				memory->current_block_size = 0;
			}
			embedded_write(memory, str, len);
		}
		else
		{
			// printf("%s\n", "here4");

			embedded_write(memory, str, len);

			if (memory->blocks_total < MEMORY_SIZE / BLOCK_SIZE)	
				memory->blocks_total += 1;
		}
	}
}