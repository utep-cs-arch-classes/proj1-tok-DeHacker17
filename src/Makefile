main: input.o tokenizer.o
	gcc -o tokenizer input.o tokenizer.o

input.o: input.c tokenizer.h
	gcc -c input.c

tokenizer.o: tokenizer.c tokenizer.h
	gcc -c tokenizer.c

clean:
	rm -f *.o *~ *# tokenizer
