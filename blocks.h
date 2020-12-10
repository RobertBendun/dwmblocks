//Modify this file to change what commands output to your statusbar, and recompile using the make command.

bool battery(char *str);
bool date(char *str);
bool disk(char *str);
bool sunrise(char *str);
bool uptime(char *str);
bool volume(char *str);

double Latitude = 52.409538;
double Longitude = 16.931992;

static const Block blocks[] = {
	// Icon, Command, Update Interval (seconds), Update Signal
	{"", &sunrise, 1 * 60 * 60, 0 },
	{"", &uptime,  120,  0 },
	{"", &disk,    120,  0 },
	{"", &volume,    0, 10 },
	{"", &battery,  10,  0 },
	{"", &date,     60,  0 },
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
