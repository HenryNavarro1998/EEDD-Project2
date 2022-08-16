#ifndef listas.h
#define listas.h

//listas con clases funciones 
#include <iostream>
#include <cstdlib>

using namespace std;

struct Node{ // carritos 
    int nroCarCaja;
    int timeCar;
    
    // Node(): ;
    Node(int nroCar, int time): n(n), ;
}

//Clase Lista
class List{// Caja
    //Seccion Privada
    private:
        friend ostream& operator<<(ostream&, const List&); // Sobrecarga del operador '<<''
        int timeCaja;
        int clientes;
        Node *first; // Cabeza y Cola de la Lista

    public:
        List(){first = NULL;}; // Constructor
        ~List(); // Destructor

        bool empty() const{return first == NULL;}; //Lista vacia
        bool push(const Word&); //Inserta en Orden las palabras
        bool find(const Word&); //Busca si una palabra existe
        bool update(const Word&); //Actualiza una palabra
        bool pop(const Word&); //Elimina una palabra
        
        void timeCajaSet(int) { timeCaja = timeC; };
        int GetTimeCaja() { return timeCaja; };
};

//Sobrecarga del operador '<<' para las palabras y las listas
ostream& operator<<(ostream&,const Word&);

#endif