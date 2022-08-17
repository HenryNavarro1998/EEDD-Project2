/****************************************************
* Jorge Caraballo                            		*
* V-30.366.057                                   	*
* ESTRUCTURA DE DATOS                               *
* SECCIÓN 01                                        *
* PRACTICA #2 'Listas, Pilas y Colas'.				*
*****************************************************/

//Librerias Incluidas
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "List/List.hpp"

using namespace std;

struct Limits {
	int lower;
	int upper;

	Limits(int l=0, int u=0): lower(l), upper(u) {};
	int randValue() { return (rand() % upper) + lower; };
};

void initialData(int&,Limits&,Limits&);
int sleep(const float);

//Funcion Main
int main(){

	List waiting;
	List cashRegister[3];
	Limits new_client_time;
	Limits shopping_time;
	int simulation_time;
	int current_time = 0;
	int client_time = 0;
	int shop_time = 0;

	srand(time(NULL));
	initialData(simulation_time, new_client_time, shopping_time);

	while(current_time < simulation_time){

		if(!client_time){
			waiting.push(Client("Cliente"));
			client_time = new_client_time.randValue();
		}

		cout << waiting << endl;
		cout << "Tiempo transcurrido: " << current_time << endl;
		cout << "Tiempo restante: " << simulation_time - current_time << endl;
		client_time--;
		current_time += sleep(1);
	}

	cout << waiting;

    return 0;
}

void initialData(int& simulation_time, Limits& new_client_time, Limits& shop_time){

	cout << "Ingrese el tiempo de ejecucion (seg): ";
	cin >> simulation_time;

	cout << "Limite inferior para la llegada de un nuevo cliente (seg): ";
	cin >> new_client_time.lower;

	cout << "Limite superior para la llegada de un nuevo cliente (seg): ";
	cin >> new_client_time.upper;

	cout << "Limite inferior para la compra (seg): ";
	cin >> shop_time.lower;

	cout << "Limite superior para la compra (seg): ";
	cin >> shop_time.upper;

}

int sleep(const float seconds){
    //Referencia del momento
    clock_t start = clock();

    //Mientras no hayan pasado 'n' segundos, retrasamos el programa
    while(clock() < (start + (seconds * CLOCKS_PER_SEC)));
    return 1;
}

// // --- funciones desarrolladas ---
// void option(string& opc){

// 	do{
// 		system("cls || clear");

// 		cout << "\t\t--- Ingrese una opcion ---" << endl;
// 		cout << "\t\t[1] Iniciar la simulacion" << endl;
// 		cout << "\t\t[2] Salir" << endl;
// 		cout << "\t\tOPC [ ]\b\b";
// 		cin >> opc;
// 		fflush(stdin);
// 	} while(opc != "1" && opc != "2");
// 	return;
// }

// void question(List& l[3], int& timeSimulation, int& randL, int& randClP){
// 	int tCaja;

// 	system("cls || clear");
// 	cout << "\t\tIngresa cuanto tarda la simulacion y como se va completando: \n\n" << endl;
// 	cin >> timeSimulation;
// 	fflush(stdin);

// 	cout << "\t\tIngresar rango de tiempo en el que llegan los clientes al local: \n" << endl;
// 	cin >> randL;
// 	fflush(stdin);

// 	for (int i = 0; i < 3; ++i){
// 		cout << "\n\t\tIngresa el tiempo en que tardan los clientes en caja " << i << " :" << endl;
// 		cin >> tCaja; 

// 		if (i == 0) { l[0].timeCaja(tCaja); }
// 		else if (i == 1) { l[1].timeCaja(tCaja); }
// 		else if (i == 2) { l[2].timeCaja(tCaja); }
// 		fflush(stdin);
// 	}

// 	cout << "\n\n\t\tIngresar rango de tiempo en el que tarda el cliente buscando productos: " << endl;
// 	cin >> randClP;
// 	fflush(stdin);
// 	return;
// }

// void shopping(){
// 	srand(0); //numeros aleatorios que se repiten. 
//     return rand()% randClP + 1;
// }

// void cola(){
// 	return;
// }

// void process(int carrito, int timeSimulation, List& l[3], int randL){
// 	// variabes
// 	int iter = 0;
// 	int i = 0, j = 0, z = 0;

// 	while(timeSimulation != 0){
// 		cout << timeSimulation-- << endl;

// 		if(randL == iter++){// clientes que llegan al local
// 		 	clientes++;
// 		 	iter = 0; // se reinicia el conteo
// 		} 

// 		if(time++ == shopping()) // tiempo en que tardan comprando, se realentiza
// 			// colocar en la cola

// 		if (carrito != 0 || clientes != 0){ l[0].push(); }
// 		if (carrito != 0 || clientes != 0){ l[1].push(); }
// 		if (carrito != 0 || clientes != 0){ l[2].push(); }

// 		cout << "Numero de carritos en la caja 1: " << l[0].length() << endl;
// 		cout << "Numero de carritos en la caja 2: " << l[1].length() << endl;
// 		cout << "Numero de carritos en la caja 3: " << l[2].length() << endl;

// 		Sleep(1000); // tiempo (seg) en el que tarda de comprar o culminar los clientes  

// 		// Personas que salieron de la caja
// 		if(l[0].getTime() == i++) { l[0].pop(); }
// 		if(l[1].getTime() == j++) { l[1].pop(); }
// 		if(l[2].getTime() == z++) { l[2].pop(); }
// 	}

// 	// culminacion de la simulacion
// 	cout << "\nLongitud maxima de las colas: " << lengthMax(l[0]) << endl;
// 	cout << "\nLongitud maxima de las colas: " << lengthMax(l[1]) << endl;
// 	cout << "\nLongitud maxima de las colas: " << lengthMax(l[2]) << endl;

// 	// CREAR UJNA VARIABLE PARA LAS LONGITUDES DE CADA UNA
// 	cout << "\nLongitud maxima de las colas: " << lengthMax(l[0])+lengthMax(l[1])+lengthMax(l[2])/3 << endl;

// 	cout << "" << endl; // MOSTRAR TIEMPO POR CARRITO 

// 	// CREAR UJNA VARIABLE PARA LOS TIEMPOS DE CADA UNA DE ALS CAJAS
// 	cout << "\nPromedio de tiempo por clientes en caja: " << AverageTimeG(l[0]) << endl;
// 	cout << "\nPromedio de tiempo por clientes en caja: " << AverageTimeG(l[1]) << endl;
// 	cout << "\nPromedio de tiempo por clientes en caja: " << AverageTimeG(l[2]) << endl;
	
// 	cout << "\nPromedio de tiempo por clientes en caja: " << AverageTimeG(l[0])+AverageTimeG(l[1])+AverageTimeG(l[2])/3 << endl;

// 	cout << "Maximo de clientes en el local: " << clienteG << endl; // clientes en la tienda
// 	cout << "Maximo de clientes en el local: " << clienteMax << endl; // maximo de clientes

// 	cout << "\n\n\t\t--- Se acabo la simulacion ---"

// 	return;
// }

// int lengthMax(List& Caja){ // longitud maxima
// 	int length = Caja.car;

// 	while( !Caja.empty() )
// 		if (length > car->next)
// 			length = car;
// 	return length;
// }

// int AverageTimeG(){ // promedio de tiempo global
// 	int mean = 0, iter = 0;

// 	while( !Caja1.empty() && !caja2.empty() && !caja3.empty() ){
// 		if(caja1.empty() != false){
// 			acum+=caja1.getTime();
// 			caja1 = caja1->next;
// 		}else if(caja2.empty() != false) {
// 			acum+=caja2.getTime();
// 			caja2 = caja2->next;
// 		}else if(caja3.empty() != false) {
// 			acum+=caja3.getTime();
// 			caja3 = caja3->next;
// 		}

// 		++iter;
// 	}

// 	return acum/i;
// }

// int AverageTime(){ // promedio de tiempo
// 	int mean = 0, iter = 0;

// 	while( !Caja1.empty() && !caja2.empty() && !caja3.empty() ){
// 		acum+=time;
// 		++iter;
// 	}
// 	return acum/i;
// }

// int nroClientes(){
// 	return acum;
// }