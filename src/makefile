program=Resource

Compile:
	g++ *.cpp -c -lm
CompileM:
	g++ -Wall -pedantic -g *.cpp -lm
Compose:
	g++ *.o -o $(program)	
test:Compile Compose deletea
	./$(program)
testM:CompileM compose deletea 
	valgrind  --leak-check=full --show-leak-kinds=all ./Resource
delete:
	-rm *.o
	-rm $(program)
deletea:
	-rm *.o

