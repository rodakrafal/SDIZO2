#include "KruskalAlgorithm.h"
#include <iostream>
// #include <vector>
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
    parent = -1;
    rank = 0;
}

DSNode::~DSNode(){

}


void KruskalAlgorithm::UnionSets (Edge edge)
{
  int ru, rv;

  ru = FindSet (edge.from) ;  
  rv = FindSet (edge.to);  

  if( ru != rv )          
  {
    if( ds[ru].rank > ds[rv].rank )
        ds[rv].parent = ru;
    else
    {
        ds[ru].parent = rv;
      if( ds[ru].rank == ds[rv].rank ) ds[rv].rank++;
    }
  }
}

int KruskalAlgorithm::FindSet(int v ){

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

    // cout << "Tablica node:\n";
    ds.resize(amountVertices);
    for (int i = 0; i < amountVertices; i++){
        ds[i].parent = i ;
        ds[i].rank = 0;
        // cout << ds[i].parent << " " << ds[i].rank << endl;
    }
    // cout << "Kolejka :\n";
    priority_queue<Edge, vector<Edge>, Compare> Q;
    Edge edge;
    vector<Edge> list;
    for(int i = 0;i <amountVertices;i++){
        for (int j = 0;j<amountVertices;j++){
            if(numeric_limits<int>::max() != graph.tableMatrix[i][j]){
                edge.from = i;
                edge.to = j;
                edge.weight = graph.tableMatrix[i][j];
                Q.push(edge);
                list.push_back(edge);
                // cout << edge.from << " "<< edge.to<< " "<< edge.weight<< endl;
            }
        }
    }
    // sort(list.begin(), list.end());
    // cout << "Kruskal :\n";
    int from,to, weight = 0;
    for( int i = 0; i < amoutOfEdges; i++ ){
        do{
            edge = Q.top();     
            Q.pop();            
            // cout << edge.from << " " << edge.to<<endl;
            from = FindSet (edge.from);
            to = FindSet (edge.to);
        } while( from == to);
            // T.addEdge ( e );   
            weight += edge.weight;
            cout << "(" << edge.from << ", " << edge.to << ")   "<<edge.weight<<endl;
            UnionSets (edge);  
  }

  cout << "\nMST = " << weight << endl;
}

void KruskalAlgorithm::kruskalList(Graph &graph){
    if(graph.getVertices() <=1){
        return;
    }
    
    amountVertices = graph.getVertices();
    amoutOfEdges = graph.getVertices() - 1;

    // cout << "Tablica node:\n";
    ds.resize(amountVertices);
    for (int i = 0; i < amountVertices; i++){
        ds[i].parent = i ;
        ds[i].rank = 0;
        // cout << ds[i].parent << " " << ds[i].rank << endl;
    }
    // cout << "Kolejka :\n";
    priority_queue<Edge, vector<Edge>, Compare> Q;
    Edge edge;
    vector<Edge> list;
    Node *x;
    for(int i = 0;i <amountVertices;i++){
        for (x = graph.tableList[i]; x!=NULL; x = x->next){
                edge.from = i;
                edge.to = x->index;
                edge.weight = x->weight;
                Q.push(edge);
                list.push_back(edge);
        }
    }
    // sort(list.begin(), list.end());
    // cout << "Kruskal :\n";
    int from,to, weight = 0;
    for( int i = 0; i < amoutOfEdges; i++ ){
        do{
            edge = Q.top();     
            Q.pop();            
            // cout << edge.from << " " << edge.to<<endl;
            from = FindSet (edge.from);
            to = FindSet (edge.to);
        } while( from == to);
            // T.addEdge ( e );   
            weight += edge.weight;
            cout << "(" << edge.from << ", " << edge.to << ")   "<<edge.weight<<endl;
            UnionSets (edge);  
  }

  cout << "\nMST = " << weight << endl;
}