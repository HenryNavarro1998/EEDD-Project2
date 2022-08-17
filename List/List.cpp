#include "List.hpp"
#include <cstdlib>

using namespace std;

bool List::push(const Client& client){

    Node* node = new Node(client);

    if(empty())
        first = node;
    else
        last->next = node;

    last = node;
    length++;
    return true;
}

bool List::pop(){

    if(empty())
        return false;

    Node* aux = first;
    first = first->next;

    delete aux;
    length--;
    return true;
}

ostream& operator<<(ostream& stream, const Client& c){
    stream << c.name;
    return stream;
}

ostream& operator<<(ostream& stream, const List& l){
    stream << endl;
    for(Node* i = l.first; i; i = i->next)
        stream << i->info << endl;
    return stream;
}
