/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   dayofbirth.c                                                             */
/*                                                                            */
/*   By: Thibault Cheneviere <thibault.cheneviere@telecomnancy.eu>            */
/*                                                                            */
/*   Created: 2023/01/16 15:47:24 by Thibault Cheneviere                      */
/*   Updated: 2023/01/16 16:16:35 by Thibault Cheneviere                      */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dayofbirth.h"

int main(int argc, char **argv) {
	if (argc != 3)
		return 1;

	char *days[7] = {"Dimanche", "Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi"};

	int w;
	int day;
	int m;
	int y;
	int t;
	int b;
	int c;
	int d;

	sscanf(argv[2], "%d/%d/%d", &day, &m, &y);

    if (m > 2) {
        t = m - 2;
        b = y;
    } else {
        t = m + 10;
        b = y - 1;
    }

    c = floor(b / 100);
    d = b - 100 * c;

    w = day + floor(2.6 * t - 0.2) + d + floor(d / 4) + floor(c / 4) + 5 * c;

	date_t date;
	date.d = day;
	date.m = m;
	date.y = y;

	if (!validate_date(&date))
		return 1;

	printf("%s est né(e) un %s\n", argv[1], days[w % 7]);

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
