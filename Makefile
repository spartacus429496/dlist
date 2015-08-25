target:test_dlist.o
	gcc -o target test_dlist.o
test_dlist.o:test_dlist.c dlist.h
	gcc -c test_dlist.c -o test_dlist.o
.PHONY:clean
clean:
	rm  -rf *.o target
