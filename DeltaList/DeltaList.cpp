#include "DeltaList.hpp"


bool DeltaList::push(const Client& info){

	Node* node = new Node(info);
	Node* iter = first;
	Node* prev = NULL;

	while(iter && node->info.time > iter->info.time){
		node->info.time -= iter->info.time;
		prev = iter;
		iter = iter->next;
	}

	if(iter){
		node->next = iter;
		iter->info.time -= node->info.time;
	}

	if(prev)
		prev->next = node;
	else
		first = node;

	length++;
	return true;
}

ostream& operator<<(ostream& stream,const DeltaList& l){
    for(Node* i = l.first; i; i = i->next)
        stream << i->info << " -> ";
    return stream;
}