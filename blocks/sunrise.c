#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "../_cgo_export.h"

extern double Latitude, Longitude;

bool sunrise(char *buffer)
{
	char *txt = GetSunriseSunset(Latitude, Longitude);
	if (txt) {
		strncpy(buffer, txt, 50);
		free(txt);
	}
	return txt != NULL;
}
