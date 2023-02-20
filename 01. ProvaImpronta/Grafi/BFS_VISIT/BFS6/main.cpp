#include"GrafoOrientato.h"
#include"Vertice.h"
#include"Nodo.h"

#include<iostream>
#include<stack>
#include<string>
#include<queue>
#include<vector>
#include<list>
#include<limits>
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

    int i = 0, num_v = 0, num_a = 0;
    int vertice_sorgente ,vertice , arco;

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

    cout<<"Grafo: "<<endl<<grafo<<endl;
    cout<<"BFS: "<<endl;
    grafo.BFS(sorgente);
    cout<<grafo<<endl;

    return 0;
}