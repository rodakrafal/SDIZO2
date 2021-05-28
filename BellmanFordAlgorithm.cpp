#include "BellmanFordAlgorithm.h"
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

BellmanFordAlgorithm::BellmanFordAlgorithm(){}

BellmanFordAlgorithm::~BellmanFordAlgorithm(){};

void BellmanFordAlgorithm::BellmanFordMatrix(Graph & graph){

    amountVertices = graph.getVertices();
    if(amountVertices <=1){
        return;
    }

    firstVertice = graph.getFirstVertice();
    amoutEdges = graph.getEdges();
    vector <int> dist;
    vector<int> parent;
    dist.resize(amountVertices);
    parent.resize(amountVertices);
    for (int i =0;i<amountVertices;i++){
        dist[i] = numeric_limits<int>::max();
        parent[i] = -1;
    }
    dist[firstVertice] = 0;
    parent[firstVertice] = firstVertice;

    for (int y = 0; y<amountVertices-1; y++){
        bool isCorrected = false;
        for (int i = 0; i< amountVertices; i++){
            for (int j = 0; j < amountVertices;j++){
                if(graph.tableMatrix[i][j] != numeric_limits<int>::max()){
                    int temp =graph.tableMatrix[i][j]; 
                    if(dist[i] == numeric_limits<int>::max()){
                        temp = numeric_limits<int>::max();
                    } else {
                        temp += dist[i];
                    }
                    if( temp < dist[j]){
                        dist[j] = temp;
                        parent[j] = i;
                        isCorrected = true;
                    }
                }
            }
        }
        if(!isCorrected){
            break;
        }
    }
    

    for (int i = 0; i< amountVertices; i++){
        for (int j = 0; j < amountVertices;j++){
            if(graph.tableMatrix[i][j] != numeric_limits<int>::max()){
                int temp =graph.tableMatrix[i][j]; 
                if(dist[i] == numeric_limits<int>::max()){
                    temp = numeric_limits<int>::max();
                } else {
                    temp += dist[i];
                }
                if( temp < dist[j]){
                    cout << "Wystąpił cykl ujemny.\n";
                    return;
                }
            }
        }
    }

    // for (int j = 0; j < amoutEdges;j++){
    //     if((dist[edge[j].from] + edge[j].weight < dist[edge[j].to])){
    //         cout << "Graf zawiera negatywny cykl."<< endl;
    //         return;
    //     }
    // }

    for(int i = 0; i<amountVertices;i++){
        cout << i << " | " << dist[i] << " |";
        int temp = i;
        if(i == firstVertice){
            cout << " " << firstVertice;
        }
        while(temp != firstVertice){
            cout << " "<< parent[temp];
            temp = parent[temp];
        }
        cout << endl;
    }

}

void BellmanFordAlgorithm::BellmanFordList(Graph &graph){

    amountVertices = graph.getVertices();
    if(amountVertices <=1){
        return;
    }

    firstVertice = graph.getFirstVertice();
    amoutEdges = graph.getEdges();
    vector <int> dist;
    vector<int> parent;
    dist.resize(amountVertices);
    parent.resize(amountVertices);
    for (int i =0;i<amountVertices;i++){
        dist[i] = numeric_limits<int>::max();
        parent[i] = -1;
    }
    dist[firstVertice] = 0;
    parent[firstVertice] = firstVertice;
    Node *x;

    for(int y = 0; y<amountVertices-1;y++){
        bool isCorrected = false;
        for (int i = 0; i< amountVertices; i++){
            for (x = graph.tableList[i]; x!=NULL; x = x->next){

                int temp = x->weight; 
                if(dist[i] == numeric_limits<int>::max()){
                    temp = numeric_limits<int>::max();
                } 
                else {
                    temp += dist[i];
                }
                if( temp < dist[x->index]){
                    dist[x->index] = temp;
                    parent[x->index] = i;
                    isCorrected = true;
                }
            }
        }
        if(!isCorrected){
            break;
        }
    }

 for (int i = 0; i< amountVertices; i++){
            for (x = graph.tableList[i]; x!=NULL; x = x->next){
                if((dist[i] + graph.tableMatrix[i][x->index]) < dist[x->index]){
                    cout << "Wystąpił cykl ujemny.\n";
                    return;
                }
            }
        }
    // for (int j = 0; j < amoutEdges;j++){
    //     if((dist[edge[j].from] + edge[j].weight < dist[edge[j].to])){
    //         cout << "Graf zawiera negatywny cykl."<< endl;
    //         return;
    //     }
    // }

    for(int i = 0; i<amountVertices;i++){
        cout << i << " | " << dist[i] << " |";
        int temp = i;
        if(i == firstVertice){
            cout << " " << firstVertice;
        }
        while(temp != firstVertice){
            cout << " "<< parent[temp];
            temp = parent[temp];
        }
        cout << endl;
    }
}