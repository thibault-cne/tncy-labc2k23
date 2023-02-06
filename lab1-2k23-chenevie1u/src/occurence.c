/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   occurence.c                                                              */
/*                                                                            */
/*   By: Thibault Cheneviere <thibault.cheneviere@telecomnancy.eu>            */
/*                                                                            */
/*   Created: 2023/01/16 16:45:51 by Thibault Cheneviere                      */
/*   Updated: 2023/01/16 17:20:32 by Thibault Cheneviere                      */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/occurence.h"

int first_occurrence(char c, char str[]) {
	int i;

	i = -1;

	while (str[++i]) {
		if (str[i] == c)
			return i;
	}

	return -1;
}

int last_occurrence(char c, char str[]) {
	int size;
	int i;

	size = strlen(str);
	i = size;

	while (--i > 0 && str[i]) {
		if (str[i] == c)
			return i;
	}

	return -1;
}
