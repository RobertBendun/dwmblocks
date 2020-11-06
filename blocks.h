//Modify this file to change what commands output to your statusbar, and recompile using the make command.

bool battery(char *str);
bool date(char *str);
bool volume(char *str);
bool disk(char *str);

static const Block blocks[] = {
	// Icon, Command, Update Interval (seconds), Update Signal
	{"", &disk,    120,  0 },
	{"", &volume,    0, 10 },
	{"", &battery,  10,  0 },
	{"", &date,     60,  0 },
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;

