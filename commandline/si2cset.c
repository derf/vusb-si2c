#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "si2c-util.h"

int main(int argc, char **argv)
{
	int i;

	i2c_init();
	i2c_start();

	if (argc < 3) {
		fputs("Usage: si2cset <address> <data ...>", stderr);
		return 1;
	}

	for (i = 1; i < argc; i++) {
		i2c_tx_byte(atoi(argv[i]));
	}

	i2c_stop();
	i2c_deinit();

	return 0;
}
