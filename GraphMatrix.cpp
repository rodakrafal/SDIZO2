#include "GraphMatrix.h"
#include <cstdlib>
#include <ctime>
#include <limits>
#include <fstream>

using namespace std;

GraphMatrix::GraphMatrix(){

}

GraphMatrix::GraphMatrix(int V){
    this->vertices = V;
}

void GraphMatrix::createTable(int V){
    table = new int * [V];
    for (int i = 0; i <V; ++i){
        table[i] = new int [V];
    }
    for (int i = 0; i<V; i++){
        for (int j =0; j<V;j++){
            table[i][j] = numeric_limits<int>::max();
        }
    }
}

GraphMatrix::~GraphMatrix(){
    for (int i = 0; i<vertices; i++){
       delete [] table [i];
    }
    delete [] table;
}

void GraphMatrix::setFirstVertice(int x){
    this->first_vertice =x;
}

int GraphMatrix::getFirstVertice(){
    return first_vertice;
}

void GraphMatrix::setLastVertice(int x){
    this->last_vertice = x;
}

int GraphMatrix::getLastVertice(){
    return last_vertice;
}

void GraphMatrix::addEdge(int x, int y, int weight){   // dodwanie połaczeń
    table[x][y] = weight;
    table[y][x] = weight;
}

void GraphMatrix::printGraphMatrix(){
    cout << "  ";
    for (int i = 0; i<vertices; i++){
        cout << i <<"\t";
    }
    cout << endl;
    for (int i = 0; i<vertices;i++){
        cout << i << " ";
        for (int j = 0; j<vertices; j++){
            if(table[i][j] == numeric_limits<int>::max()){
                cout << "inf" << "\t";
            }else {
                cout << table[i][j] << "\t";
            }
        }
        cout << endl;
    }
}

void GraphMatrix::readFromFile(string filename){
    ifstream file;
	file.open(filename);
	int first,last,w;
	if (file.is_open())
	{
		file >> edges;
		if (edges < 0) {
			cout << "Podana w pliku ilość krawędzi jest nieodpowiednia" << endl;
			return;
		}
        file >> vertices;
		if (vertices <= 0) {
			cout << "Podana w pliku ilość wierzchołków jest nieodpowiednia" << endl;
			return;
		}
        createTable(vertices);

        file >> first_vertice;
        	if (first_vertice < 0) {
			cout << "Podana w pliku pierwszy wierzchołek jest nieodpowiedni" << endl;
			return;
		}
        file >> last_vertice;
        	if (last_vertice < 0) {
			cout << "Podana w pliku ostatni wierzchołek jest nieodpowiedni" << endl;
			return;
		}
		if (file.fail())
			cout << "File error - READ SIZE" << endl;
		else {
            for (int x = 0; x<edges;x++)
            {
                file >> first;
                if(first >= vertices){
                    cout << "Błedna wartość pierwszego wierzchołka " << endl;
                    return;
                }
                file >> last;
                 if(first >= vertices){
                    cout << "Błędna wartość drugiego wierzchołka" << endl;
                    break;
                }
                file >>w;
                addEdge(first,last,w);
                cout << first << " " << last << " " << w  << endl;
            }
		}
		file.close();
	}
	else
		cout << "File error - OPEN" << endl;
}

void GraphMatrix::generateGraph(float density, int amountOfVertices){

    int amountOfEdges = (density * amountOfVertices * (amountOfVertices-1))/2;
    bool isCorret = true;
    int first, second, amount;
    vertices = amountOfVertices;

    if(amountOfEdges<amountOfVertices-1){
        amountOfEdges = amountOfVertices-1;
        isCorret = false;
    }
    edges = amountOfEdges;
    cout << amountOfEdges <<endl; 
    createTable(vertices);
    
    bool ** temp = new bool * [vertices];
    for (int i = 0; i <vertices; ++i){
        temp[i] = new bool [vertices];
    }
    for (int i = 0; i<vertices; i++){
        for (int j =0; j<vertices;j++){
            if(i==j)temp[i][j] = true;
            else temp[i][j] = false;
        }
    }

    srand(time(0));
    for (int i = 0; i<edges; i++){
        first = rand()%amountOfVertices;
        second = rand()%amountOfVertices;
        while (first == second){
            second = rand()%amountOfVertices;
        }
        if(temp[first][second]==true){
            cout << "juz to mamy"<<endl;
        }
        amount = rand()%10;
        addEdge(first,second,rand()%10);
        temp[first][second]=true;
        temp[second][first]=true;
    }
}


int main(int argc, char const *argv[])
{
    cout << "Początek \n"<<endl;
    GraphMatrix graph;
    graph.generateGraph(0.99, 4);
    graph.printGraphMatrix();

    return 0;
}

