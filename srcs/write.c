#include "../includes/mcu.h"

void	write_string(char *dst, char *src, int len)
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

bool	check_data_possibility_to_be_written_to_the_current_block(int len, int current_block_size, int block_limit)
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

	if (memory->current_block_position == memory->end && memory->start == memory->start_init)
		return (false);
	return (true);
}

void	write(t_memory *memory, char *str)
{
	int		len;

	len = strlen(str);

	if (check_data_possibility_to_be_written_to_the_current_block(len, memory->current_block_size, memory->block_limit))
	{
		// printf("cur address -> %p\n",(void*)memory->current_block_position);
		// printf("end address -> %p\n",(void*)memory->end);
		// printf("\n");

		embedded_write(memory, str, len);
		// printf("%s\n", "here1");
	}
	else
	{
		// printf("%s\n", "here2");

		if (memory_availability(memory))
		{
			memory->current_block_position = memory->current_block_position + (memory->block_limit - memory->current_block_size);
			memory->current_block_size = 0;
		
			embedded_write(memory, str, len);
		}
		else
			printf("%s\n", "No available memory");
	}
	// printf("%s\n", "here3");
}