#include <stdio.h>
#include <time.h>
#include <stdbool.h>

bool date(char *str)
{
	struct tm *tm;
	time_t t = time(NULL);
	tm = localtime(&t);
	return strftime(str, 50, "%d/%m %H:%M", tm) != 0;
}

