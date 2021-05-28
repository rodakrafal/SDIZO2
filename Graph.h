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

class Compare2
{
public:
    bool operator() (Edge e1, Edge e2)
    {
        return e1.weight < e2.weight;
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
    bool isDirected, created, wrong;        // czy graf jest skierowany czy nie, domyślnie nie jest
    int which; // wartosc 1 - algorytm djikstry, 2 - bellmana-forda
    void shuffle(int [], int n);
    void destruct();
    public:
    int ** tableMatrix;
    Node ** tableList;

    Graph(bool x, int y);
    ~Graph();     // destruktory

    void createTable (int x);  // tworzenie tabeli 2D zawierającej (reprezentującej) graf nieskierowany - macierz sąsiedztwa

    int getTableValue(int x, int y);
    int getListValue(int x, int y);

    void setFirstVertice(int x);  // setter oraz getter dla pierwszego wierzchołka
    int getFirstVertice();

    void setLastVertice(int x);   // setter oraz getter dla ostatniego wierzchołka
    int getLastVertice();
    
    int getVertices();      // getter dla liczby wierzchołków

    int getEdges();      // getter dla liczby krawędzi

    bool checkIfNegativ();  // getter sprawdzenia wartości ujemnych

    void addEdge(int x, int y, int weight);  // dodwawanie krawędzi między wierzchołkami

    void printGraphMatrix();         // wyświetlenie grafu - macierz sąsiedztwa 
    void printGraphList();           // wyświetlenie grafu - lista sąsiadów 

    void toList();

    void readFromFile(std::string filename);            // wczytanie grafu z pliku

    void generateGraph(float x, int y);       // generowanie grafu 



};
#endif