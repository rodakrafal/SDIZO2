#include <iostream>

using namespace std;


struct MST {
    bool visited;
    int key;
    int near;
};

class PrimAlgorithm
{
    private:
    int amountVertices, firstVertice;
    
    public:
    PrimAlgorithm();
    PrimAlgorithm(int x, int y);
    ~PrimAlgorithm();

    void initilize(MST MSTarr []);
    void prim(MST MSTarr []);

    void primMatrix();
    void primList();
};