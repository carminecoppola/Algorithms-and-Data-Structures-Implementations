
/* Progettare ed implementare una procedura Merge ricorsiva */

#include <iostream>
#include"ricorsivo.h"

using namespace std;

int main(){

    int a[4] = {4,3,1,2};

    cout<<"Array iniziale:"<<endl;
    for (auto &i:a){
        cout<<i<<" ";
    }
    cout<<endl;

    ricorsivo<int>::mergesort(a,0,3);

    cout<<"Array ordinato dopo mergesort:"<<endl;
    for (auto &i:a){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}