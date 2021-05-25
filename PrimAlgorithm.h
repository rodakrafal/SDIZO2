#include <iostream>
#include "Graph.h"
using namespace std;


// struct MST {
//     bool visited;
//     int key;
//     int near;
// };

class PrimAlgorithm
{
    private:
    int amountVertices, firstVertice;
    public:
    PrimAlgorithm();
    PrimAlgorithm(int x, int y);
    ~PrimAlgorithm();

    // void prim(MST arr []);

    void primAlg(bool x, Graph graph);
    void primMatrix(Graph &graph);
    void primList(Graph &graph);
};