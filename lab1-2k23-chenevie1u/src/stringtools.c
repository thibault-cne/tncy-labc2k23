/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   stringtools.c                                                            */
/*                                                                            */
/*   By: Thibault Cheneviere <thibault.cheneviere@telecomnancy.eu>            */
/*                                                                            */
/*   Created: 2023/01/16 16:24:24 by Thibault Cheneviere                      */
/*   Updated: 2023/01/16 16:30:27 by Thibault Cheneviere                      */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stringtools.h"

char min2maj(char c) {
	if (c < 97 || c > 122)
		return c;

	return c - (97 - 65);
}

char maj2min(char c) {
	if (c < 65 || c > 90)
		return c;

	return c + (97 - 65);
}
