program=test

Compile:
	g++ *.cpp -ljsoncpp -lcurl -o test
test: Compile
	./test
