#ifndef VERTICE_H
#define VERTICE_H

#include<iostream>
#include<limits>
#include<string>

using namespace std;

enum class Color{
    WHITE,GRAY,BLACK
};

template<class T>
class Vertice
{
    private:
        T value;
        Color colore;
        Vertice<T> *predecessore;
        int tempoInizio;
        int tempoFine;
    public:
        Vertice(T value);

        //Set
        void setValue(T value){this->value = value;}
        void setColore(Color colore){this->colore = colore;}
        void setPredecessore(Vertice<T> *predecessore){this->predecessore = predecessore;}
        void setTempoInizio(int tempoInizio){this->tempoInizio = tempoInizio;}
        void setTempoFine(int tempoFine){this->tempoFine = tempoFine;}

        //Get
        T getValue(){return value;}
        Color getColore(){return colore;}
        Vertice<T> *getPredecessore(){return predecessore;}
        int getTempoInizio(){return tempoInizio;}
        int getTempoFine(){return tempoFine;}

        friend ostream& operator<<(ostream& out, const Vertice<T>& obj)
        {
            string c;
            switch (obj.colore)
            {
                case Color::WHITE:
                    c = "WHITE";
                    break;
                case Color::GRAY:
                    c = "GRAY";
                    break;
                case Color::BLACK:
                    c = "BLACK";
                    break;
                default:
                    break;
            }
            out<<"Valore: "<<obj.value<<" Colore: "<<c;
            return out;
        }
};

template<class T> Vertice<T>::Vertice(T value)
{
    this->value = value;
    colore = Color::WHITE;
    predecessore = nullptr;
    tempoInizio = 0;
    tempoFine = 0;
}


#endif