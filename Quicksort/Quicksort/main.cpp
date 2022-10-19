#include <iostream>

using namespace std;


//Variante che parte dall'inizio
/*
int partition( int A[], int p,int r)
{
    int x = A[r];
    int i = p-1;
    for (int j = p; j < r-1; j++)
      {
          if (A[j] <= x)
            {
                i = i+1;
                swap(A[i],A[j]);
            }
      }
    swap(A[i+1],A[r]);
    return i+1;
}*/

void swap( int &A, int &B)
{ 
    int t=A;
    A=B;
    B=t;
} 



int partition (int a[ ], int l, int r)
{
    int i= l-1, j=r;
    int v = a[r];

    for(;;)
    {
        while (a[++i] < v);
        while (v < a[--j])
            if(j == l)
                break;
        if (i >= j)
            break;
        swap (a[i],a[j]);
    }
    swap(a[i],a[r]);
    return i;

}


void quicksort(int a[ ], int l, int r)
{
   
    if (r <= l)
        return;
    int i = partition(a,l,r);

    quicksort(a,l,i-1);
    quicksort(a,i+1,r);

}

int main()
{
    int arr [] = {2,8,7,1,3,5,6,4};

    cout<<"\nL'array iniziale è:"<<endl;
    for(int i = 0; i < 8; i++)
    {
        cout << arr[i]<< " ";
    }
    cout<<endl;

    quicksort(arr,0,7);

    cout<<"\nL'array ordinato è:"<<endl;
    for(int i = 0; i < 8; i++)
    {
        cout << arr[i]<< " ";
    }
    cout<<endl;
    return 0;
}