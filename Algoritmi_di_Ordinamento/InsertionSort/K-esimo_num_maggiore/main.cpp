/* Dato un insieme di N numeri, trovare il k-esimo numero più grande 
     1) Bisogna prima ordinare l'array;
     2) Trovare il k-esimo numero più grande;
*/

#include<iostream>

using namespace std;

void printArray(int arr[], int n){
    for(int i = 0; i < n;i++){
        cout<<" "<<arr[i];
    }
    cout<<endl;
};

void insertionSort(int arr[],int n){

    int i,j,key;

    for (j = 1; j < n; j++)
    {
        key = arr[j];
        i = j-1;

        while (i >= 0 && arr[i] < key)
        {
            arr[i+1] = arr[i];
            i = i-1;
        }
        arr[i+1] = key;
    }
}

int searchKMax(int arr[],int n,int k){


    return arr[k];
}
int main(){

    int arr[] = { 2, 5, 6, 4, 3 , 1};
    int N = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    cout<<endl<<"***Stampa array iniziale***"<<endl;
    printArray(arr,N);
    insertionSort(arr, N);
    cout<<"***Stampa array dopo insertion***"<<endl;
    printArray(arr, N);
    searchKMax(arr,N,k);
    cout<<"Il 2 elemento massimo è:"<<arr[k]<<endl;

    return 0;
}