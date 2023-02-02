#include"Vertice.h"
#include"Nodo.h"
#include"GrafoOrientato.h"

#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;

int main(){

    GrafoOrientato<int> grafo;

    ifstream file;
    string myFile = "GTR.txt";
    string line;

    int i = 0, numNodiIniz, numArchiIniz, vertice,arco;
    
    file.open(myFile);

    while (getline(file,line))
    {
        stringstream lineIn(line);

        if(i == 0)
        {
            lineIn >> numNodiIniz;
            lineIn >> numArchiIniz;
            i++;
        }
        else
        {
            lineIn >> vertice;
            lineIn >> arco;

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

    cout<<"Grafo Iniziale: "<<endl;
    cout<<grafo<<endl;

    cout<<"DFS: "<<endl;
    grafo.DFS();
    cout<<grafo<<endl;

    ofstream fileOut;
    string fileO = "Output.txt";

    fileOut.open(fileO);

    auto u = grafo.getCoda();

    while (!u.empty())
    {
        fileOut << u.front() << endl;
        u.pop();
    }

    fileOut.close();
    

    return 0;
}