hello:
	echo "hello world"


main: book.o bookDatabase.o user.o userDatabase.o main.o
	g++ -o main book.o bookDatabase.o user.o userDatabase.o main.o

book.o: book.h book.cpp
	g++ -c book.cpp

bookDatabase.o: book.h bookDatabase.h bookDatabase.cpp
	g++ -c bookDatabase.cpp

user.o: user.h user.cpp
	g++ -c user.cpp

userDatabase.o: user.h userDatabase.h userDatabase.cpp
	g++ -c userDatabase.cpp

main.o: book.h bookDatabase.h user.h userDatabase.h main.cpp
	g++ -c main.cpp


#shaper: shape.o rect.o main.o
#	g++ -o shaper shape.o rect.o main.o

.PHONY: clean
clean:
	rm -f user.o
	rm -f userDatabase.o
	rm -f main.o
	rm -i main 