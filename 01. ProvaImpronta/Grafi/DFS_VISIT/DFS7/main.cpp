#include<iostream>
#include<string>
#include<sstream>
#include<fstream>

#include"Vertice.h"
#include"Nodo.h"
#include"GrafoOrientato.h"

using namespace std;

int main(){

    GrafoOrientato<int> grafo;

    ifstream file;
    string myFile = "GTR.txt";
    string line;

    file.open(myFile);

    int i, num_vert = 0, num_archi = 0;
    int vert, arco;

    while (getline(file,line))
    {
        stringstream lineIn(line);

        if(i == 0)
        {
            lineIn >> num_vert;
            lineIn >> num_archi;
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

    // ofstream fileOut;
    // string file2 = "Output.txt";

    // fileOut.open(file2);

    cout<<"Grafo: "<<endl;
    cout<<grafo<<endl;
    grafo.DFS();
    cout<<"Grafo dopo DFS: "<<endl;
    cout<<grafo<<endl;

    //fileOut.close();

    return 0;
}