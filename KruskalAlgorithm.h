#include "Graph.h"

class DSNode{
    public:
    int parent, rank;
    DSNode();
    ~DSNode();
    void MakeSet ( int v );
    int FindSet ( int v );
    void UnionSets ( Edge e );
};

class DSStruct
{
    private:
    public:
    DSStruct ( int n );
    ~DSStruct( );
};

struct TNode
{
  TNode * next;
  int v, weight;
};


class KruskalAlgorithm
{
    private:
    int amountVertices;
    int amoutOfEdges;
    public:
    vector<DSNode> ds;

    KruskalAlgorithm();
    ~KruskalAlgorithm();

    int find(int v);
    void union_op(int x,int y);

    void kruskalMatrix(Graph &graph);
    void kruskalList(Graph &graph);
};