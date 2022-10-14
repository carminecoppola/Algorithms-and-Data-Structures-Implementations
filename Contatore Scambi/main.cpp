/*  Progettare ed implementare un algoritmo ricorsivo per contare il 
    numero di scambi necessari per ordinare un' array

                    [9,7,3,1]->(9,7),(9,3),(9,1)
                    [7,3,1,9]->(7,3),(7,1)
                    [3,1,7,9]->(3,1)
                    [1,3,7,9]
*/

//Marge a due vie

#include <iostream>

using namespace std;
typedef int Item;
int contatore = 0;


void merge(Item a[],int left,int center, int right){

    const int n=4;
    static Item aux[n];

    int i,j;

    for (i = center+1; i > left; i--){
        aux[i-1] = a[i-1];
    }

    for (j = center; j < right; j++){
        aux[right+center-j] = a[j+1];
    }    

    for (int k = left; k <= right; k++){
        if (aux[j] < aux [i]){
            a[k] = aux [j--];
            contatore += center+1-left;
        }
        else
            a[k] = aux[i++];
        
    }
}

void mergesort(Item a[],int left,int right){

    if (left < right){
        
        int center = (left+right)/2;
        mergesort(a,left,center);
        mergesort(a,center+1,right);
        merge(a,left,center,right);
    }
    
}

int main(){

    const int n = 4;
    int a[n] = {9,7,3,1};

    for (int i = 0; i < n; i++){
        cout<<"["<< a[i] <<"]";
    }
    cout<<endl;
    mergesort(a,0,n-1);
    
    for (int i = 0; i < n; i++){

        cout<<"["<< a[i] <<"]";
    }
    
    cout<<endl;
    cout<<"Il numero di scambi è: "<< contatore <<endl;
    return 0;
}