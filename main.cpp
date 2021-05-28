#include <iostream>
#include <limits>
#include "Graph.h"

#include "PrimAlgorithm.h"
#include "KruskalAlgorithm.h"
#include "DijkstraAlgorithm.h"


// #include <conio.h>
using namespace std;

void displayMenuPrim()
{
    // system("clear");
    cout << "================= ALGORYTM PRIMA =================" << endl;
	cout << "\t   1. Wczytaj z pliku" << endl;
    cout << "\t   2. Wyświetl graf macierzowo" << endl;
    cout << "\t   3. Wyświetl graf listowo" << endl;
    cout << "\t   4. Wykonaj algorytm" << endl;
    cout << "\t   5. Generowanie grafu" << endl;
	cout << "\t   0. Powrot do menu" << endl<<endl;
	cout << "Podaj opcje: ";
}

void displayMenuKruskal()
{
    // system("clear");
    cout << "================= ALGORYTM KRUSKALA =================" << endl;
	cout << "\t   1. Wczytaj z pliku" << endl;
    cout << "\t   2. Wyświetl graf macierzowo" << endl;
    cout << "\t   3. Wyświetl graf listowo" << endl;
    cout << "\t   4. Wykonaj algorytm" << endl;
    cout << "\t   5. Generowanie grafu" << endl;
	cout << "\t   0. Powrot do menu" << endl<<endl;
	cout << "Podaj opcje: ";
}

void displayMenuDijkstra()
{
    // system("clear");
    cout << "================= ALGORYTM DIJKSTRY =================" << endl;
	cout << "\t   1. Wczytaj z pliku" << endl;
    cout << "\t   2. Wyświetl graf macierzowo" << endl;
    cout << "\t   3. Wyświetl graf listowo" << endl;
    cout << "\t   4. Wykonaj algorytm" << endl;
    cout << "\t   5. Generowanie grafu" << endl;
	cout << "\t   0. Powrot do menu" << endl<<endl;
	cout << "Podaj opcje: ";
}

void displayMenuBELLMANFORD()
{
    // system("clear");
    cout << "=============== ALGORYTM BELLMANA-FORDA ===============" << endl;
	cout << "\t   1. Wczytaj z pliku" << endl;
    cout << "\t   2. Wyświetl graf macierzowo" << endl;
    cout << "\t   3. Wyświetl graf listowo" << endl;
    cout << "\t   4. Wykonaj algorytm" << endl;
    cout << "\t   5. Generowanie grafu" << endl;
	cout << "\t   0. Powrot do menu" << endl<<endl;
	cout << "Podaj opcje: ";
}

void displayMainMenu(){
    // system("clear");
    cout << "================== MENU GLOWNE ==================" << endl;
    cout << "\t   1. Algorytm Prima" << endl;
    cout << "\t   2. Algorytm Kruskala" << endl;
    cout << "\t   3. Algorytm Dijkstry" << endl;
    cout << "\t   4. Algorytm Bellmana-Forda" << endl;
    cout << "\t   0. Wyjscie" << endl<<endl;
    cout << "Podaj opcje: ";
}

void displayInfo(string info){
    // system("clear");
    cout << endl<< info;
}
void menu_prim(){
	bool quit = false;
	char option;
    string name;
    Graph graph (false, 0);
    PrimAlgorithm prim;
	do {
        displayMenuPrim();
		cin >> option;

		cout << endl;
		switch (option) {
		case '0':
			quit = true;
		 	break;
		case '1':
			displayInfo("Prosze podać nazwę pliku: ");
            cin >> name;
            graph.readFromFile(name);
            cin >> name;
			break;
        case '2':
            graph.printGraphMatrix();
            cin >> name;
            break;
        case '3':
            graph.printGraphList();
            cin >> name;
            break;
        case '4':
			if(graph.getVertices() <=1){
				displayInfo("Graf nie został utworzony.");
				break;
			}
			graph.printGraphMatrix();
			prim.primMatrix(graph);
			cout << endl<<endl;
			graph.printGraphList();
			prim.primList(graph);
			cout << endl<<endl;
			cin >> name;
            break;
		case '5':
			float x;
			int y;
			displayInfo("Prosze podac gęstość od 0.00 do 1.00: ");
			cin >> x;
			displayInfo("Prosze podać ilość wierzchołków: ");
			cin >> y;
			graph.generateGraph(x,y);

		default:
			cout << "Wybrano nieodpowiednia opcje.\n";

		}

	} while (!quit);
}

void menu_kruskal(){
	bool quit = false;
	KruskalAlgorithm krusk;
    string name;
    Graph graph (false, 0);
	char option;
	do {
        displayMenuKruskal();
		cin >> option;

		cout << endl;
		switch (option) {
		case '0':
			quit = true;
		 	break;
		case '1':
			displayInfo("Prosze podać nazwę pliku: ");
            cin >> name;
            graph.readFromFile(name);
            cin >> name;
			break;
        case '2':
            graph.printGraphMatrix();
            cin >> name;
            break;
        case '3':
            graph.printGraphList();
            cin >> name;
            break;
        case '4':
			if(graph.getVertices() <=1){
				displayInfo("Graf nie został utworzony.");
				break;
			}
			graph.printGraphMatrix();
			krusk.kruskalMatrix(graph);
			cout << endl<<endl;
			graph.printGraphList();
			krusk.kruskalList(graph);
			cout << endl<<endl;
			cin >> name;
            break;
		case '5':
			float x;
			int y;
			displayInfo("Prosze podac gęstość od 0.00 do 1.00: ");
			cin >> x;
			displayInfo("Prosze podać ilość wierzchołków: ");
			cin >> y;
			graph.generateGraph(x,y);
			break;
		default:
			cout << "Wybrano nieodpowiednia opcje.\n";

		}

	} while (!quit);
}

void menu_dijkstra(){
	bool quit = false;
	char option;
    string name;
	Graph graph (true, 1);
	DijkstraAlgorithm dijkst;
	do {
        displayMenuDijkstra();
		cin >> option;

		cout << endl;
		switch (option) {
		case '0':
			quit = true;
		 	break;
		case '1':
			displayInfo("Prosze podać nazwę pliku: ");
            cin >> name;
            graph.readFromFile(name);
            cin >> name;
			break;
        case '2':
            graph.printGraphMatrix();
            cin >> name;
            break;
        case '3':
            graph.printGraphList();
            cin >> name;
            break;
        case '4':
			if(graph.getVertices() <=1){
				displayInfo("Graf nie został utworzony.");
				break;
			}
			if(graph.checkIfNegativ()){
				cout << "Wagi w algorytmie Djiskstry nie mogą być ujemne.\n";
				break;
			}
			graph.printGraphMatrix();
			dijkst.DijkstraMatrix(graph);
			cout << endl<<endl;
			graph.printGraphList();
			dijkst.DijkstraList(graph);
			cout << endl<<endl;
			cin >> name;
            break;
		default:
			cout << "Wybrano nieodpowiednia opcje.\n";

		}

	} while (!quit);
}
void menu_bellmanford(){
	bool quit = false;
	char option;
	do {
        displayMenuBELLMANFORD();
		cin >> option;

		cout << endl;
		switch (option) {
		case '0':
			quit = true;
		 	break;
		case '1':
			
			break;
        case '2':
        
            break;
        case '3':
    
            break;
        case '4':
        
            break;
		default:
			cout << "Wybrano nieodpowiednia opcje.\n";

		}

	} while (!quit);
}

int main(int argc, char* argv[])
{
	bool quit = false;
	char option;
	do {
        displayMainMenu();
		cin >> option;

		cout << endl;
		switch (option) {
		case '0':
			quit = true;
		 	break;
		case '1':
			menu_prim();
			break;

		case '2':
			menu_kruskal();
			break;

		case '3':
			menu_dijkstra();
			break;
		case '4':
            menu_bellmanford();
            break;
		default:
			cout << "Wybrano nieodpowiednia opcje.\n";

		}

	} while (!quit);

	return 0;

}





