// getenv(): lay bien environment
// putenv(): dat bien environment

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char *var, *value;
	char *str;
	var = "HOME";
	printf("%s\n", getenv(var));

	var = "HOME2";
	value = "Huong";
	str = malloc(strlen(var) + strlen(value) + 2);
	strcpy(str, var);
	strcat(str, "=");
	strcat(str, value);
	putenv(str);
	printf("%s\n", getenv(var));
	exit(0);

}