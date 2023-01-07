#include<iostream>
#include<vector>
#include<map>
#include"Casella.h"
#define S 5

using namespace std;

int main(){

    //Creiamo la matrice
    Casella matrix[5][6];
    int i = 0, j= 0; // i-> indice di colonna, j->indice di riga

    vector<int> w = {0, 2, 3, 4, 5}; //Peso dell'oggetto
    vector<int> v = {0, 3, 4, 5, 6}; //Valore dell'oggetto

    /*Ogni cella della riga (sacco) dobbiamo dire se l'elemento c'è o non c'è nel sacco con la map
      l'elemento di indice 1 non c'è nel sacco ... 
      Fa riferimento ai singoli elementi (i) della tabella dei pesi e dei valori
      quindi stiamo dicendo che lo zaino nella casella 0 non ha elementi dentro. */

    //Inizializziamo la prima riga
    for ( j = 0; j < 6; j++)
    {
        matrix[0][j].setValue(0);
        for (int k = 1; k < v.size(); k++)
            matrix[0][j].setMap(k,0);
    }

    //Inizializziamo la prima colonna

    for ( i = 0; i < 5; i++)
    {
        matrix[i][0].setValue(0);
        for (int k = 1; k < v.size(); k++)
            matrix[i][0].setMap(k,0);
        
    }
    
    for (i = 1; i < v.size(); i++)
    {
        for(j = 1; j <= S; j++)
        {
            if (w[i] > j)
            {
                matrix[i][j].setValue(matrix[i-1][j].getValue());

                for (int k = 1; k < v.size(); k++)
                {
                    matrix[i][j].setMap(k, matrix[i-1][j].getMap(k));
                }
            }
            else if(matrix[i-1][j].getValue() > matrix[i-1][j - w[i]].getValue() + v[i])
            {
                matrix[i][j].setValue(matrix[i-1][j].getValue());

                for (int k = 1; k < v.size(); k++)
                {
                    matrix[i][j].setMap(k,matrix[i-1][j].getMap(k));
                }  
            }
            else
            {
                matrix[i][j].setValue(matrix[i-1][j - w[i]].getValue() + v[i]);
                for(int k = 1; k < v.size(); k++)
                {
                    matrix[i][j].setMap(k, matrix[i-1][j - w[i]].getMap(k));
                }
                matrix[i][j].setMap(i,1);
            }
            
        }
    }
    
    //Stampa della matrice
    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 6; j++)
            cout<<matrix[i][j].getValue()<<" ";
        cout<<endl;
    }

    cout<<endl;
    //Stampa della mappa zaino (come sta lavorando)
    for(int k = 1; k < v.size(); k++){
        cout<< k <<" ";
        cout<<matrix[4][5].getMap(k)<<endl;
    }
    


    return 0;
}