#ifndef List_hpp
#define List_hpp

//listas con clases funciones 
#include <iostream>
#include <cstdlib>

using namespace std;

struct Client{

    int time;

    Client(const string& n=""): name(n) {};
};

struct Node{

    Client info;
    Node* next;
    
    Node(const Client& c=Client(), Node* n=NULL): info(c), next(n){};
};

//Clase Lista
class List{

    //Seccion Privada
    private:
        Node *first, *last; // Cabeza y Cola de la Lista
        int length;
        friend ostream& operator<<(ostream&, const List&); // Sobrecarga del operador '<<''

    public:
        List(): first(NULL), last(NULL), length(0){}; // Constructor
        ~List() { while(pop()); }; // Destructor

        bool empty() const{ return first == NULL; }; //Lista vacia
        
        bool push(const Client&); //Inserta en Orden las palabras
        bool pop(); //Elimina una palabra
        
        const Client& front() const { return first->info; };
};

//Sobrecarga del operador '<<' para las palabras y las listas
ostream& operator<<(ostream&,const Client&);
ostream& operator<<(ostream&,const List&);

#endif