program=test

Compile:
	g++ *.cpp -ljsoncpp -lcurl -o test
CompileM:
	g++ -Wall -pedantic -g *.cpp -ljsoncpp -lcurl -o test
test: Compile
	./test
testM: CompileM
	valgrind  --leak-check=full --show-leak-kinds=all ./test
