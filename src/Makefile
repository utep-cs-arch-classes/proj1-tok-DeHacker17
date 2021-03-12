main: input.o tokenizer.o history.o
	gcc -o tokenizer input.o tokenizer.o history.o

input.o: input.c tokenizer.h
	gcc -c input.c

tokenizer.o: tokenizer.c tokenizer.h
	gcc -c tokenizer.c

history.o: history.c history.h
	gcc -c history.c

clean:
	rm -f *.o *~ *# tokenizer
