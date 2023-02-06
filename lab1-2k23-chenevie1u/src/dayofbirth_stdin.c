/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   dayofbirth_stdin.c                                                       */
/*                                                                            */
/*   By: Thibault Cheneviere <thibault.cheneviere@telecomnancy.eu>            */
/*                                                                            */
/*   Created: 2023/01/16 15:47:24 by Thibault Cheneviere                      */
/*   Updated: 2023/01/16 17:02:23 by Thibault Cheneviere                      */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dayofbirth.h"

int main(void) {
	char *name = malloc(sizeof(char) * 40);
	char *days[7] = {"Dimanche", "Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi"};

	int w;
	int day;
	int m;
	int y;
	int t;
	int b;
	int c;
	int d;

	fgets(name, 40, stdin);
	scanf("%d/%d/%d", &day, &m, &y);

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

	trim(name);
	printf("%s est né(e) un %s\n", name, days[w % 7]);
	free(name);

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

void trim(char *name) {
	int i;

	i = -1;

	while(name[++i]) {
		if (name[i] == '\n') {
			name[i] = '\0';
			return;
		}
	}

	return;
}
