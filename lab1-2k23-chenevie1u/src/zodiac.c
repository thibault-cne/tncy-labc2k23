/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   zodiac.c                                                                 */
/*                                                                            */
/*   By: Thibault Cheneviere <thibault.cheneviere@telecomnancy.eu>            */
/*                                                                            */
/*   Created: 2023/01/16 14:56:18 by Thibault Cheneviere                      */
/*   Updated: 2023/01/16 15:46:02 by Thibault Cheneviere                      */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zodiac.h"

int main(int argc, char **argv) {
	if (argc != 2)
		return 1;

	int d;
	int m;
	int y;

	sscanf(argv[1], "%d/%d/%d", &d, &m, &y);

	date_t date;
	date.d = d;
	date.m = m;
	date.y = y;
	
	if (!validate_date(&date))
		return 1;

	print_sign(&date);
}

int validate_date(date_t *date) {
	if (date->d < 0 || date->d > 31)
		return 0;
	
	if (date->m > 12 || date->m < 0)
		return 0;

	if (date->d > 30 && (date->m == 4 || date->m == 6 || date->m == 9 || date->m == 11))
		return 0;

	if (date->d > 29 && date->m == 2)
		return 0;

	if (date->d > 28 && date->m == 2 && (date->y%400 == 0 || (date->y%4 == 0 && date->y%100 != 0)))
		return 0;

	return 1;
}

void print_sign(date_t *date) {
	sign_t list[12] = {{"Bélier", {21, 3, 0}, {19, 4, 0}}, {"Taureau", {20, 4, 0}, {20, 5, 0}}, {"Gémeaux", {21, 5, 0}, {20, 6, 0}}, {"Cancer", {21, 6, 0}, {21, 7, 0}}, {"Lion", {22, 7, 0}, {22, 8, 0}}, {"Vierge", {23, 8, 0}, {22, 9, 0}}, {"Balance", {23, 9, 0}, {22, 10, 0}}, {"Scorpion", {23, 10, 0}, {21, 11, 0}}, {"Sagittaire", {22, 11, 0}, {21, 12, 0}}, {"Capricorne", {22, 12, 0}, {19, 1, 0}}, {"Verseau", {20, 1, 0}, {18, 2, 0}}, {"Poisson", {19, 2, 0}, {20, 3, 0}}};

	int i;

	i = -1;

	while (++i < 12) {
		if (check_date(date, &list[i])) {
			printf("%s\n", list[i].name);
			return;
		}
	}

	return;
}

int check_date(date_t *date, sign_t *sign) {
	if (date->d >= sign->beg_d.d && date->m == sign->beg_d.m)
		return 1;

	if (date->d <= sign->end_d.d && date->m == sign->end_d.m)
		return 1;

	return 0;
}
