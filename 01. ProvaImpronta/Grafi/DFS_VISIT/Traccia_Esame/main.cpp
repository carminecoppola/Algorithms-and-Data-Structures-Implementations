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

    ifstream file;
    string myFile = "GTR.txt";
    ofstream output;
    string fileOut = "Output.txt";
    string line;
    int v1,v2;
    GrafoOrientato<int> grafo; 


    file.open(myFile);
    output.open(fileOut);

    int i = 0, num_v = 0, num_a = 0;

    while(getline(file,line))
    {
        stringstream lineIn(line);

        if(i == 0)
        {
            lineIn>>num_v;
            lineIn>>num_a;
            i++;
            
        }
        else
        {
            lineIn>>v1;
            lineIn>>v2;

            Vertice<int> *vertice1 = new Vertice<int> (v1);
            Vertice<int> *vertice2 = new Vertice<int> (v2);

            if(grafo.searchVertice(vertice1) == -1)
                grafo.addNodo(vertice1);
            if(grafo.searchVertice(vertice2) == -1)
                grafo.addNodo(vertice2);

            grafo.addArco(grafo.getIndirizzoVertice(v1),grafo.getIndirizzoVertice(v2));
        }
    }

    file.close();

    cout<<"Grafo prima di DFS"<<endl;
    cout<<grafo<<endl;
    cout<<"Grafo con DFS:"<<endl;
    grafo.DFS();
    cout<<grafo<<endl;

    auto u = grafo.getQueue();

    while(!u.empty())
    {
        output << u.front() << endl; 
        u.pop();
    }

    output.close();

    return 0;
}