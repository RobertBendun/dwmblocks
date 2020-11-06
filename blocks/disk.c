#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <sys/statvfs.h>

void write_human_readable_size(unsigned long space, char *str)
{
	char const *units[] = { "", "kB", "MB", "GB", "TB" };
	unsigned i = 0;
	for (; space > 1024 && i < sizeof(units) / sizeof(*units); ++i) {
		space = (space + 1023) / 1024;
	}

	sprintf(str, "%lu%s", space, units[i]);
}

bool disk(char *str)
{
	strcat(str, "🏠 ");
	struct statvfs stat;
	if (statvfs("/", &stat) != 0)
		return false;

	unsigned long total = stat.f_blocks * stat.f_frsize;
	unsigned long avail = total - stat.f_bsize * stat.f_bavail;

	write_human_readable_size(avail, str + strlen(str));
	strcat(str, " / ");
	write_human_readable_size(total, str + strlen(str));
	return true;
}

