#include "KruskalAlgorithm.h"
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

    vector<DSNode> ds;
    vector<Edge> mst;

KruskalAlgorithm::KruskalAlgorithm(){

}

KruskalAlgorithm::~KruskalAlgorithm(){

}

DSNode::DSNode(){

}

DSNode::~DSNode(){

}

void DSNode::UnionSets (Edge edge)
{
  int ru, rv;

  ru = FindSet (edge.from) ;   // Wyznaczamy korzeń drzewa z węzłem u
  rv = FindSet (edge.to);   // Wyznaczamy korzeń drzewa z węzłem v

  if( ru != rv )           // Korzenie muszą być różne
  {
    if( ds[ru].rank > ds[rv].rank ) // Porównujemy rangi drzew
        ds[rv].parent = ru;
    //   Z [ rv ].up = ru;    // ru większe, dołączamy rv
    else
    {
        ds[ru].parent = rv;
    //   Z [ ru ].up = rv;    // równe lub rv większe, dołączamy ru
      if( ds[ru].rank == ds[rv].rank ) ds[rv].rank++;
    }
  }
}

int DSNode::FindSet(int v ){

    if(ds[v].parent == v) return v;
    else {
        ds[v].parent = FindSet (ds[v].parent);
        return ds[v].parent;
    }
}

void KruskalAlgorithm::kruskalMatrix(Graph &graph){

    if(graph.getVertices() <=1){
        return;
    }
    
    amountVertices = graph.getVertices();
    amoutOfEdges = graph.getVertices() - 1;

    ds.resize(amountVertices);
    for (int i = 0; i < amountVertices; i++){
        ds[i].parent = i ;
        ds[i].rank = 0;
    }

    priority_queue<Edge, vector<Edge>, Compare> Q;
    Edge edge;
    for(int i = 0;i <amountVertices;i++){
        for (int j = 0;j<i;j++){
            if(numeric_limits<int>::max() != graph.tableMatrix[i][j]){
                edge.from = i;
                edge.from = j;
                edge.weight = graph.tableMatrix[i][j];
                Q.push(edge);
                cout << i << " "<< j<< " "<< edge.weight<< endl;
            }
        }
    }
    int x,y;
    for( int i = 0; i < amountVertices-1; i++ ){
        do{
            edge = Q.top();      // Pobieramy z kolejki krawędź
            Q.pop();            // Krawędź usuwamy z kolejki
        } while( ds[0].FindSet(edge.from) == ds[0].FindSet (edge.to));
            // T.addEdge ( e );       // Dodajemy krawędź do drzewa
            cout << edge.from << " "<<edge.to<<" "<<edge.weight<<endl;
            ds.at(i).UnionSets (edge);     // Zbiory z wierzchołkami łączymy ze sobą
  }
}

void KruskalAlgorithm::kruskalList(Graph &graph){

}
