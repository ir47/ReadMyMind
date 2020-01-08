#The first target is what is run if you just type 'make'
all : readmymind
# It is nice to have a clean target. Make sure you don't delete your source files!
# If you give no dependences, then the run always runs
clean :
	rm *.o readmymind

readmymind : readmymind.o card.o linkedlist.o
	clang readmymind.o card.o linkedlist.o -o readmymind -Wall -Wextra -g


# Note we say here we need 'library.h', as we need to recompile if it changes.
# We don't need to recompile file1.o if library.c changes however.
readmymind.o : readmymind.c readmymind.h
	clang readmymind.c -c -o readmymind.o -Wall -Wextra -g

card.o : card.c readmymind.h
	clang card.c -c -o card.o -Wall -Wextra -g

linkedlist.o : linkedlist.c readmymind.h
	clang linkedlist.c -c -o linkedlist.o -Wall -Wextra -g
