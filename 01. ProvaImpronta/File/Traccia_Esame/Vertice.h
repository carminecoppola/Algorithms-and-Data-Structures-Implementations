#ifndef VERTICE_H
#define VERTICE_H

#include<iostream>
#include<string>
#include<limits>

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
        int tempInizio;
        int tempFine;

    public:
        Vertice(T value);

        //Metodi di set
        void setValue(T value){this->value = value;}
        void setColor(Color colore){this->colore = colore;}
        void setPredecessore(Vertice<T> *predecessore){this->predecessore = predecessore;}
        void setTempInizio(int tempInizio){this->tempInizio = tempInizio;}
        void setTempFine(int tempFine){this->tempFine = tempFine;}

        //Metodi di get

        T getValue(){return value;}
        Color getColore(){return colore;}
        Vertice<T> *getPredecessore(){return predecessore;}
        int getTempInizio(){return tempInizio;}
        int getTempFine(){return tempFine;}

        //Overload
        friend ostream& operator<<(ostream& out, const Vertice<T> &obj)
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
            out<<"Valore: "<<obj.value <<" Colore: "<<c;
            return out;
        }

};

template<class T> Vertice<T>::Vertice(T value){

    this->value = value;
    colore = Color::WHITE;
    predecessore = nullptr;
    tempInizio = 0;
    tempFine = 0;
}

#endif
