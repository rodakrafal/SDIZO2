#include "PrimAlgorithm.h"
#include <queue>
#include <vector>
#include <limits>


using namespace std;


PrimAlgorithm::PrimAlgorithm(int x, int y){
    this->amountVertices = x;
    this->firstVertice = y;

}

PrimAlgorithm::PrimAlgorithm(){

}

PrimAlgorithm::~PrimAlgorithm(){

}

void PrimAlgorithm::initilize(int x){}

void PrimAlgorithm::primMatrix(Graph &graph) {

    if(graph.getVertices() <=1){
        return;
    }

    firstVertice = graph.getFirstVertice();
    amountVertices = graph.getVertices();
    int weight = 0;

    MST MST_Array [amountVertices];
    for (int i = 0; i < amountVertices; i++) {
        MST_Array[i].visited = false; // wierzchołki odwiedzone
        MST_Array[i].key = numeric_limits<int>::max();  // "waga" drogi
        MST_Array[i].near = numeric_limits<int>::max();  // wierzchołki połaczone
    }
    MST_Array[firstVertice].key = 0;
    MST_Array[firstVertice].visited = true;

    typedef pair<pair<int, int>, int> pi;
    priority_queue<pi, vector<pi>, greater<pi> > pq;
    pair<pair<int, int>, int> top;
    int temp = firstVertice;
    int current = firstVertice;

    int count = amountVertices-1;
    temp = current;
    for(int i = 0; i<count;i++){
        for (int x = 0; x < amountVertices; x++){
            if(numeric_limits<int>::max() != graph.getTableValue(current, x) && !MST_Array[x].visited){
                pq.push(make_pair(make_pair(graph.getTableValue(current, x), x),current));
            }
        }

        top = pq.top();
        MST_Array[top.second].near = temp;
        temp = top.second;
        current = top.first.second;
        MST_Array[current].visited = true;
        MST_Array[current].key = top.first.first;
        weight +=  top.first.first;
        MST_Array[current].near = temp;
        cout << endl << "Przejście z " << temp << " do "<< current << " z wagą " << top.first.first<< endl;
        cout << "Przejście z " << temp << " do "<< current << " z wagą---" << graph.getTableValue(current, temp) << endl;
        pq.pop();
    }
    cout << "\nCałkowita waga MST to: " << weight << endl;
        
}

void PrimAlgorithm::primList(Graph &graph){
    
    if(graph.getVertices() <=1){
        return;
    }
    MST MST_Array [graph.getVertices()];
    for (int i = 0; i < amountVertices; i++) {
        MST_Array[i].visited = false; // wierzchołki odwiedzone
        MST_Array[i].key = numeric_limits<int>::max();  // "waga" drogi
        // MST_Array[i].near = i; // wierzchołki połaczone
    }
    priority_queue<int, vector<int>, greater<int> > pq;

}


// int main(int argc, char const *argv[])
// {


//     graph.generateGraph(0.7,5);
//     graph.printGraphMatrix();
//     graph.printGraphList();
//     PrimAlgorithm primMat (graph.getVertices(), graph.getFirstVertice());
//     primMat.primMatrix();

// }