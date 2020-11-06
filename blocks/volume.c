#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define Muted "🔇 "
#define High "🔊 "
#define Low "🔈 "
#define Mid "🔉 "

bool volume(char *str)
{
	unsigned volume;
	FILE *p;
	
	if ((p = popen("pamixer --get-volume-human", "r")) == NULL)
		return false;
	
	char buffer[sizeof("muted")]; 
	fscanf(p, "%5s", buffer);
	
	if (buffer[0] == 'm')
		strcat(str, Muted);
	else {
		sscanf(buffer, "%u", &volume);
		if (volume > 70) strcat(str, High); 
		else if (volume < 35) strcat(str, Low);
		else strcat(str, Mid);
	}

	strcat(str, buffer);
	return pclose(p) != -1;
}

