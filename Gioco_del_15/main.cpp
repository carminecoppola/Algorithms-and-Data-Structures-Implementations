/*  Il gioco del 15 consiste nel disporre le celle da 1 a 15 per riga in una matrice
    4x4. Avendo a disposizione una sola cella vuota, è possibile spostare solo le
    celle adiacianti alla cella vuota, in orizzontale ed in verticale.
                    
                   | 13   10   11   6|
                   | 5    7    4    8|
                   | 1    12   14   9|
                   | 3    15   2     |
                   

    Progettare ed implementare un programma che legga da file una
    configurazione del gioco e verifichi se rappresenta la soluzione, usando un
    contenitore della STL.
    Implementare una versione parallella che, usando i thread, consenta di
    verificare più file contemporaneamente.
*/

#include "Verificatore.h"


int main(){

    Verificatore ogg("File1.txt");
    Verificatore ogg_2("File2.txt");

    std::cout<<std::boolalpha<<ogg.check();
    std::cout<<std::boolalpha<<ogg_2.check();  

    return 0;

}