#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
* is_number - Check if the argument is number
* @str: String of argument
* Return: 0 if not number, 1 is number
*/

int is_number(char *str)
{
for (int i = 0; str[i] != '\0'; i++)
{
if (!isdigit(str[i]))
return (0);
}
return (1);
}

/*
* main - main function passed by arguments
* @argc: Argument count
* @argv: Argument ver
* Return: 0 if sucess
*/

int main(int argc, char *argv[])
{
long long num1, num2, result;

if (argc != 3)
{
printf("Error\n");
return (98);
}

if (!is_number(argv[1]) || !is_number(argv[2]))
{
printf("Error\n");
return (98);
}

num1 = atoll(argv[1]);
num2 = atoll(argv[2]);
if (num1 == 0 || num2 == 0)
{
printf("0\n");
return (0);
}
result = num1 * num2;

printf("%lld\n", result);

return (0);
}
