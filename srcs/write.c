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

bool	memory_availability(t_memory *memory) /* availability in the whole address space */
{
	if (memory->current_block_position == memory->end)
	{
		memory->current_block_size = 0;
		memory->current_block_position = memory->start_init;
		return (false);
	}
	else if ((memory->end - memory->current_block_position) < BLOCK_SIZE)
	{
		memory->current_block_size = 0;
		memory->current_block_position = memory->start_init;
		return (false);
	}
	return (true);
}

void	write(t_memory *memory, char *str) /* routine to write to the address space */
{
	int		len;

	len = strlen(str);

	printf("write -> %s\n", str);

	if (block_capacity(len, memory->current_block_size, memory->block_limit))
	{
		embedded_write(memory, str, len);

		if (memory->blocks_total == 0)	
			memory->blocks_total += 1;
	}
	else
	{
		if (memory->current_block_position != memory->start_init)
		{
			memory->current_block_position = memory->current_block_position + (memory->block_limit - memory->current_block_size);
			memory->current_block_size = 0;
		}
		
		if (memory_availability(memory))
		{
			if (memory->blocks_total < (MEMORY_SIZE / BLOCK_SIZE))
				memory->blocks_total += 1;

			embedded_write(memory, str, len);
		}
		else
		{
			embedded_write(memory, str, len);

			if (memory->blocks_total < MEMORY_SIZE / BLOCK_SIZE)	
				memory->blocks_total += 1;
		}
	}
}