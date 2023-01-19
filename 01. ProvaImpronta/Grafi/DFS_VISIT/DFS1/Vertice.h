#ifndef VERTICE_H
#define VERTICE_H
#include<iostream>
#include<limits>
#include<string>

using namespace std;

enum class Color
{
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

        //Metodi di set
        void setValue(T value){this->value = value;}
        void setColor(Color colore){this->colore = colore;}
        void setPredecessor(Vertice<T> *predecessore){this->predecessore = predecessore;}
        void setTempInizio(int tempoInizio){this->tempoInizio = tempoInizio;}
        void setTempFine(int tempoFine){this->tempoFine = tempoFine;}

        //Metodi di get
        T getValue(){return value;}
        Color getColor(){return colore;}
        Vertice<T> *getPredecessor(){return predecessore;}
        int getTempInizio(){return tempoInizio;}
        int getTempFine(){return tempoFine;}

        friend ostream& operator<<(ostream& out, const Vertice<T>& obj)
        {
            string c;
            switch(obj.colore)
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

        friend bool operator ==(const Vertice<T> &a , const Vertice<T> &b)
        {
            return a.value == b.value;
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