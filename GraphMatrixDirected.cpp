#include "GraphMatrixDirected.h"
#include <limits>
#include <fstream>

using namespace std;

GraphMatrixDirected::GraphMatrixDirected(){

}

GraphMatrixDirected::GraphMatrixDirected(int V){
    this->vertices = V;
}

void GraphMatrixDirected::createTable(){
    table = new int * [vertices];
    for (int i = 0; i <vertices; ++i){
        table[i] = new int [vertices];
    }
    for (int i = 0; i<vertices; i++){
        for (int j =0; j<vertices;j++){
            table[i][j] = numeric_limits<int>::max();
        }
    }
}

GraphMatrixDirected::~GraphMatrixDirected(){
    for (int i = 0; i<vertices; i++){
       delete [] table [i];
    }
    delete [] table;
}

void GraphMatrixDirected::setFirstVertice(int x){
    this->first_vertice =x;
}

int GraphMatrixDirected::getFirstVertice(){
    return first_vertice;
}

void GraphMatrixDirected::setLastVertice(int x){
    this->last_vertice = x;
}

int GraphMatrixDirected::getLastVertice(){
    return last_vertice;
}

void GraphMatrixDirected::addEdge(int x, int y, int weight){   // dodwanie połaczeń
    table[x][y] = weight;
}

void GraphMatrixDirected::printGraphMatrix(){
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

void GraphMatrixDirected::readFromFile(string filename){
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
        createTable();

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


int main(int argc, char const *argv[])
{
    cout << "Początek \n"<<endl;
    GraphMatrixDirected graph (5);
    graph.readFromFile("test");
    graph.printGraphMatrix();

    return 0;
}

