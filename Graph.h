#ifndef GRAPH_H
#define GRAPH_H
#include <string>
#include <vector>

class Edge{
public:
    int weight;
    int from;
    int to;
};

class Compare
{
public:
    bool operator() (Edge e1, Edge e2)
    {
        return e1.weight > e2.weight;
    }
};

class Node{
public:
    int index;
    int weight;
    Node *next;
    Node();
};


class Graph
{

    private:
    int edges, vertices, first_vertice, last_vertice;      // wierzchołki, krawędzie, pierwszy/ostatni wierzchołek
    bool isDirected, created;        // czy graf jest skierowany czy nie, domyślnie nie jest
    void shuffle(int [], int n);
    void destruct();
    public:
    int ** tableMatrix;
    Node ** tableList;

    Graph();          // konstruktory
    Graph(bool x);
    ~Graph();     // destruktory

    void createTable (int x);  // tworzenie tabeli 2D zawierającej (reprezentującej) graf nieskierowany - macierz sąsiedztwa

    int getTableValue(int x, int y);
    int getListValue(int x, int y);


    void setFirstVertice(int x);  // setter oraz getter dla pierwszego wierzchołka
    int getFirstVertice();

    void setLastVertice(int x);   // setter oraz getter dla ostatniego wierzchołka
    int getLastVertice();
    
    int getVertices();      // getter dla liczby wierzchołków

    void addEdge(int x, int y, int weight);  // dodwawanie krawędzi między wierzchołkami

    void printGraphMatrix();         // wyświetlenie grafu - macierz sąsiedztwa 
    void printGraphList();           // wyświetlenie grafu - lista sąsiadów 

    void toList();

    void readFromFile(std::string filename);            // wczytanie grafu z pliku

    void generateGraph(float x, int y);       // generowanie grafu 



};
#endif