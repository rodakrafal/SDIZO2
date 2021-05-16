#include <iostream>
#include "GraphMatrix.h"

using namespace std;


struct MST {
    bool visited;
    int key;
    int near;
};

struct Edges{
    int first;
    int second;
    int weight;
};

class KruskalAlgorithm
{
    private:
    int amountVertices, firstVertice;
    MST MST_Array;
    public:
    KruskalAlgorithm();
    KruskalAlgorithm(int x, int y);
    ~KruskalAlgorithm();
    
    void setAmountVertices(int x); // setter dla ilości krawędzi
    int getAmountVertices();   // getter dla ilości krawędzi
    void setFirstVertice(int x);
    int getFirstVertice(); // getter dla pierwszego wierzchołka

    void initilize(MST MSTarr []);
    void prim(MST MSTarr []);

    void kruskalMatrix();
    void kruskalist();
};