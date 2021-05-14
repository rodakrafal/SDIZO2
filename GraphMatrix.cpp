#include "GraphMatrix.h"
#include <cstdlib>
#include <ctime>
#include <limits>
#include <fstream>

using namespace std;

GraphMatrix::GraphMatrix(){

}

GraphMatrix::GraphMatrix(bool x){
    this->isDirected = x;
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
    // table[y][x] = weight;
    if(!isDirected){
        table[y][x] = weight;
    }
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
                cout << " " << "\t";
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
    bool isBool = true;
    int first, second, amount;
    vertices = amountOfVertices;
    // sprawdzenie czy jest minimalna liczba połaczeń miedzy wierzchołkami
    if(amountOfEdges<amountOfVertices-1){
        amountOfEdges = amountOfVertices-1;
        isBool = false;
    }
    edges = amountOfEdges;
    cout << amountOfEdges << " - ilosc krawędzi"<<endl; 
    createTable(vertices);
    
    srand(time(0));
    // tworzenie tablicy z wierzchołkami
    int tab [vertices];
    for (int i = 0; i<vertices ;i++){
        tab [i] = i;
    }
    // wyymieszanie elementów tablicy zawierajacej wierzchołki
    shuffle(tab,vertices);

    bool ** tabEdge = new bool * [vertices];
    for (int i = 0; i <vertices; ++i){
        tabEdge[i] = new bool [vertices];
    }
    for (int i = 0; i<vertices; i++){
        for (int j =0; j<vertices;j++){
            if(i ==j)tabEdge[i][j] = true;
            tabEdge[i][j] = false;
        }
    }

    // zrobienie połaczeń miedzy wierzchołkami
    for(int i = 0; i < vertices;i++){
        if(i+1==vertices){
            break;
        }
        addEdge(tab[i+1], tab[i], i+1);
        tabEdge[i+1][i] = true;
        // tabEdge[i][i+1] = true;
        
        if(!isDirected){
            tabEdge[i][i+1] = true;
        }
        
    }
    // dodanie dodatkowych połaczeń jeżeli takowe mają się zanaleść 
    if(isBool){
        int temp;
        temp = amountOfEdges - vertices +1; 
        cout << temp << " - ilosc krawedzie które trzeba jeszcze doddać"<< endl<< endl;
        amount = 9;
        for (int i = 0; i<temp;i++){
            first = rand()%vertices;
            second = rand()%vertices;
            while(first==second){
                second = rand()%vertices;
            }
            while(tabEdge[first][second]==true){
                first = rand()%vertices;
                second = rand()%vertices;
            }
            // amount = rand()%10;
            addEdge(first,second,amount++);
            tabEdge[first][second] = true;
            // tabEdge[second][first] = true;
            if(!isDirected){
                tabEdge[second][first] = true;
            }
        }
    }

    for (int i = 0; i<vertices; i++){
       delete [] tabEdge [i];
    }
    delete [] tabEdge;
}

void GraphMatrix::shuffle (int arr[], int lenght){
    int temp;
    int randomIndex;
    for (int i = 0; i < lenght; i++){
        randomIndex = rand()%lenght;
        temp = arr[i];
        arr [i] = arr[randomIndex];
        arr[randomIndex] = temp;
    }
}

int main(int argc, char const *argv[])
{
    cout << "Początek \n"<<endl;
    GraphMatrix graph(true);
    graph.generateGraph(0.25,22);
    graph.printGraphMatrix();

    return 0;
}

