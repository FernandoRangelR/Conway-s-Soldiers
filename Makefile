CFLAGS = -Wall -Wextra -Werror -Wfloat-equal -pedantic -ansi -O2

sold: sold.c test.c
	$(CC) sold.c test.c -o sold $(CFLAGS)

run: sold
	./sold

.PHONY: clean run
