#include "monty.h"

/**
 * pstr - Prints the string starting at the top of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number being executed from the Monty file
 */
void pstr(stack_t **stack, unsigned int line_number)
{
    stack_t *current;
    current = *stack;

    (void)line_number;

    while (current != NULL && current->n != 0 && current->n >= 0 && current->n <= 127)
    {
        if (current->n == '\0')
            break;
        printf("%c", current->n);
        current = current->next;
    }

    printf("\n");
}