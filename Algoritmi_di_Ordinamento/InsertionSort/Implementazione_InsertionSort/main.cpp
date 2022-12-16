/*Implementazione dell'Inserction sort*/

#include <iostream>

using namespace std;

void printArray(int arr[], int n){
    int i;
    
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";  
        cout << endl;
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    
    for (j = 1; j < n; j++){
        key = arr[j];
        //cout<<"Prima del while key= "<<key<<endl;
        i = j - 1;
        //cout<<"1)Prima del while j= "<<arr[j]<<endl;
        //cout<<"2)Prima del while i= "<<arr[i]<<endl;
    //cout<<"-------WHILE-------------"<<endl;
    while (i >= 0 && arr[i] > key){
        arr[i + 1] = arr[i];
        i = i - 1;
        //cout<<"3)NEL WHILE J= "<<arr[j]<<endl;
        //cout<<"4)NEL WHILE I= "<<arr[i]<<endl;
        //cout<<"Array NEL WHILE:"<<endl;
        //printArray(arr,n);
        //cout<<endl<<endl;

    }
    //cout<<"------FINE WHILE---------------"<<endl;
    arr[i + 1] = key;
    //cout<<"DOPO WHILE Key="<<key<<endl;
    //cout<<"Array DOPO WHILE"<<endl;
    //printArray(arr,n);
    //cout<<endl;
    //cout<<"1)Dopo While j= "<<arr[j]<<endl;
    //cout<<"2)Dopo While i= "<<arr[i]<<endl;
    //cout<<endl<<endl;

    }
};

int main()
{
    int arr[] = { 2, 5, 6, 4, 3 , 1};
    int N = sizeof(arr) / sizeof(arr[0]);

    cout<<endl<<"***Stampa array iniziale***"<<endl;
    printArray(arr,N);
    insertionSort(arr, N);
    cout<<"***Stampa array dopo insertion***"<<endl;
    printArray(arr, N);

    return 0;
}