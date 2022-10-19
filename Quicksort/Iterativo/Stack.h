#ifndef STACK_H
#define STACK_H

template <typename T>

class Stack{
    private:
        int Dim;    //Massima occupazione della pila
        int Top;   //Ultimo elemento inserito
        T *Vet;   //Pila di T
    public:
        Stack(){
            Vet = nullptr; // pila vuota
            Dim = 0;
            Top = -1;
        }
    void Push (T Elm);
    bool Pop (T &Elm);
    bool isEmpty();



};

template <typename T> void Stack<T>::Push (T Elm){
    if (Top == Dim-1){   // se lo Stack è pieno
    T *App;
    App = new T[Dim+10];  // trasloca lo stack
    for (int i=0; i<Dim; i++) 
        App[i] = Vet[i];
        Dim += 10;
    delete [] Vet;
        Vet = App;      // allunga lo stack
    }
    Vet[ ++Top ] = Elm;
}

template <typename T> bool Stack<T>::Pop (T &Elm){
    bool Risp;
    if (Top >= 0){
        Risp = true;
        Elm = Vet[Top--];
    }
    else
        Risp = false;   // stack vuoto
    return Risp;
}

template <typename T> bool Stack<T>::isEmpty(){

    return Top == -1;
}

#endif //STACK_H