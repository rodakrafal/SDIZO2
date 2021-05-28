all: run valgrind valgrindleak run_new main

run:
	clear
	g++ -o main main.cpp Graph.cpp PrimAlgorithm.cpp KruskalAlgorithm.cpp DijkstraAlgorithm.cpp BellmanFordAlgorithm.cpp
	./main

valgrind:
	clear
	g++ -ggdb -o main main.cpp Graph.cpp PrimAlgorithm.cpp KruskalAlgorithm.cpp DijkstraAlgorithm.cpp BellmanFordAlgorithm.cpp -Wall
	valgrind --track-origins=yes ./main

valgrindleak:
	clear
	g++ -ggdb -o main main.cpp Graph.cpp PrimAlgorithm.cpp KruskalAlgorithm.cpp DijkstraAlgorithm.cpp BellmanFordAlgorithm.cpp -Wall
	valgrind --leak-check=full ./main