#include <iostream>

using namespace std;

class GraphMatrix
{

    private:
    int edges, vertices, first_vertice, last_vertice;      // wierzchołki, krawędzie, pierwszy/ostatni wierzchołek
    int ** table;
    public:

    GraphMatrix();          // konstruktory
    GraphMatrix(int V);
    ~GraphMatrix();     // destruktory

    void createTable (int x);  // tworzenie tabeli 2D zawierającej (reprezentującej) graf nieskierowany - macierz sąsiedztwa

    void setFirstVertice(int x);  // setter oraz getter dla pierwszego wierzchołka
    int getFirstVertice();

    void setLastVertice(int x);   // setter oraz getter dla ostatniego wierzchołka
    int getLastVertice();

    void addEdge(int x, int y, int weight);  // dodwawanie krawędzi między wierzchołkami
    void printGraphMatrix();         // wyświetlenie grafu nieskierowanego - macierz sąsiedztwa 
    void readFromFile(string filename);            // wczytanie grafu z pliku

    void generateGraph(float x, int y);       // generowanie grafu 


    
};
