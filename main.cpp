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
#include "DeltaList/DeltaList.hpp"

using namespace std;

const int N = 3;

struct Limits{
	int lower;
	int upper;
	int randValue() { return (rand() % (upper-lower)) + lower; };
};

struct CashRegister{
	int time;
	List clients;
};

void initialData(int&,Limits&,Limits&,CashRegister*);
void printCashRegisters(const CashRegister*);
int sleep(const float);
int min(const CashRegister*);

int main(){

	srand(time(NULL));
	List waitingQueue;
	CashRegister cashQueue[N];
	DeltaList shopQueue;
	
	Limits new_client_time;
	Limits shopping_time;
	
	int simulation_time;
	int avalibleCart = 0;
	int current_time = 0;
	int client_time = 0;
	int shop_time = 0;
	int totalCompleted = 0;

	initialData(simulation_time, new_client_time, shopping_time, cashQueue);

	while(current_time < simulation_time){

		system("cls || clear");

		if(!client_time){
			waitingQueue.push(shopping_time.randValue());
			client_time = new_client_time.randValue();
		}

		if(!waitingQueue.empty() && avalibleCart < 20){
			shopQueue.push(waitingQueue.front());
			waitingQueue.pop();
			avalibleCart++;
		}

		while(!shopQueue.empty() && !shopQueue.front().time){
			int pos = min(cashQueue);
			cashQueue[pos].clients.push(cashQueue[pos].time);
			shopQueue.pop();
		}

		for(int i=0; i<N; i++){
			if(!cashQueue[i].clients.empty() && !cashQueue[i].clients.front().time){
				cashQueue[i].clients.pop();
				avalibleCart--;
				totalCompleted++;
			}
			cashQueue[i].clients.decrementTime();
		}

		cout << "\n\n\t----------\tEn espera\t----------\n\t";
		cout << waitingQueue << endl;
		cout << "\n\tTotal en Espera: " << waitingQueue.getLength(); 

		cout << "\n\n\t----------\tEn Compra\t----------\n\t";
		cout << shopQueue << endl;
		cout << "\n\tTotal en Compra: " << shopQueue.getLength() << endl;

		printCashRegisters(cashQueue);

		cout << "\tTiempo Transcurrido: " << current_time << " sg" << endl;
		cout << "\tTiempo Restante: " << simulation_time - current_time << " sg" << endl;
		cout << "\tTotal Atendidos: " << totalCompleted << " Clientes Atendidos" << endl;

		client_time--;
		shopQueue.decrementTime();
		current_time += sleep(.2);
	}

    return 0;
}

void initialData(int& simulation_time, Limits& new_client_time,
				Limits& shop_time, CashRegister* cashQueue){

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

	for(int i=0; i<N; i++){
		cout << "Tiempo de Caja #" << i+1 << ": ";
		cin >> cashQueue[i].time;
	}

}

void printCashRegisters(const CashRegister* cashQueue){

	int acumLength = 0;

	for(int i=0; i<N; i++){

		acumLength += cashQueue[i].clients.getLength();

		cout << "\n\t----------\tCaja #" << i+1 << " \t----------\n\t";
		cout << cashQueue[i].clients << endl;
		cout << "\n\tTotal en Caja #" << i+1 << ": " << cashQueue[i].clients.getLength() << endl;
		cout << "\tTotal Atendidos en Caja #" << i+1 << ": " << cashQueue[i].clients.getCompleted() << endl;
	}

	cout << "\n\tTotal en Cajas:" << acumLength << endl;

}

int sleep(const float seconds){
    //Referencia del momento
    clock_t start = clock();

    //Mientras no hayan pasado 'n' segundos, retrasamos el programa
    while(clock() < (start + (seconds * CLOCKS_PER_SEC)));
    return 1;
}

int min(const CashRegister* cashQueue){
	int minLength = cashQueue[0].clients.getLength();
	int pos = 0;

	for(int i=1; i<N; i++)
		if(minLength > cashQueue[i].clients.getLength())
			pos = i;

	return pos;
}
