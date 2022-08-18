#ifndef List_hpp
#define List_hpp

//listas con clases funciones
#include <iostream>
#include <cstdlib>

using namespace std;

struct Client{

    int time;

    Client(const int t=0): time(t){};
};

struct Node{

    Client info;
    Node* next;

    Node(const Client& c=Client(), Node* n=NULL): info(c), next(n){};
};

//Clase Lista
class List{

    //Seccion Protected
    protected:
        Node *first, *last; // Cabeza y Cola de la Lista
        int length;
        int maxLength;
        int completed;
        friend ostream& operator<<(ostream&, const List&); // Sobrecarga del operador '<<''

    public:
        List(): first(NULL), last(NULL), length(0), maxLength(0), completed(0){}; // Constructor
        ~List() { while(pop()); }; // Destructor

        bool empty() const{ return first == NULL; }; //Lista vacia

        bool push(const Client&); //Inserta en Orden las palabras
        bool pop(); //Elimina una palabra

        const Client front() const { return first->info; };
        const int getListTime() const;
        const int getLength() const { return length; };
        const int getMaxLength() const { return maxLength; };
        const int getCompleted() const { return completed; };
        const float averageTime() const{ return getListTime() / getLength(); };
        void decrementTime() { if(!empty()) first->info.time--; };
};

//Sobrecarga del operador '<<' para las palabras y las listas
ostream& operator<<(ostream&,const Client&);
ostream& operator<<(ostream&,const List&);

#endif