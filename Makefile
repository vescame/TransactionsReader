CC = gcc

main = transaction.c

target = transaction

all: $(target)

list.o: list.c
	$(CC) -std=c17 -o $@ -c $^ -g

readfile.o: readfile.c
	$(CC) -std=c17 -o $@ -c $^ -g

transaction.o: $(main)
	$(CC) -std=c17 -o $@ -c $^ -g

$(target): readfile.o list.o transaction.o
	$(CC) -std=c17 -o $@ $(main) -g

.PHONY: run clean

run: $(target)
	./$<

clean:
	@rm *.o $(target)

