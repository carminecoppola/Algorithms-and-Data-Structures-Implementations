#include"Vertice.h"
#include"Nodo.h"
#include"GrafoOrientato.h"

#include<iostream>
#include<queue>
#include<list>
#include<limits>
#include<string>
#include<sstream>
#include<fstream>

using namespace std;

int main()
{
    GrafoOrientato<int> grafo;

    ifstream file;
    string myFile = "GTR.txt";
    string line;

    int i = 0, num_archi = 0 , num_vertici = 0;
    int vert,arco;

    file.open(myFile);

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
            lineIn >> vert;
            lineIn >> arco;

            Vertice<int> *vertice1 = new Vertice<int>(vert);
            Vertice<int> *vertice2 = new Vertice<int>(arco);

            if(grafo.searchVertice(vertice1) == -1)
                grafo.addNodo(vertice1);
            if(grafo.searchVertice(vertice2) == -1)
                grafo.addNodo(vertice2);
            grafo.addArco(grafo.getIndirizzoVertice(vert),grafo.getIndirizzoVertice(arco));

        }
    }
    
    file.close();

    cout<<"Grafo: "<<endl;
    cout<< grafo <<endl;
    cout<<"DFS: "<<endl;
    grafo.DFS();
    cout<< grafo <<endl;

    return 0;
}