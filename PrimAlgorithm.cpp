#include "PrimAlgorithm.h"
#include "Graph.h"
#include <queue>
#include <vector>
#include <limits>


using namespace std;

Graph graph(false);
typedef pair<int, int> pi;

PrimAlgorithm::PrimAlgorithm(int x, int y){
    this->amountVertices = x;
    this->firstVertice = y;

}

PrimAlgorithm::~PrimAlgorithm(){

}

void PrimAlgorithm::initilize(MST MST_Array []) {
        for (int i = 0; i < amountVertices; i++) {
        MST_Array[i].visited = false; // wierzchołki odwiedzone
        MST_Array[i].key = numeric_limits<int>::max();  // "waga" drogi
        // MST_Array[i].near = i; // wierzchołki połaczone
    }
}

void PrimAlgorithm::prim(MST MST_Array []) {
    
    priority_queue<pi, vector<pi>, greater<pi> > pq;
    pair<int, int> top;
    int weight = 0;

    MST_Array[firstVertice].key = 0;
    MST_Array[firstVertice].visited = true;
    int temp = firstVertice;
    int current = firstVertice;
    for(int j = 0; j < amountVertices; j++){
        if(numeric_limits<int>::max() != graph.getTableValue(current, j) && MST_Array[j].visited == false){
            pq.push(make_pair(graph.getTableValue(current, j), j));
        }
    }
    top = pq.top();
    current = top.second;
    MST_Array[current].visited = true;
    MST_Array[current].key = top.first;
    weight += top.first;
    MST_Array[current].near = temp;
    cout << endl << "Przejście z " << temp << " do "<< current << " z wagą " << top.first<< endl;
    cout << "Przejście z " << temp << " do "<< current << " z wagą---" << graph.getTableValue(current, temp) << endl;

    pq.pop();
    int count = amountVertices-2;
    temp = current;
    while(count){
        
        for (int x = 0; x < amountVertices; x++){
            if(numeric_limits<int>::max() != graph.getTableValue(current, x) && !MST_Array[x].visited){
                pq.push(make_pair(graph.getTableValue(current, x), x));
            }
        }
        top = pq.top();

        current = top.second;
        if(MST_Array[current].visited != true){
        MST_Array[current].visited = true;
        MST_Array[current].key = top.first;
        weight += top.first;
        MST_Array[current].near = temp;
        cout << endl << "Przejście z " << temp << " do "<< current << " z wagą " << top.first<< endl;
        cout << "Przejście z " << temp << " do "<< current << " z wagą---" << graph.getTableValue(current, temp) << endl;
        pq.pop();
        temp = current;
        }
        count--;
    }
    cout << "\nCałkowita waga MST to: " << weight << endl;

}

void PrimAlgorithm::primMatrix(){
    MST tab [graph.getVertices()];
    initilize(tab);
    prim(tab);
}

int main(int argc, char const *argv[])
{
    graph.generateGraph(0.7,5);
    graph.printGraphMatrix();
    graph.printGraphList();
    PrimAlgorithm primMat (graph.getVertices(), graph.getFirstVertice());
    primMat.primMatrix();

}