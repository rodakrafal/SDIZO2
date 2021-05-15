all: run valgrind valgrindleak run_new main

run:
	clear
	g++ -o main main.cpp GraphMatrix.cpp PrimAlgorithm.cpp
	./main

valgrind:
	clear
	g++ -g -o main main.cpp GraphMatrix.cpp PrimAlgorithm.cpp -Wall
	valgrind --track-origins=yes ./main

valgrindleak:
	clear
	g++ -g -o main main.cpp GraphMatrix.cpp PrimAlgorithm.cpp -Wall
	valgrind --leak-check=full ./main