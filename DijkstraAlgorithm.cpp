#include "DijkstraAlgorithm.h"
#include <iostream>
#include <limits>
#include <queue>

using namespace std;

DijkstraAlgorithm::DijkstraAlgorithm(){}

DijkstraAlgorithm::~DijkstraAlgorithm(){}

void DijkstraAlgorithm::DijkstraMatrix(Graph & graph){
   
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
    priority_queue<pair<int, int>,  vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[firstVertice] = 0;
    parent[firstVertice] = firstVertice;
    pq.push(make_pair(0, firstVertice));
    while(!pq.empty()){

        int currentNode = pq.top().second;
        int currentDist = pq.top().first;
        pq.pop();

        for (int z = 0;z<amountVertices;z++){
            if(graph.tableMatrix[currentNode][z] != numeric_limits<int>::max()){
                int y = (currentDist + graph.tableMatrix[currentNode][z]);
                if (y < dist[z]) {
                    dist[z] = currentDist + graph.tableMatrix[currentNode][z];
                    parent[z] = currentNode;
                    pq.push(std::make_pair(dist[z], z));
                }
            }
        }
    }
    
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

void DijkstraAlgorithm::DijkstraList(Graph & graph){
    
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
    priority_queue<pair<int, int>,  vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[firstVertice] = 0;
    parent[firstVertice] = firstVertice;
    pq.push(make_pair(0, firstVertice));
    Node *x;
    while(!pq.empty()){
    
        int currentNode = pq.top().second;
        int currentDist = pq.top().first;
        pq.pop();

        for (x = graph.tableList[currentNode]; x!=NULL; x = x->next) {
            /// minimizing distances
            int y = (currentDist + x->weight);
            if (y < dist[x->index]) {
                dist[x->index] = currentDist + x->weight;
                parent[x->index] = currentNode;
                pq.push(std::make_pair(dist[x->index], x->index));
            }
        }
    }
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
