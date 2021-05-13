#include <iostream>

using namespace std;

class GraphMatrixDirected
{

    private:
    int edges, vertices, first_vertice, last_vertice;      //wierzchołki, krawędzie
    int ** table;
    public:

    GraphMatrixDirected();
    GraphMatrixDirected(int V);
    ~GraphMatrixDirected();

    void createTable ();

    void setFirstVertice(int x);  //setter oraz getter dla pierwszego wierzchołka
    int getFirstVertice();

    void setLastVertice(int x);   //setter oraz getter dla ostatniego wierzchołka
    int getLastVertice();

    void addEdge(int x, int y, int weight);  // dodwawanie krawędzi między wierzchołkami
    void printGraphMatrix();         // wyświetlenie grafu nieskierowanego - macierz sąsiedztwa 
    void readFromFile(string filename);            // wczytanie grafu z pliku


    
};
