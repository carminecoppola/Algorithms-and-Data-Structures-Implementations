
#include<iostream>
#include<vector>
#include"algoritmo.h"

using namespace std;

int main(){

    vector<int> a = {7,9,3,1};
   
    cout<<"Array iniziale:"<<endl;
        for (auto &i:a){
            cout<<i<<" ";
        }
    cout<<endl;

    //Chiamata alla funzione mergesort
    algoritmo<int>::mergesort(a.begin(),a.end());

    cout<<"Array ordinato dopo mergesort:"<<endl;
    for (auto &i:a){
        cout<<i<<" ";
    }


    return 0;
}