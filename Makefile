program4.out: program4_driver.o adventurer.o utils.o
	g++ -g -std=c++17 program4_driver.o adventurer.o utils.o -o program4.out

utils.o: src/utils.cpp include/adventurer.h
	g++ -g -std=c++17 -I./include -c  src/utils.cpp

adventurer.o: src/adventurer.cpp include/adventurer.h
	g++ -g -std=c++17 -I./include -c  src/adventurer.cpp

program4_driver.o: src/program4_driver.cpp include/adventurer.h
	g++ -g -std=c++17 -I./include -c  src/program4_driver.cpp

run:
	./program4.out

valrun:
	valgrind ./program4.out

clean:
	rm *.o
