/*  Riscrivere il quicksort utilizzando il contenitore Vector
    ed gli iteratori 
*/

#include <iostream>
#include <vector>
#include "Algoritmo.h"

using namespace std;

int main(){

    vector <int> a = {2,7,11,30,4,32,12,8,15};

    cout<<"\nL'array iniziale è:"<<endl;
    for (auto i:a){
        cout<<i<<" ";
    }
    cout<<endl;
    
    Algoritmo <int>::quicksort(a.begin(),a.end()-1);

    cout<<"\nL'array ordinato è:"<<endl;
    for (auto i:a){
        cout<<i<<" ";
    }
    cout<<endl;


    return 0;
}