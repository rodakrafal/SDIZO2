all: run valgrind valgrindleak run_new main

run:
	clear
	g++ -o main main.cpp GraphMatrix.cpp
	./main

valgrind:
	clear
	g++ -g -o main main.cpp -Wall
	valgrind --track-origins=yes ./main

valgrindleak:
	clear
	g++ -g -o main main.cpp -Wall
	valgrind --leak-check=full ./main