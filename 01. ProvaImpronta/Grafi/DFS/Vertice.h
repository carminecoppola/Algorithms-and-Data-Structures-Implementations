#ifndef VERTICE_H
#define VERTICE_H

#include<iostream>
#include<limits>
#include<string>
using namespace std;

//Questa enum class ci serve per i colori dei grafi
enum class Color{
    WHITE, GRAY, BLACK
};


template<class T>
class Vertice
{
    private:
         T value;
         Color colore;
         Vertice<T> *predecessore;
         int distanza;

        int tempInizio;
        int tempFine;
    public:
        Vertice(T );

        //Metodi di set
        void setValue(T value){this->value = value;}
        void setColor(Color colore){this->colore = colore;}
        void setPredecessore(Vertice<T> *predecessore){this->predecessore = predecessore;}
        void setDistanza(int distanza){this->distanza = distanza;}
        void setTempInizio(int tempInizio){this->tempInizio = tempInizio;}
        void setTempFine(int tempFine){this->tempFine = tempFine;}

        //Metodi di get
        T getValue(){return value;}
        Color getColor(){return colore;}
        Vertice<T> *getPredecessore(){return predecessore;}
        int getDistanza(){return distanza;}
        int getTempInizio(){return tempInizio;}
        int getTempFine(){return tempFine;}

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

        friend bool operator== (const Vertice<T> &a, const Vertice<T> &b)
        {
            return a.value == b.value;
        }
        
};

//Costruttore
template<class T> Vertice<T>::Vertice(T value)
{
    this->value = value;
    colore = Color::WHITE;  //Inizialmente tutti bianchi
    predecessore = nullptr;
    distanza = UINT16_MAX;

    tempInizio = 0;
    tempFine = 0;
}

#endif
