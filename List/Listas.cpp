#include "Listas.h"
#include <cstdlib>

using namespace std;

//Destructor
List::~List(){
    Node* iter = first;

    while(iter){
        Node* aux = iter;
        iter = iter->next;
        delete aux;
    }
}

//Inserta una palabra, de manera ordenada, en la Lista 
bool List::push(const Node& word){

    Node* iter = first;
    Node* prev = NULL;

    while(iter && Node.nroCarCaja > iter->Node.nroCarCaja){
        prev = iter;
        iter = iter->next;
    }

    Node* node = new Node(node,iter);

    if(prev)
        prev->next = node;
    else
        first = node;
    return true;
}

bool List::pop(const Node& word){

    Node* iter = first; 
    Node* prev = NULL;

    while(iter && Node.nroCarCaja > iter->Node.nroCarCaja){
        prev = iter;
        iter = iter->next;
    }

    if(iter)
        if (prev)
            prev->next = iter->next;
        else
            first = first->next; 
    else 
        return true;

    delete iter;
    return true;
}

//Busca un elemento en la lista
bool List::find(const Word& word){
    
    for(Node* iter = first; iter; iter = iter->next)
        if(iter->word.name == word.name)
            return true;

    return false;
}