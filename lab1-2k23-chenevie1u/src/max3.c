/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   max3.c                                                                   */
/*                                                                            */
/*   By: Thibault Cheneviere <thibault.cheneviere@telecomnancy.eu>            */
/*                                                                            */
/*   Created: 2023/01/16 14:41:33 by Thibault Cheneviere                      */
/*   Updated: 2023/01/16 14:48:01 by Thibault Cheneviere                      */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/max3.h"

int main(void) {
	int a;
	int b;
	int c;
	int max;

	a = 1;
	b = 2;
	c = 3;

	max = max3(a, b, c);

	printf("%d\n", max);
	return 0;
}

int max3(int a, int b, int c) {
	return max_2(max_2(a, b), c);
}

int max_2(int a, int b) {
	return (a > b) ? a : b;
}
