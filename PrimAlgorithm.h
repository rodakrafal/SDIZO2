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

class PrimAlgorithm
{
    private:
    int amountVertices, firstVertice;
    MST MST_Array;
    public:
    PrimAlgorithm();
    PrimAlgorithm(int x, int y);
    ~PrimAlgorithm();
    void setAmountVertices(int x); // setter dla ilości krawędzi
    int getAmountVertices();   // getter dla ilości krawędzi
    void setFirstVertice(int x);
    int getFirstVertice(); // getter dla pierwszego wierzchołka

    void initilize(MST MSTarr []);
    void prim(MST MSTarr []);

    void primMatrix();
    void primList();
};