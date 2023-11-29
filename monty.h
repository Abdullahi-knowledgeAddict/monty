#ifndef MONTY_H
#define MONTY_H
/*External Inclusions*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

/*Definition of structures for the Interpreter*/

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer (The actual in the structure)
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack (LIFO), and or queues (FIFO)
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack(LIFO), and or queue(FIFO)
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*---> Definition of functions to handle opcode*/

/*macro like function that helps to define the functions*/

#define func(name) void name(stack_t **stack, unsigned int line_number)
/*Generating the prototypes with these macro*/
func(push);
func(pall);
func(pint);
func(pop);
func(swap);
func(add);
func(nop);
func(sub);
func(dv);
func(mul);
func(mod);
func(pchar);
func(pstr);
func(rotl);
func(rotr);
func(stack);
func(queue);

/*functions to handle opcodes end here*/

/*complementary functions*/
size_t _getline(char **buff, int fd, size_t *buff_size);
char *_realloc(char *buff,  size_t new_size, size_t *old_size);
#endif
