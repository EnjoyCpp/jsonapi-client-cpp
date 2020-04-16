program=Resource

Compile:
	g++ *.cpp -c -lm
CompileM:
	g++ -Wall -pedantic -g *.cpp -lm
Compose:
	g++ *.o -o $(program)	
test:Compile Compose
	./$(program)
testM:CompileM compose
	valgrind  --leak-check=full --show-leak-kinds=all ./Resource
delete:
	-rm *.o
	-rm $(program)
