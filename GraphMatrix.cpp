#include "GraphMatrix.h"
#include <cstdlib>
#include <ctime>
#include <limits>
#include <fstream>

using namespace std;

GraphMatrix::GraphMatrix(){ // konstuktor bez argumentowy
    this->isDirected = false;
    this->vertices = 0;
    this->created = true;
}

GraphMatrix::GraphMatrix(bool x){ // konstuktor z argumentem decydującym czy graf jest skierowany czy nie
    this->isDirected = x;
    this->vertices = 0;
    this->created = true;
    this->edges = 0;
}

GraphMatrix::~GraphMatrix(){ // destruktor
    if(vertices>=1){
    destruct();
    }
}

void GraphMatrix::createTable(int V){ // tworzenie tablicy dwu wymiarowej zawierajacej połączenia między wierzchołkami 
    if(V <= 1){
        cout << "Podano za małą ilość krawędzi do stworzenia tablicy dwuwymiarowej."<<endl;
        return;
    }
    table = new int * [V];
    for (int i = 0; i <V; ++i){
        table[i] = new int [V];
    }
    for (int i = 0; i<V; i++){
        for (int j =0; j<V;j++){
            table[i][j] = numeric_limits<int>::max();       // tablica początkowo wypełniana jest nieskończonością - nawjwiększą wartością dla tego typu
        }
    }
}
int GraphMatrix::getTableValue(int x, int y){
    return table[x][y];
}

void GraphMatrix::destruct(){ // "wnętrze" destruktora
    for (int i = 0; i<vertices; i++){
       delete [] table [i];
    }
    delete [] table;
}

void GraphMatrix::setFirstVertice(int x){ //ustawianie wartości "pierwszego" wierzchołka
    this->first_vertice =x;
}

int GraphMatrix::getFirstVertice(){ // getter dla "pierwszego" wierzchołka
    return first_vertice;
}

void GraphMatrix::setLastVertice(int x){ //ustawianie wartości "ostatniego" wierzchołka
    this->last_vertice = x;
}

int GraphMatrix::getLastVertice(){ // getter dla "ostatniego" wierzchołka
    return last_vertice;
}

int GraphMatrix::getVertices(){ // getter dla ilości wierzchołków
    return vertices;
}

void GraphMatrix::addEdge(int x, int y, int weight){   // dodawanie połączeń między wierzchołkami
    table[x][y] = weight;   // dla grafu skierowanego
    // table[y][x] = weight;
    if(!isDirected){    //dla grafu nieskierowanego
        table[y][x] = weight;
    }
}

void GraphMatrix::printGraphMatrix(){ // funckja wyświetlająca graficzną reprezentacje grafu
    if(vertices <= 1){
        cout<<"Nie odpowiednia ilosć wierzchołków." << endl;
        return;
    }
    cout << "  ";
    for (int i = 0; i<vertices; i++){
        cout << i <<"\t";
    }
    cout << endl;
    for (int i = 0; i<vertices;i++){
        cout << i << " ";
        for (int j = 0; j<vertices; j++){
            if(table[i][j] == numeric_limits<int>::max()){   // dla wartości największej - reprezentującej nieskończoność wypisywana jest "--" dla przejrzystości 
                if(i == j) cout << "--\t";
                else cout << " " << "\t";
            }else {
                cout << table[i][j] << "\t";
            }
        }
        cout << endl;
    }
}

void GraphMatrix::readFromFile(string filename){ // wczytywanie grafu z pliku
    if(vertices >1 && created && edges>0){
        destruct();
    }
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
        cout << first_vertice << endl;
        file >> last_vertice;
        	if (last_vertice < 0) {
			cout << "Podana w pliku ostatni wierzchołek jest nieodpowiedni" << endl;
			return;
		}
        cout << endl;
		if (file.fail())
			cout << "File error - READ SIZE" << endl;
		else {
            cout << "Graf o " << vertices<< " krawędziach, wczytany z pliku."<< endl<<endl;
            for (int x = 0; x<edges;x++)
            {
                file >> first;
                if(first >= vertices){
                    cout << "Błedna wartość pierwszego wierzchołka " << endl;
                    return;
                }
                file >> last;
                 if(last >= vertices){
                    cout << "Błędna wartość drugiego wierzchołka" << endl;
                    break;
                }
                file >>w;
                addEdge(first,last,w);
                // cout << first << " " << last << " " << w  << endl;
            }
		}
		file.close();
	}
	else
		cout << "File error - OPEN" << endl;
}

void GraphMatrix::generateGraph(float density, int amountOfVertices){

    if(amountOfVertices >1 && created && edges>0){
        destruct();
    }
    if(amountOfVertices <= 1){
        cout<<"Podano za małą ilość wierzchołków." << endl;
        return;
    }
    vertices = amountOfVertices; // ustawienie podanej ilości wierzchołków
    int amountOfEdges;
    if(!isDirected){
    amountOfEdges = (density * amountOfVertices * (amountOfVertices-1))/2;
    } else amountOfEdges = (density * amountOfVertices * (amountOfVertices-1));
    bool isBool = true;
    int first, second, amount;
    // sprawdzenie czy jest minimalna liczba połaczeń miedzy wierzchołkami
    if(amountOfEdges<amountOfVertices-1){
        amountOfEdges = amountOfVertices-1;
        isBool = false;
    }
    edges = amountOfEdges;  // ustawienie odpowiedniej ilości połączeń
    cout << "\nDla gęstości wynoszącej " << density*100 << "% ilość krawędzi wynosi: " << amountOfEdges << ", podana ilość wierzchołków to: "<< vertices<<endl;
    createTable(vertices); // tworzenie tablicy dwuwymiarowej dla zadanej ilości wierzchołków
    
    //ustawiamy teraz pierwszego wierzchołek - domyślnie będzie to wierzchołek o indeksie 0  "ostatni" wierzchołek - domyslnie jest to n wierzchołek
    first_vertice = 0;
    last_vertice = vertices -1;
    srand(time(0)); 
    // tworzenie tablicy z wierzchołkami
    int tab [vertices];
    for (int i = 0; i<vertices ;i++){
        tab [i] = i;
    }
    // wyymieszanie elementów tablicy zawierajacej wierzchołki - losowa kolejność
    shuffle(tab,vertices);
    
    // tworzenie boolowskiej tablicy zawierającej krawędzie, dla krawędzi której nie chcemy powtarzać dajemy true
    bool ** tabEdge = new bool * [vertices];
    for (int i = 0; i <vertices; ++i){
        tabEdge[i] = new bool [vertices];
    }
    for (int i = 0; i<vertices; i++){
        for (int j =0; j<vertices;j++){
            if(i ==j)tabEdge[i][j] = true;
            else tabEdge[i][j] = false; // false jeżeli krawędź nie została "połączona"
        }
    }
    // zrobienie połaczeń miedzy wierzchołkami - "minimalne", takie łączenie stosowane w celu wystąpienia przynajmniej jedeneg połaczęnia miedzy wierzchołkami
    for(int i = 0; i < vertices;i++){
        if(i+1==vertices){
            break;
        } 
        addEdge(tab[i+1], tab[i], rand()%vertices);
        tabEdge[tab[i+1]][tab[i]] = true; // ustawiamy połaczenia na true, w celu "poinfomowania" że krawędź została juz wykorzystana/połaczona
        
        if(!isDirected){ // w przypadku grafu nieskierowanego
            tabEdge[tab[i]][tab[i+1]] = true;
        }
        
    }
    // dodanie dodatkowych połaczeń jeżeli takowe mają się znaleść - wynika to ze wzoru na gęstość 
    if(isBool){
        int temp;
        temp = amountOfEdges - vertices +1; 
        cout << "Dla zadanej wyżej gęstości dodane zostanie "<<temp << " krawędzi, pozostała ilość potrzebna była w celu utworzenienia minimalnej ilości połączeń. "<< endl<< endl;
        // amount = vertices-1;
        for (int i = 0; i<temp;i++){
            do{  // sprawdzamy czy dana krawędż została juz stworzona, gdyby była losujemy nowe wartośći
                first = rand()%vertices;
                second = rand()%vertices;
            }while(isDirected ? tabEdge[first][second] : (tabEdge[first][second] || tabEdge[second][first]));
            addEdge(first,second,rand()%vertices);
            tabEdge[first][second] = true;
            if(!isDirected){
                tabEdge[second][first] = true;
            }
        }
    } else cout << endl;

    for (int i = 0; i<vertices; i++){
       delete [] tabEdge [i];
    }
    delete [] tabEdge;
}

void GraphMatrix::shuffle (int arr[], int lenght){ // funckja służąca do losowego ustawienia wartości w tablicy
    int temp;
    int randomIndex;
    for (int i = 0; i < lenght; i++){
        randomIndex = rand()%lenght;
        temp = arr[i];
        arr [i] = arr[randomIndex];
        arr[randomIndex] = temp;
    }
}