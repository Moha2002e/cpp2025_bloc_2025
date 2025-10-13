
CC = g++
CFLAGS = -std=c++17 -Wall -Wextra -g -I.

CLASS_SRCS = classes/Model.cpp classes/Option.cpp classes/Car.cpp

all: Test1 Test2a Test2b Test2c

Test1: Test1.cpp $(CLASS_SRCS)
	$(CC) $(CFLAGS) -o Test1 Test1.cpp $(CLASS_SRCS)

Test2a: Test2a.cpp $(CLASS_SRCS)
	$(CC) $(CFLAGS) -o Test2a Test2a.cpp $(CLASS_SRCS)

Test2b: Test2b.cpp $(CLASS_SRCS)
	$(CC) $(CFLAGS) -o Test2b Test2b.cpp $(CLASS_SRCS)

Test2c: Test2c.cpp $(CLASS_SRCS)
	$(CC) $(CFLAGS) -o Test2c Test2c.cpp $(CLASS_SRCS)

Test3: Test3.cpp $(CLASS_SRCS)
	$(CC) $(CFLAGS) -o Test3 Test3.cpp $(CLASS_SRCS)

clean:
	rm -f Test1 Test2a Test2b Test2c
