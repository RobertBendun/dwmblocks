#include <stdio.h>
#include <stdbool.h>

bool packages(char *str)
{
	FILE *p;
	if ((p = popen("sh -c 'pacman -Qu | grep -Fcv \"[ignored]\"'", "r")) == NULL)
		return false;
	
	unsigned long packages = 0;
	fscanf(p, "%lu", &packages);
	sprintf(str, "📦 %lu\n", packages);
	return pclose(p) != -1;
}

int main()
{
	char buffer[1024];
	packages(buffer);
	printf("%s\n", buffer);
}
