#include "KruskalAlgorithm.h"
#include <queue>
#include <vector>
#include <limits>

using namespace std;


KruskalAlgorithm::KruskalAlgorithm(int x, int y){
    this->amountVertices = x;
    this->firstVertice = y;
}

KruskalAlgorithm::~KruskalAlgorithm(){

}

void KruskalAlgorithm::kruskalMatrix(){

}

// int main(int argc, char const *argv[])
// {
//     GraphMatrix graph(false);
//     graph.generateGraph(0.7,5);
//     graph.printGraphMatrix();

//     KruskalAlgorithm kruskal(graph.getVertices(), graph.getFirstVertice());
//     kruskal.kruskalMatrix();
//     return 0;
// }

