CC=g++
FLAGS=-std=c++20 -Wall -pedantic
TEST_LIBS=-lgtest_main -lgtest -lpthread

.PHONY: test clean

all: test_bin

string_view.o: string_view.cpp
	$(CC) $(FLAGS) string_view.cpp -c

test_bin: string_view.o test.cpp
	$(CC) $(FLAGS) string_view.o test.cpp  -o test_bin $(TEST_LIBS)

test:
	./test_bin

int_test:
	python3 int_test.py

wrapper:
	$(CC) $(FLAGS) string_view.o test.cpp  -o wrapper $(TEST_LIBS)

main:
	./wrapper

clean:
	rm -f *.o main
