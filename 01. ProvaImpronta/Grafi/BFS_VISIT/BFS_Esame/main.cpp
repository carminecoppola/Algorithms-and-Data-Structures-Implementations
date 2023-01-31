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

    GrafoOrientato<int> grafo; 

    ifstream file;                   //Grazie ad ifstram creiamo il file di lettura
    string myFile = "GTR.txt";
    string line;                   //Questa ci servirà per la funzione getline()
    int vert,arco,valoreSorgente;                     
    int i = 0;
    int num_v = 0;               //Mi servirà per prendere in input il numero di vertici dal file
    int num_a = 0;              //Mi servirà per prendere in input il numero di archi dal file.

    //Qui apriamo i file
    file.open(myFile);
   
    
    while(getline(file,line)) //Finche ci sono cose scritte sulla linea  
    {
        stringstream lineIn(line);  //Convertiamo line in un oggetto di tipo stringstream per poter fare operazioni

        //Prendiamo in input il numero di archi e vertici che sono sulla prima linea
        if(i == 0)
        {
            lineIn>>num_v;
            lineIn>>num_a;
            i++;
            
        }
        else
        {
            //Essendoci due valori per ogni riga del file ci segnamo il numero del vertice e dell'arco
            lineIn>>vert;
            lineIn>>arco;
            

            Vertice<int> *vertice1 = new Vertice<int> (vert);
            Vertice<int> *vertice2 = new Vertice<int> (arco);

            valoreSorgente = vert;
            //Se il nodo non esiste lo aggiungo
            if(grafo.searchVertice(vertice1) == -1) 
                grafo.addNodo(vertice1);
            if(grafo.searchVertice(vertice2) == -1) 
                grafo.addNodo(vertice2);
            
            //Indipendentemente dall'esistenza del nodo inserisco l'arco
            grafo.addArco(grafo.getIndirizzoVertice(vert),grafo.getIndirizzoVertice(arco));
        }
    }

    Vertice<int> *sorgente = grafo.getIndirizzoVertice(valoreSorgente);

    //Chiudo il file di lettura
    file.close();

    cout<<"Grafo prima di BFS"<<endl;
    cout<<grafo<<endl;    
    //Applico la BFS
    cout<<"Grafo con BFS:"<<endl;
    grafo.BFS(sorgente);
    cout<<grafo<<endl;

    //Per scrivere sul file di output
    auto u = grafo.getQueue();

    
     return 0;
}