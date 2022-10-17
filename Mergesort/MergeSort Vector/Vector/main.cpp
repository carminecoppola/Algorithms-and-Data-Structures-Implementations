/*  Riscrivere il Merge Sort utilizzando il contenitore Vector
    ed un iteratore
*/
#include <iostream>
#include <vector>
#include"Algoritmo.h"

using namespace std;

int main(){

    vector<int> a = {7,9,3,1};
   
   cout<<"Array iniziale:"<<endl;
    for (auto &i:a){
        cout<<i<<" ";
    }
    cout<<endl;
    
    //Chiamata alla funzione mergesort
    Algoritmo<int>::mergesort(a.begin(),a.end());

    cout<<"Array ordinato dopo mergesort:"<<endl;
    for (auto &i:a){
        cout<<i<<" ";
    }


    return 0;
}

