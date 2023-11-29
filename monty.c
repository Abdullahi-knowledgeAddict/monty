#include "monty.h"

/*
 * main - Entry for the MONTY INTERPRETER
 * @argc: Number of Arguments passed to monty
 * @argv: The array of the null terminated arguents (string)
 *
 * Return: zero on success, EXIT_FAILURE, if the program fails at any point
 */
int main(int argc, char *argv[])
{
	char *buff;
	size_t buff_size;
	int fd;

	buff = NULL;
	buff_size = 0;
	if (argc != 2) /*checking the number of Arguments*/
	{
		write(STDERR_FILENO, "USAGE: monty <file_path>\n", 25);
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);/*attempting to open file*/
	if (fd == -1)/*Handling for failure to open*/
	{
		write(STDERR_FILENO, "Can't open file <file>\n", 23);
		exit(EXIT_FAILURE);
	}
	while (_getline(&buff, fd, &buff_size) != 0)
	{
		/*tokenize*/
		/*search for opcode*/
		/*call it function*/
		printf("%s", buff);
	}
	close(fd);
	free(buff);
	return (EXIT_SUCCESS);
}

