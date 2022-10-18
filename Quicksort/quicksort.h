#ifndef QUICKSORT_H
#define QUICKSORT_H

using namespace std;

class quicksort{
    private:
        void static partition();
        void static swap(int * , int *);
    public:
       void static quick();

};

void quicksort::partition(){


}

void quicksort::swap(int *a, int *b){

    int t = *a;
    *a = *b;
    *b = t;

}

void quicksort::quick(){


}

#endif