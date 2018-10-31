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

void	write(t_memory *memory, char *str)
{
	int		len;

	len = strlen(str);

	if (check_data_possibility_to_be_written_to_the_current_block(len, memory->current_block_size, memory->block_limit))
	{
		embedded_write(memory, str, len);
	}
	else
	{
		if (we have some space till the end or in the start of the memory block);
		
		memory->current_block_position = memory->current_block_position + (memory->block_limit - memory->current_block_size);
		memory->current_block_size = 0;
		embedded_write(memory, str, len);
	}
}