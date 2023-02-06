/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   max3_stdin.c                                                             */
/*                                                                            */
/*   By: Thibault Cheneviere <thibault.cheneviere@telecomnancy.eu>            */
/*                                                                            */
/*   Created: 2023/01/16 14:47:25 by Thibault Cheneviere                      */
/*   Updated: 2023/01/16 14:49:32 by Thibault Cheneviere                      */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/max3.h"

int main(void) {
	int a;
	int b;
	int c;

	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);

	printf("%d\n", max3(a, b, c));
}

int max3(int a, int b, int c) {
	return max_2(max_2(a, b), c);
}

int max_2(int a, int b) {
	return (a > b) ? a : b;
}
