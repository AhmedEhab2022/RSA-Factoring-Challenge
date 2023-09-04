#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <unistd.h>

/**
 * factorize - factorize a number
 * @n: the number to be factorized
 *
 * Return: void
 */
void factorize(uintmax_t n)
{
	u_int32_t i, j;

	for (i = 2; i <= sqrt(n); ++i)
	{
		if (n % i == 0)
		{
			j = n / i;
			printf("%ld=%ld*%ld\n", n, j, i);
			return;
		}
	}
}

/**
 * main - Entry point
 *
 * @argc: agrument counter
 * @argv: argument vector
 *
 * Return: 0 always (success)
 */
int main(int argc, char **argv)
{
	FILE *file;
	size_t len;
	char *buff = NULL;
	u_int32_t num;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: factors <file>\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&buff, &len, file) != -1)
	{
		num = atoi(buff);
		factorize(num);
	}

	return (0);
}
