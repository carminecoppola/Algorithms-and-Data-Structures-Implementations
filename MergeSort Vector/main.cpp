/*  Riscrivere il Merge Sort utilizzando il contenitore Vector
    ed un iteratore
*/
#include <iostream>
#include <vector>
#include"Algoritmo.h"

using namespace std;
template <typename Item>

int main(){

    vector<int> a = {7,9,3,1};
    vector<int>::iterator i;
   

    for (i = 0; i < a.end(); i++){
        cout<<"["<<a.at(*i)<<"]";
    }
    cout<<endl;
    
    Algoritmo<int>::mergesort(a,a.begin(),a.end());

    for (i = 0; i < a.end(); i++){
        cout<<"["<<a.at(*i)<<"]";
    }


    return 0;
}

