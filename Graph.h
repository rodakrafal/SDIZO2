#include <iostream>

using namespace std;

class Graph
{

    private:
    int edges, vertices, first_vertice, last_vertice;      // wierzchołki, krawędzie, pierwszy/ostatni wierzchołek
    bool isDirected, created;        // czy graf jest skierowany czy nie, domyślnie nie jest
    void shuffle(int [], int n);
    void destruct();
    int ** table;
    public:

    Graph();          // konstruktory
    Graph(bool x);
    ~Graph();     // destruktory

    void createTable (int x);  // tworzenie tabeli 2D zawierającej (reprezentującej) graf nieskierowany - macierz sąsiedztwa

    int getTableValue(int x, int y);

    void setFirstVertice(int x);  // setter oraz getter dla pierwszego wierzchołka
    int getFirstVertice();

    void setLastVertice(int x);   // setter oraz getter dla ostatniego wierzchołka
    int getLastVertice();
    
    int getVertices();

    void addEdge(int x, int y, int weight);  // dodwawanie krawędzi między wierzchołkami

    void printGraphMatrix();         // wyświetlenie grafu nieskierowanego - macierz sąsiedztwa 
    void printGraphList();

    void readFromFile(string filename);            // wczytanie grafu z pliku

    void generateGraph(float x, int y);       // generowanie grafu 


    
};
