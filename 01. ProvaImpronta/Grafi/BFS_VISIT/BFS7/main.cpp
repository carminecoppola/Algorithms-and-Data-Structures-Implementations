#include"GrafoOrientato.h"
#include"Vertice.h"
#include"Nodo.h"

#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<list>
#include<limits>
#include<stack>
#include<fstream>
#include<sstream>

using namespace std;

int main()
{
    GrafoOrientato<int> grafo;

    ifstream file;
    string myFile = "GTR.txt";

    file.open(myFile);

    string line;

    int num_v = 0, num_a = 0, i = 0;
    int vertice = 0, arco = 0, vertice_sorgente = 0;

    while (getline(file,line))
    {
        stringstream lineIn(line);

        if(i == 0)
        {
            lineIn >> num_v;
            lineIn >> num_a;
            i++;
        }
        else
        {
            lineIn >> vertice;
            lineIn >> arco;

            vertice_sorgente = vertice;

            Vertice<int> *v1 = new Vertice<int>(vertice);
            Vertice<int> *v2 = new Vertice<int>(arco);

            if(grafo.searchVertice(v1) == -1)
                grafo.addNodo(v1);
            if(grafo.searchVertice(v2) == -1)
                grafo.addNodo(v2);
            grafo.addArco(grafo.getIndirizzoVertice(vertice),grafo.getIndirizzoVertice(arco));
        }
    }
    
    file.close();

    Vertice<int> *sorgente = new Vertice<int>(vertice_sorgente);

    cout<<"Grafo: "<<grafo<<endl;
    grafo.BFS(sorgente);
    cout<<"BFS: "<<grafo<<endl;

    return 0;
}