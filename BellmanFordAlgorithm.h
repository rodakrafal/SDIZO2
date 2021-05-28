#include "Graph.h"

class BellmanFordAlgorithm
{
    private:
    int amountVertices,amoutEdges, firstVertice;
    int *d, *p;
    bool *QS;
    public:
    
    BellmanFordAlgorithm();
    ~BellmanFordAlgorithm();

    void BellmanFordMatrix(Graph &graph);
    void BellmanFordList(Graph &graph);
};