all: test test1
test1: test1.c
	gcc test1.c maopao.c -o test
test:
	gcc test.c lianbiao1.c -o test
clean:
	test
