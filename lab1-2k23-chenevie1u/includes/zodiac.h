#ifndef ZODIAC_H
#define ZODIAC_H

#include <stdlib.h>
#include <stdio.h>

struct _date {
	int d;
	int m;
	int y;
};
typedef struct _date date_t; 

struct _sign {
	char *name;
	date_t beg_d;
	date_t end_d;
};
typedef struct _sign sign_t;

int validate_date(date_t *date);
void print_sign(date_t *date);
int check_date(date_t *date, sign_t *sign);

#endif // ZODIAC_H
