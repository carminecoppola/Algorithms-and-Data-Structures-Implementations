
#include<iostream>
#include<vector>
#include"radixsort.h"

using namespace std;

int main(){

    vector<int> array{170,45,75,90,802,24,2,66};
    
    cout<<endl<<"L'array iniziale è: "<<endl;
    Radixsort::print(array);


    Radixsort::radixsort(&array);
    cout<<endl<<"L'array dopo RadixSort è: "<<endl;
    Radixsort::print(array);

}