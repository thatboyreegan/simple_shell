#include "main.h"

/**
 * handle_signal_2 - handle SIGNINT.
 *
 * @i: integer.
 *
 * Return: void.
 */
void handle_signal_2(int i)
{
	(void) i;
	write(STDOUT_FILENO, "\n$ ", 3);
}
