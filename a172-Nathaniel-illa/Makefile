all: clean test
programtest: tests.cpp 
	g++ -fsanitize=address --std=c++11 tests.cpp -o programtest 
test: programtest 
	./programtest
clean:
	rm -f programtest a.out a.exe