#include <iostream>
#include "Graph.h"

using namespace std;


class KruskalAlgorithm
{
    private:
    int amountVertices, firstVertice;
    public:
    KruskalAlgorithm();
    KruskalAlgorithm(int x, int y);
    ~KruskalAlgorithm();
    
    void setAmountVertices(int x); // setter dla ilości krawędzi
    int getAmountVertices();   // getter dla ilości krawędzi
    void setFirstVertice(int x);
    int getFirstVertice(); // getter dla pierwszego wierzchołka

    void kruskalMatrix();
    void kruskalist();
};