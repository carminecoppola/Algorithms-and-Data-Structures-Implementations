/*  
    Aggiunger il metodo heapsort alla classe Heap
*/
#include<iostream>
#include<vector>
#include "heapsort.h"

using namespace std;

int main(){

    vector<int> tree{10,15,22,7,40,3};
    heapsort<int> albero = heapsort<int>(tree);
    
    cout<<endl<<"Albero iniziale:";
    albero.printArray();
    albero.heapSort();
    cout<<endl<<"Albero dopo HEAPSORT:";
    albero.printArray();

    return 0;
}
