/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   occurence_main.c                                                         */
/*                                                                            */
/*   By: Thibault Cheneviere <thibault.cheneviere@telecomnancy.eu>            */
/*                                                                            */
/*   Created: 2023/01/16 16:50:00 by Thibault Cheneviere                      */
/*   Updated: 2023/01/16 17:21:12 by Thibault Cheneviere                      */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "../includes/occurence.h"

int main(void) {
	char *string = (char*) malloc(sizeof(char) * 41);
	char *c = (char*) malloc(sizeof(char) * 2);


	while (1) {
		read(0, string, sizeof(string) - 1);
		string[40] = '\0';

		if (!strncmp("exit", string, 4)) {
			break;
		}

		read(0, c, sizeof(c) - 1);

		printf("%d %d\n", first_occurrence(*c, string), last_occurrence(*c, string));
	}

	free(string);
}
