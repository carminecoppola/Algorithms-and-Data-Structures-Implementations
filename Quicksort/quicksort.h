#ifndef QUICKSORT_H
#define QUICKSORT_H

using namespace std;

class quicksort{
    private:
        int static partition(int *,int ,int ,int* );
        void static swap(int * , int *);
    public:
       void static quick(int *a, int l,int r);

};

int quicksort::partition(int *a,int s, int f, int *puntatore){

     if (a[s]< a[f]){
        swap(&a[s], &a[f]);
    }
    
    int p1,p2;
    p1 = a[s];
    p2 = a[f];

    int i,j,k;
    i = s + 1;
    j = f - 1;
    k = s + 1;

    while (k <= j){
        if (a[k] < p1){
            swap(&a[k],&a[i]);
            i++;
        }
        else if (a[k] >= p2){
            while (a[j] > p2 && k < j){
                j--;
            }
            swap(&a[k],&a[j]);
            j--;

            if (k < p1){
                swap(&a[k],&a[i]);
                i++;
            }
        }    
        k++;   
    }
    i--;
    j++;

    swap(&a[i],&a[s]);
    swap(&a[j],&a[f]);
    
    *puntatore = j;
    return i;

}

void quicksort::swap(int *a, int *b){

    int t = *a;
    *a = *b;
    *b = t;

}

void quicksort::quick(int *a, int l,int r){

    if (r <= l)
        return ;

    int j;
    int i = partition(a,l,r,&j);
    quick(a,l,i-1);
    quick(a,i+1,j);
    quick(a,j+1,r);
}

#endif