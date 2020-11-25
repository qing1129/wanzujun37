all: test test1
test1: test1.c
	gcc test1.c -o test
test:
	gcc test.c -o test
clean:
	test
