#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "si2c-util.h"

int main(int argc, char **argv)
{
	char line[8];
	short int number;

	si2c_init();
	si2c_start();
	puts("ready");

	while (fgets(line, 8, stdin) != NULL) {
		if (sscanf(line, "%hi\n", &number) == 1) {
			if ((number >= 0) && (number <= 255)) {
				puts("tx");
				si2c_tx_byte(number);
			}
		}
		if (strcmp(line, "push\n") == 0) {
			puts("sig");
			si2c_stop();
		}
	}

	si2c_stop();
	si2c_deinit();
	return 0;
}
