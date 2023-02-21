#include <iostream>
#include "Nodo.h"
#include "GrafoOrientato.h"
#include "Vertice.h"
#include <string>
#include <queue>
#include<fstream>
#include<sstream>

using namespace std;

int main(){

    GrafoOrientato<int> grafo;

    ifstream file;
    string myFile = "GTR.txt";
    file.open(myFile);

    string line;
    int i = 0, num_archi = 0, num_vertice = 0;
    int vertice, arco ,valoreSorgente;

    while (getline(file,line))
    {
        stringstream lineIn(line);

        if(i == 0)
        {
            lineIn >> num_vertice;
            lineIn >> num_archi;
            i++;
        }
        else
        {
            lineIn >> vertice;
            lineIn >> arco;

            Vertice<int> *vert1 = new Vertice<int>(vertice);
            Vertice<int> *vert2 = new Vertice<int>(arco);

            valoreSorgente = vertice;

            if(grafo.searchVertice(vert1) == -1)
                grafo.addNodo(vert1);
            if(grafo.searchVertice(vert2) == -1)
                grafo.addNodo(vert2);
            grafo.addArco(grafo.getIndirizzoVertice(vertice),grafo.getIndirizzoVertice(arco));
        }
    }
    

    file.close();
    
    cout<<"Grafo:"<<endl;
    cout<<grafo<<endl;
    cout<<"Grafo dopo BFS:"<<endl;
    grafo.BFS(grafo.getIndirizzoVertice(valoreSorgente));
    cout<<grafo<<endl;

    return 0;
}