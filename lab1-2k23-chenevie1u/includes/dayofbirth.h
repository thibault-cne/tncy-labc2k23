#ifndef DAYOFBIRTH_H
#define DAYOFBIRTH_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct _date {
	int d;
	int m;
	int y;
};
typedef struct _date date_t; 

int validate_date(date_t *date);
void trim(char *name);

#endif // DAYOFBIRTH_H
