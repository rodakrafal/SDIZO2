#include "PrimAlgorithm.h"
#include <iostream>
#include <queue>
#include <vector>
#include <limits>

using namespace std;

PrimAlgorithm::PrimAlgorithm(){

}

PrimAlgorithm::~PrimAlgorithm(){

}

void PrimAlgorithm::primMatrix(Graph &graph) {

    amountVertices = graph.getVertices();
    if(amountVertices <=1){
        return;
    }

    firstVertice = graph.getFirstVertice();
    int weight = 0;
    bool * MST_Array = new bool [amountVertices];
    for (int i = 0; i<amountVertices;i++){
        MST_Array[i]=false;
    }
    MST_Array[firstVertice]= true;

    priority_queue<Edge, vector<Edge>, Compare> Q;
    int temp = firstVertice;
    int current = firstVertice;

    int count = amountVertices-1;
    temp = current;
    for(int i = 0; i<count;i++){
        Edge edge;
        for (int x = 0; x < amountVertices; x++){
            if(numeric_limits<int>::max() != graph.getTableValue(current, x) && !MST_Array[x]){
                edge.from = current;
                edge.to = x;
                edge.weight = graph.getTableValue(current, x);
                Q.push(edge);
            }
        }
        MST_Array[current] = true;
        edge = Q.top();
                
        temp = edge.from;
        current = edge.to;
        weight +=  edge.weight;
        cout << "(" << temp << ", "<< current << ")   " << edge.weight<< endl;
        Q.pop();
    }
    cout << "\nMST = " << weight << endl;
    delete [ ]MST_Array;
        
}

void PrimAlgorithm::primList(Graph &graph){
 
    amountVertices = graph.getVertices();
    if(amountVertices <=1){
        return;
    }

    firstVertice = graph.getFirstVertice();
    int weight = 0;
    bool * MST_Array = new bool [amountVertices];
    for (int i = 0; i<amountVertices;i++){
        MST_Array[i]=false;
    }
    MST_Array[firstVertice]= true;

    priority_queue<Edge, vector<Edge>, Compare> Q;
    int temp = firstVertice;
    int current = firstVertice;

    int count = amountVertices-1;
    temp = current;
    for(int i = 0; i<count;i++){
        Edge edge;
        Node *x;
        for (x = graph.tableList[current]; x!=NULL; x = x->next){
            if(!MST_Array[x->index]){
                edge.from = current;
                edge.to = x->index;
                edge.weight = x->weight;
                Q.push(edge);
            }
        }
        MST_Array[current] = true;
        edge = Q.top();
                
        temp = edge.from;
        current = edge.to;
        weight +=  edge.weight;
        cout << "(" << temp << ", "<< current << ")   " << edge.weight<< endl;
        Q.pop();
    }
    cout << "\nMST = " << weight << endl;
    delete [] MST_Array;
}
