#include <stdio.h>
#include <stdbool.h>


bool write_human_readable_time(char *str, double uptime)
{
	char *unit = "min";
	uptime /= 60;

	if (uptime > 60) {
		uptime /= 60;
		unit = "h";
	}

	return sprintf(str, "Uptime: %.1lf%s", uptime, unit) > 0;
}

bool uptime(char *str)
{
	FILE *f;
	double uptime;

	bool retval = (f = fopen("/proc/uptime", "r")) != NULL
		&& fscanf(f, "%lf", &uptime)
		&& write_human_readable_time(str, uptime);

	fclose(f);
	return retval;
}

