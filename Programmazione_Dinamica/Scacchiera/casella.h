#include<iostream>

using namespace std;

/*  Creiamo una classe di tipo ENUM per gestire i tre diversi casi della
    direzione che viene fatta ad ogni casella.*/

enum class Direction{UP,LEFT,DIAG};
ostream& operator<<(ostream& out, const Direction& dir){
    switch (dir)
    {
    case Direction::UP:
        out<<"U";
        break;
    case Direction::LEFT:
        out<<"L";
        break;
    case Direction::DIAG:
        out<<"D";
        break;
    default:
        break;
    }
    return out;
}


class casella{
    private:
        int value;
        Direction dir;  //per indicare la direzione che assume ad ogni passo la pedina
    public:
        casella():value{0}, dir{Direction::UP}{}
        casella(int value, Direction dir):value{value}, dir{dir}{}

        //metodo di getter per ritornare il valore e la direzione

        int getValue(){
            return value;
        };

        Direction getDirection(){
            return dir;
        };

        //Metodi per settare il valore e la direzione

        void setValue(int value){
            this->value = value;
        }

        void setDirection(Direction dir){
            this->dir = dir;
        }
};

