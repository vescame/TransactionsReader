CC = gcc

main = transaction.c

target = transaction

all: $(target)

list.o: list.c
	$(CC) -o $@ -c $^

readfile.o: readfile.c
	$(CC) -o $@ -c $^

$(target): readfile.o list.o
	$(CC) -o $@ $(main)

.PHONY: run clean

run: $(target)
	./$<

clean:
	@rm *.o $(target)

