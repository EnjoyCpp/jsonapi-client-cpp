program=Resource

Compile:
	g++ -std=c++11 *.cpp -lcurl -ljsoncpp -c -lm
Compose:
	g++ -std=c++11 *.o -lcurl -ljsoncpp -o $(program)	
test:Compile Compose deletea
	./$(program)
delete:
	-rm *.o
	-rm $(program)
deletea:
	-rm *.o

