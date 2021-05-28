#include "Graph.h"

class DijkstraAlgorithm
{
    private:
    int amountVertices,amoutEdges, firstVertice;
    public:
    
    DijkstraAlgorithm();
    ~DijkstraAlgorithm();

    void DijkstraMatrix(Graph &graph);
    void DijkstraList(Graph &graph);
};