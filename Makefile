all: run valgrind valgrindleak run_new main

run:
	clear
	g++ -o main main.cpp Graph.cpp PrimAlgorithm.cpp KruskalAlgorithm.cpp
	./main

valgrind:
	clear
	g++ -ggdb -o main main.cpp Graph.cpp PrimAlgorithm.cpp KruskalAlgorithm.cpp -Wall
	valgrind --track-origins=yes ./main

valgrindleak:
	clear
	g++ -ggdb -o main main.cpp Graph.cpp PrimAlgorithm.cpp KruskalAlgorithm.cpp -Wall
	valgrind --leak-check=full ./main