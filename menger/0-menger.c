#include "menger.h"

/**
 * is_filled - Check if the current position should be filled
 * @row: The current row
 * @col: The current column
 * Return: 1 if the position is filled, 0 otherwise
 */
int is_filled(int row, int col)
{
while (row > 0 || col > 0)
{
if (row % 3 == 1 && col % 3 == 1)
return (0);
row /= 3, col /= 3;
}
return (1);
}

/**
 * menger - Draws a 2D Menger Sponge
 * @level: The level of the Menger Sponge to draw
 */
void menger(int level)
{
int size, row, col;

if (level < 0)
return;

size = pow(3, level);

for (row = 0; row < size; row++)
{
for (col = 0; col < size; col++)
{
if (is_filled(row, col))
putchar('#');
else
putchar(' ');
}
putchar('\n');
}
}
