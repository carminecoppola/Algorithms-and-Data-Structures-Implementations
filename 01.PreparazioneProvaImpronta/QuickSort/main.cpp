/* Riscrivere il quicksort utilizzando il contenitore vector*/

#include <iostream>
#include<vector>
#include"algoritmo.h"

using namespace std;

int main(){

    vector<int> a = {7,9,3,1};
   
    cout<<"Array iniziale:"<<endl;
        for (auto i:a){
            cout<<i<<" ";
        }
    cout<<endl;

    //Chiamata alla funzione quicksort
    algoritmo<int>::quickSort(a.begin(),a.end()-1);

    cout<<"Array ordinato dopo quicksort:"<<endl;
    for (auto i:a){
        cout<<i<<" ";
    }

    return 0;
}