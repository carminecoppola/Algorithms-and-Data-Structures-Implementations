#ifndef CATENA_H
#define CATENA_H

#include <iostream>
#include<vector>

using namespace std;

/* Queste sono due strutture entry e exit che rappresentano 
i tempi di entrata e di uscita dalle catene, e un intero n 
che rappresenta il numero di stazioni di lavoro. */

struct entry{
    int a,b;
};

struct exit{
    int a,b;
};

vector<int>fastestWay(vector<vector<int>> Aij, vector<vector<int>> tempoTrasferimento, struct entry entry ,struct exit exit, int n)
{
    /*Abbiamo due vettori di interi catena1 e catena2 
      che rappresentano i tempi totali per completare
      il lavoro nelle due catene*/
    vector<int> catena1, catena2;

    /*e due vettori di interi l1 e l2 che indicano in 
    quale delle due catene è stata completata ogni stazione.*/
    vector<int> l1,l2;

    catena1.push_back(entry.a + Aij[0][0]);
    catena2.push_back(entry.b + Aij[1][0]);

    for (int j = 1; j < n; j++)
    {
        //Calcoliamo il tempo totale della prima catena
        /*Se la catena 1 ha un tempo minore la facciamo 
          avanzare e segnamo come scelta la catena 1 stessa*/
        if (catena1.at(j-1) + Aij[0][j] <= catena2.at(j-1) + Aij[0][j] +tempoTrasferimento[1][j-1])
        {
            catena1.push_back(catena1.at(j-1) + Aij[0][j]);
            l1.push_back(1);
        }
        else
        {
            catena1.push_back(catena2.at(j-1) + Aij[0][j] + tempoTrasferimento[1][j-1]);
            l1.push_back(2);
        }
        //Calcoliamo il tempo totale della seconda catena
        /*Se la catena 2 ha un tempo minore la facciamo 
          avanzare e segnamo come scelta la catena 2 stessa*/
        if (catena2.at(j-1) + Aij[1][0] <= catena1.at(j-1) + Aij[1][j] + tempoTrasferimento[0][j-1])
        {
            catena2.push_back(catena2.at(j-1) + Aij[1][j]);
            l2.push_back(1);
        }
        else
        {
            catena2.push_back(catena1.at(j-1) + Aij[1][j] + tempoTrasferimento[0][j-1]);
            l2.push_back(2);
        }  
    }

    //Stampe
    
    if(catena1.at(n-1) + exit.a <= catena2.at(n-1) + exit.b)
    {
        l1.push_back(1);
        cout<<"La prima catena è più veloce"<<endl;
        return l1;
    }
    else
    {
        l2.push_back(2);
        cout<<"La seconda catena è più veloce"<<endl;
        return l2;
    }

}

#endif