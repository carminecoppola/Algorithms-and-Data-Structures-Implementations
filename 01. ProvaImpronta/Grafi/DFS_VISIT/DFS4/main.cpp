#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

#include"GrafoOrientato.h"
#include"Nodo.h"
#include"Vertice.h"

using namespace std;

int main()
{
    GrafoOrientato<int> grafo;

    ifstream file;
    string myFile = "GTR.txt";
    file.open(myFile);

    string line;
    int i = 0, num_archi = 0, num_vertice = 0;
    int vertice, arco;

    while (getline(file,line))
    {
        stringstream lineIn(line);

        if(i == 0)
        {
            lineIn >> num_archi;
            lineIn >> num_vertice;
            i++;
        }
        else
        {
            lineIn >> vertice;
            lineIn >> arco;

            Vertice<int> *v1 = new Vertice<int>(vertice);
            Vertice<int> *v2 = new Vertice<int>(arco);

            if( grafo.searchVertice(v1) == -1 )
                grafo.addNodo(v1);
            if( grafo.searchVertice(v2) == -1 )
                grafo.addNodo(v2); 
            grafo.addArco(grafo.getIndirizzoVertice(vertice), grafo.getIndirizzoVertice(arco));
            
        }
    }

    file.close();

    cout<<"Grafo: "<<endl;
    cout<<grafo<<endl;
    grafo.DFS();
    cout<<"Grafo dopo DFS: "<<endl;
    cout<<grafo<<endl;


    return 0;
}