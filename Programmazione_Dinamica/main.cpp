//Distanza di editing

#include<iostream>
#include<iomanip>
#include<string.h>
#include<iomanip>
#include"casella.h"

using namespace std;

int delta(char Si,char Tj){

    return(Si == Tj)?0:1;   //Operatore terziario
}

int main(){

    casella matrix[8][7];
    int i = 0;
    int j = 0;

    string S = "ATCTGAT";
    string T = "TGCATA";

    matrix[0][0].setValue(0);
    

    //prima riga
    
    i = 0;
    for (j = 1; j < 7; j++){

        matrix[i][j].setValue(j);
        matrix[i][j].setDir(Direction::LEFT);
    }

    //prima colonna
    j = 0;

    for (i = 1; i < 8; i++){

        matrix[i][j].setValue(i);
        matrix[i][j].setDir(Direction::UP);
    }
    
    //Tutti i calcoli
    for (i = 1; i < 8; i++)
    {
        for (j = 1; j < 7; j++)
        {
            int a = delta(S[i-1],T[j-1])+ matrix[i-1][j-1].getValue() ;
            int b = 1 + matrix[i-1][j].getValue();
            int c = 1 + matrix[i][j-1].getValue();

            int m = a;
            Direction d = Direction::DIAG;

            if (b < m){
                m = b;
                d = Direction::UP; 
            }
            if (c < m){
                m = c;
                d = Direction::LEFT; 
            }

            matrix[i][j].setValue(m);
            matrix[i][j].setDir(d);
        }
    }
    
    //Stampa

    for (i = 0; i < 8; i++){
        for (j = 0; j < 7; j++){

            cout << matrix[i][j].getValue() << " (" << matrix[i][j].getDir() << ") " ;
        }
        cout << endl;
    }
    
    i = 7; j = 6;
    

    while (i!= 0 || j!= 0)
    {
        
       switch (matrix[i][j].getDir())
       {
            case Direction::UP:
                i--;
                cout << "[Cancellazione]"<<endl;
            break;
            case Direction::LEFT:
                j--;
                cout << "[Inserimento]"<<endl;
            break;
            case Direction::DIAG:
                i--;
                j--;
                cout << "[Sostituzione/Corrispondenza]"<<endl;
            break;

            default:
                break;
       } 
    }
    

  return 0;
}