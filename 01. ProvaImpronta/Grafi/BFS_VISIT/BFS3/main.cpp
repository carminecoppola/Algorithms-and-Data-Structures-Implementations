#include <iostream>
#include "Nodo.h"
#include "GrafoOrientato.h"
#include "Vertice.h"
#include <string>
#include <queue>

using namespace std;

int main(){

    GrafoOrientato<int> grafo;
    int valore_sorgente = 0;

    ifstream file;
    string myFile = "GTR.txt";

    file.open(myFile);

    string line;

    int i = 0, num_vertici = 0, num_archi = 0;

    int vertice = 0, arco = 0;

    while (getline(file,line))
    {
        stringstream lineIn(line);

        if(i == 0)
        {
            lineIn >> num_vertici;
            lineIn >> num_archi;
            i++;
        }

        else
        {
            lineIn >> vertice;
            lineIn >> arco;

            valore_sorgente = vertice;

            Vertice<int> *vertice1 = new Vertice<int>(vertice);
            Vertice<int> *vertice2 = new Vertice<int>(arco);

            if(grafo.searchVertice(vertice1) == -1)
                grafo.addNodo(vertice1);
            if(grafo.searchVertice(vertice2) == -1)
                grafo.addNodo(vertice2);
            grafo.addArco(grafo.getIndirizzoVertice(vertice),grafo.getIndirizzoVertice(arco));
            
        }
    }

    file.close();

    Vertice<int> *valore_sor = new Vertice<int>(valore_sorgente);

    cout<<"Grafo: "<<endl;
    cout<<grafo<<endl;
    cout<<"BFS: "<<endl;
    grafo.BFS(valore_sor);
    cout<<grafo<<endl;
    

    return 0;
}