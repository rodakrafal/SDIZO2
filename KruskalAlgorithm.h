#include "Graph.h"
#include <vector>

class DSNode{
    public:
    int parent, rank;
    DSNode();
    ~DSNode();
};

class KruskalAlgorithm
{
    private:
    int amountVertices, amoutOfEdges;
    public:
    std::vector<DSNode> ds;

    KruskalAlgorithm();
    ~KruskalAlgorithm();

    int find(int v);
    void union_op(int x,int y);

    void kruskalMatrix(Graph &graph);
    void kruskalList(Graph &graph);

    int FindSet (int v);
    void UnionSets (Edge e);
};