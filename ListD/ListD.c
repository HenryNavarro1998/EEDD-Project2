#ifndef list_hpp
#define list_hpp

using namespace std;

// ------------- estructura nodo ------------- 
struct nodoDelta {
	string process;
	string espera; 
	nodoDelta* sig;

	nodoDelta(): process(), time(), next(NULL){};
	nodoDelta(string& p, string& e, nodoDelta* n = NULL): process(p), espera(e), next(n){};
}

// ------------------------- clase lista -------------------------

class listaDelta{

	private:
		nodoDelta* ini;

	public:		
		listaDelta() { ini = NULL; }; // constructor
		~listaDelta(); //  destructor

		bool empty(){ return ini == NULL; };
		bool InsertalistaDelta( );
		bool ( );
		void show();
}

// -------------------------- funciones de la clase -------------------------

// Destructor
List::~List(){
	nodoDelta* iter = first;

	while(iter){
		nodoDelta* aux = iter;
		iter = iter->next;
		delete aux;
	}
}

bool InsertalistaDelta(listaDelta ldp, string process, int espera){
	nodoDelta *np;
	nodoDelta *ap = NULL
	nodoDelta *cp = ldp->ini;

	if( (np = (nodoDelta *)malloc( sizeof(nodoDelta) ) ) == NULL)
		return false;

	np->elemento = elemento;
	np->espera = espera;
	
	while(cp && np->espera >= cp->espera){
		np->espera -= cp->espera;
		ap = cp;
		cp = cp->sig;
	}

	np->sig = cp;
	
	if(cp != NULL) 
		cp->espera -= np->espera;
	if(ap) 
		ap->sig = np;
	else 
		ldp->ini = np;
	
	return true;
}

// Decrementa tiempo en una lista delta,
void DecrementaListaDelta(listaDelta ldp, int tiempo){
	nodoDelta *cp = ldp->ini;

	while(cp){

		if(cp->espera >= tiempo){
			cp->espera -= tiempo;
			break;
		}else {
			tiempo -= cp->espera;
			cp->espera = 0;
		}
		
		cp = cp->prox;
	}

	return;
}

// Retorna 1 si el primer elemento de la lista tiene espera == 0
int ListoEnListaDelta(listaDelta ldp){
	return ldp->ini && !ldp->ini->espera;
}

bool listaDelta::eliminarNodo(nodoDelta nd){
	nodoDelta* iter = ini;
	nodoDelta* prev = NULL;

	while(iter && iter->nd.process != nd.process){
		prev = iter;
		iter = iter->sig;
	}

	if (iter){
		if (prev)
			prev->sig = iter->sig;
		else
			ini = ini->sig;
	}else 
		return false;	

	delete iter;
	return true;	
}
	
#endif
