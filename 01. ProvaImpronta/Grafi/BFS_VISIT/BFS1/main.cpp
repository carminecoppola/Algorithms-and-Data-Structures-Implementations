#include"Vertice.h"
#include"Nodo.h"
#include"GrafoOrientato.h"

#include<iostream>
#include<limits>
#include<stack>
#include<queue>
#include<vector>
#include<list>
#include<sstream>
#include<fstream>

int main()
{
    GrafoOrientato<int> grafo;

    ifstream file;
    string myFile = "GTR.txt";

    file.open(myFile);

    string line;

    int i = 0, num_v = 0, num_a = 0;
    int vertice, arco;
    int sorgente = 0;

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

            sorgente = vertice;

            Vertice<int> *v1 = new Vertice<int>(vertice);
            Vertice<int> *v2 = new Vertice<int>(arco);

            if(grafo.searchVertice(v1) == -1)
                grafo.addNodo(v1);
            if(grafo.searchVertice(v2) == -1)
                grafo.addNodo(v2);
            grafo.addArco(grafo.getIndirizzoVertice(vertice), grafo.getIndirizzoVertice(arco));
            
        }
    }
    
    file.close();

    Vertice<int> *vert_sorgent = new Vertice<int>(sorgente);

    cout<<"Grafo: "<< endl << grafo <<endl;
    grafo.BFS(vert_sorgent);
    cout<<"BFS: "<< endl << grafo <<endl;


    return 0;
}