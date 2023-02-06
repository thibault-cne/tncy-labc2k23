/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   max3_args.c                                                              */
/*                                                                            */
/*   By: Thibault Cheneviere <thibault.cheneviere@telecomnancy.eu>            */
/*                                                                            */
/*   Created: 2023/01/16 14:50:06 by Thibault Cheneviere                      */
/*   Updated: 2023/01/16 14:51:37 by Thibault Cheneviere                      */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/max3.h"

int main(int argc, char **argv) {
	if (argc != 4)
		return 1;

	int a;
	int b;
	int c;

	a = atoi(argv[1]);
	b = atoi(argv[2]);
	c = atoi(argv[3]);

	printf("%d\n", max3(a, b, c));
}

int max3(int a, int b, int c) {
	return max_2(max_2(a, b), c);
}

int max_2(int a, int b) {
	return (a > b) ? a : b;
}
