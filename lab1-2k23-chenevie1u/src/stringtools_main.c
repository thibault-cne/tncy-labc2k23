/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   stringtools_main.c                                                       */
/*                                                                            */
/*   By: Thibault Cheneviere <thibault.cheneviere@telecomnancy.eu>            */
/*                                                                            */
/*   Created: 2023/01/16 16:31:20 by Thibault Cheneviere                      */
/*   Updated: 2023/01/16 16:33:36 by Thibault Cheneviere                      */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stringtools.h"

int main(int argc, char **argv) {
	if (argc != 2)
		return 1;

	int i;

	i = -1;

	while (argv[1][++i])
		putchar(min2maj(argv[1][i]));
	
	putchar('\n');


	i = -1;

	while (argv[1][++i])
		putchar(maj2min(argv[1][i]));
	
	putchar('\n');
}
