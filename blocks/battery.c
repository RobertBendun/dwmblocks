#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define Capacity "/sys/class/power_supply/BATx/capacity"
#define Status "/sys/class/power_supply/BATx/status"
#define Cell_Size sizeof("___ 100%")

static bool read_from(char const* filename, char const* format, void *p)
{
	FILE *f;
	if ((f = fopen(filename, "r")) == NULL)
		return false;
	
	bool ret = fscanf(f, format, p) == 1;
	fclose(f);
	return ret;
}

bool battery(char *str)
{
	unsigned i, capacity;
	// status may contain: Discharging, Full and Charging
	// all options differ by first letter so we can simplify and parse only it
	char status, *stat, *cap;
	char capacity_path[] = Capacity;
	char status_path[] = Status;

	cap = strchr(capacity_path, 'x');
	stat = cap - capacity_path + status_path;

	for (i = 0u; i < 9u; ++i) {
		*stat = *cap = '0' + (char)i;	
		if (!read_from(capacity_path, "%u", &capacity) || !read_from(status_path, "%c", &status)) 
			break;
		
		char buffer[Cell_Size] = {};
		switch (status) {
			case 'D': sprintf(buffer, "%s %u%%", capacity > 30 ? "🔋" : "🛑", capacity); break;
			case 'F': sprintf(buffer, "⚡ %u%%", capacity); break;
			default:  sprintf(buffer, "🔌 %u%%", capacity); break;
		}
		strncat(str, buffer, Cell_Size);
	}

	return i != 0;
}

