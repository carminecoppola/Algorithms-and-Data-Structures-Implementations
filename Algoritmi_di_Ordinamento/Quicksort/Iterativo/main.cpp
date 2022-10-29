/* Progettare ed implementare una procedura quicksort
    iterativa
        • Usare lo stack illustrato nella lezione 4
*/

#include <iostream>
#include"Algoritmo.h"
#include"Stack.h"

using namespace std;

int main (){

    int a[7] = {1,4,5,23,78,3,7};

    cout<<"Array iniziale:"<<endl;
    for (int i = 0; i < 7; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    Algoritmo<int>::quicksort_iterativo(a,0,6);

    cout<<"\nArray finale:"<<endl;
    for (int i = 0; i < 7; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}