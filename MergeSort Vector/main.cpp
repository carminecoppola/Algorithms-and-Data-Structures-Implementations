/*  Riscrivere il Merge Sort utilizzando il contenitore Vector
    ed un iteratore
*/
#include <iostream>
#include <vector>
#include"Algoritmo.h"

using namespace std;

int main(){

    vector<int> a = {7,9,3,1};
    //vector<int>::iterator i;
   

   for (auto &i:a)
   {
    cout<<i<<" ";
   }
   cout<<endl;
    
    Algoritmo<int>::mergesort(a.begin(),a.end());

    for (auto &i:a)
   {
    cout<<i<<" ";
   }


    return 0;
}

