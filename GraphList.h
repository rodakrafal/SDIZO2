#include <iostream>

using namespace std;
struct Node{
    int val, cost;
    Node* next;
};
struct Edge{
    int fvertice, lvertice, weight;
};
class GraphList
{

    private:
    int edges, vertices, first_vertice, last_vertice;      //wierzchołki, krawędzie
    Edge edges[];
    public:

    GraphList();
    GraphList(int V);
    ~GraphList();

    void createTable ();

    void setFirstVertice(int x);  //setter oraz getter dla pierwszego wierzchołka
    int getFirstVertice();

    void setLastVertice(int x);   //setter oraz getter dla ostatniego wierzchołka
    int getLastVertice();

    void addEdge(int x, int y, int weight);  // dodwawanie krawędzi między wierzchołkami
    void printGraphMatrix();         // wyświetlenie grafu nieskierowanego - macierz sąsiedztwa 
    void readFromFile(string filename);            // wczytanie grafu z pliku


    
};
