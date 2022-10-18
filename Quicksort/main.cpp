/*  Implementare il Quicksort con doppio pivot
        • Questa variante utilizza un pivot per la parte sinistra dell'array ed
        un pivot per la parte destra con il vincolo che il pivot sinistro sia
        minore del pivot destro
        • Al termine della procedura di partition, l'array sarà diviso in tre parti:
                • La prima in cui gli elementi sono minori del pivot sinistro
                • La seconda in cui gli elementi sono maggiori o uguali del
                  pivot sinistro e minori uguali del pivot destro
                • La terza in cui gli elementi sono maggiori del pivot destro
    L'algoritmo viene richiamato ricorsivamente sulle tre parti
    dell'array
*/

#include <iostream>
#include"quicksort.h"
using namespace std;

int main (){

    int a[7] = {1,4,5,23,78,3,7};

    cout<<"Array iniziale:"<<endl;
    for (int i = 0; i < 6; i++){
        cout<<i<<" ";
    }

    quicksort::quick(a,0,6);

    cout<<"Array finale:"<<endl;
    for (int i = 0; i < 6; i++){
        cout<<i<<" ";
    }
    


    return 0;
}