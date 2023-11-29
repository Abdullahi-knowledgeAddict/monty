#include "monty.h"

/**
 * _getline - reads a line from a stream given through filedescriptor
 * @buff: Where the line read should be stored
 * @fd: The file descriptor to the stream, given by the OS
 * @buff_size: sizeof buffer
 *
 * Return: The no of bytes read
 */
size_t _getline(char **buff, int fd, size_t *buff_size)
{
	size_t nb; /*count of bytes read*/
	char *copy_buff, c; /*where to store each bytes*/

	nb = 0;
	if (*buff == NULL)
	{
		copy_buff = *buff;
		*buff = _realloc(*buff, *buff_size + 120, buff_size);
		if (copy_buff == *buff)/*check, if address still same*/
			return (nb);
	}
	while (read(fd, &c, 1) > 0)
	{
		if (*buff_size == nb + 2)
		{
			copy_buff = *buff;
			*buff = _realloc(*buff, *buff_size + 120, buff_size);
			if (copy_buff == *buff)
				return (nb);
		}
		(*buff)[nb++] = c;
		if (c == '\n')
			break;
	}
	(*buff)[nb] = '\0';
	return (nb);
}

/**
 * _realloc - Expands an already allocated space by malloc
 * and initialize with the formalcontent
 * @buff: pointer to the former buffer or space
 * @new_size: the new size for the buff
 * @f_size: the formal size
 *
 * Return: a pointer to the new_buff if successful. else old buffer's returned
 */
char *_realloc(char *buff, size_t new_size, size_t *f_size)
{
	size_t index;
	char *new_buff;

	index = 0;
	new_buff = malloc(sizeof(char) * new_size);
	if (new_buff == NULL)
	{
		printf("Couldn't reallocate space\n");
		return (buff);
	}
	if (buff != NULL)
	{
		while (index < *f_size)
		{
			new_buff[index] = buff[index];
			index++;
		}
	}
	*f_size = new_size;
	free(buff);
	return (new_buff);
}
