#include "Graph.h"

using namespace std;


class PrimAlgorithm
{
    private:
    int amountVertices, firstVertice;
    public:
    PrimAlgorithm();
    ~PrimAlgorithm();

    void primMatrix(Graph &graph);
    void primList(Graph &graph);
};