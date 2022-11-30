/*
    • Si supponga di avere una scacchiera nxn, contenente in ogni casella un numero intero, su cui si può muovere una pedina. 
      Ogni volta che la pedina passa su una casella accumula il valore contenuto nella casella.
    
    • La pedina parte dall'ultima casella in basso a destra e deve raggiungere la prima casella in alto a sinistra potendosi muovere
     solo di una casella alla volta verso l'alto, verso sinistra o in diagonale (alto-sinistra)
    
    • Si vuole calcolare un percorso che massimizzi il valore accumulato dalla pedina
*/

#include <iostream>
#include<iomanip>
#include"casella.h"
#define n 5

using namespace std;

int main(){

    //Creiamo la nostra scacchiera (matrice[n][n])
    int scacchiera[n][n] = {6, 7, 4, 7, 8,
                            7, 6, 1, 1, 4,
                            3, 5, 7, 8, 2,
                            2, 6, 7, 0, 2,
                            7, 3, 5, 6, 1 };

    //Quest'altra matrice ci servira per i valori dei percorsi
    casella scacchiera2[n][n];

    int i,j,m;    // i = indice per le righe, j = indice per le colonne , m = indice del valore massimo;

    //Inizializziamo la secodna scacchira

    for (i = 0; i < n; i++){
        for (j = 0;j < n; j++){
            scacchiera2[i][j].setValue(0);
        } 
    }
    
    //Sottoproblema della prima casella (6,in alto a sx)

    scacchiera2[0][0].setValue(scacchiera[0][0]);
    
    //Prima riga
    i = 0;
    
    for (j = 1; j < n; j++) //partiamo da 1 poichè la prima posizione gia l'abbiamo settata
    {
        scacchiera2[i][j].setValue(scacchiera2[i][j-1].getValue() + scacchiera[i][j]);
        scacchiera2[i][j].setDirection(Direction::LEFT);    //Andiamo sempre a sx
    }
    
    //Prima colonna
    j = 0;
    for (i = 1; i < n; i++)
    {
        scacchiera2[i][j].setValue(scacchiera2[i-1][j].getValue() + scacchiera[i][j]);
        scacchiera2[i][j].setDirection(Direction::UP);    //Andiamo sempre in alto
    }
    

    //Resto dei casi

    Direction d;

    for (i = 1; i < n; i++)
    {
        for (j = 1; j < n; j++)
        {
            /*Il massimo sarà il nostro elemento in diagonale 
                            | 6  7 |->13
                         13 | 7  6 |->19    */

            m = scacchiera2[i-1][j-1].getValue();
            d = Direction::DIAG;

            //Se l'elemento maggiore è quello in alto setto UP

            if (scacchiera2[i-1][j].getValue() > m)
            {
                m = scacchiera2[i-1][j].getValue();
                d = Direction::UP;
            }
            
            //Se l'elemento maggiore è quello a Sinistra setto LEFT

            if (scacchiera2[i][j-1].getValue() > m)
            {
                m = scacchiera2[i][j-1].getValue();
                d = Direction::LEFT;
            }
            
            scacchiera2[i][j].setValue(m + scacchiera[i][j]);
            scacchiera2[i][j].setDirection(d);

        }
    }
    

    //stampa matrice
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            cout<<setw(7)<<scacchiera2[i][j].getValue()<<" ("<<scacchiera2[i][j].getDirection()<<")";
        }
        cout<<endl;
    }

    //stampa percorso
    i = n-1;
    j = n-1;
    cout<< i <<" "<< j <<endl;
    while(i != 0 or j !=0){
        d = scacchiera2[i][j].getDirection();
        switch (d)
        {
        case Direction::UP:
            i--;
            break;
        case Direction::LEFT:
            j--;
            break;
        case Direction::DIAG:
            i--;
            j--;
            break;
        default:
            break;
        }
        cout<<i<< " "<<j<<endl;
    }

    return 0;
}