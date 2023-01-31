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

    int i,num_vertici,num_archi,vertice,arco;

    file.open(myFile);

    while(getline(file,line))
    {
        stringstream lineIn(line);

        if(i == 0){
            lineIn >> num_vertici;
            lineIn >> num_archi;
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
            
            grafo.addArco(grafo.getInizizzoVertice(vertice),grafo.getInizizzoVertice(arco));
        }

    }

    file.close();

    cout<<"Grafo prima di DFS"<<endl;
    cout<<grafo<<endl;    
    //Applico la DFS
    cout<<"Grafo con DFS:"<<endl;
    grafo.DFS();
    cout<<grafo<<endl;

    //Creo il file di output
    ofstream output;
    string fileOut = "Output.txt";

    output.open(fileOut);

    auto u = grafo.getCoda();

    while(!u.empty())
    {
        output << u.front() << endl; 
        u.pop();
    }

    output.close();

    return 0;
}