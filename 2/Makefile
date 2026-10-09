CC=g++
CFLAGS=-m64 -std=c++23
DD=dist

all:
	mkdir -p $(DD)
	$(CC) $(CFLAGS) bucket_sort.cpp test.cpp -o $(DD)/test
	$(CC) $(CFLAGS) bucket_sort.cpp benchmark.cpp -o $(DD)/benchmark
