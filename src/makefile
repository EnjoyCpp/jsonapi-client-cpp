program=Resource

Compile:
	g++ *.cpp -lcurl -ljsoncpp -c -lm
Compose:
	g++ *.o -lcurl -ljsoncpp -o $(program)	
test:Compile Compose deletea
	./$(program)
delete:
	-rm *.o
	-rm $(program)
deletea:
	-rm *.o

