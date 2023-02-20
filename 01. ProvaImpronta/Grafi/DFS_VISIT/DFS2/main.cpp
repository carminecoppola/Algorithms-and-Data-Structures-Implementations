#include"Vertice.h"
#include"Nodo.h"
#include"GrafoOrientato.h"

#include<iostream>
#include<list>
#include<vector>
#include<stack>
#include<queue>
#include<string>
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

    int i = 0,num_v = 0, num_a = 0;
    int vertice = 0, arco = 0;

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

    cout<<"Grafo: "<<endl<<grafo<<endl;
    grafo.DFS();
    cout<<"DFS: "<<endl<<grafo<<endl;
}