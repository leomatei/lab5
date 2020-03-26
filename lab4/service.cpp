#include <iostream>
#include <string.h>
#include "repo.h"
#include "tranzactie.h"
#include "service.h"

using namespace std;

Service::~Service() {
	this->che.~Repo();
}
void Service::add(int id, int nr_ap, int suma, char* tip) {
	Cheltuiala c(id, nr_ap, suma, tip);
	che.addCheltuiala(c);
}

void Service::ModificaCheltuiala(int id, int nr_ap, int suma, char* tip) {
	Cheltuiala c(id, nr_ap, suma, tip);
	che.updateCheltuiala(c);
}

void Service::EliminareCheltuieliAp(int nr_ap) {
	for (int i = 0; i < this->che.n; i++)
		if (this->che.getAll()[i].getnr_ap() == nr_ap)
			this->che.getAll()[i].setsuma(0);
}
void Service::EliminareInterval(int a, int b) {
	for (int i = a; i <= b; i++)
		this->EliminareCheltuieliAp(i);
}
void Service::EliminareTip(char* tip) {
	for (int i = 0; i < this->che.n; i++)
		if (strcmp(this->che.getAll()[i].gettip(),tip) == 0)
			this->che.getAll()[i].setsuma(0);
}
void Service::Inlocuire(int nr_ap, char* tip, int suma) {
	for (int i = 0; i < this->che.n; i++)
		if (strcmp(this->che.getAll()[i].gettip(), tip) == 0 && this->che.getAll()[i].getnr_ap() == nr_ap)
			this->che.getAll()[i].setsuma(suma);
}
Cheltuiala* Service::CheltuieliApartament(int nr_ap) {
	Cheltuiala* c = new Cheltuiala[101];
	int x = 0;
	for (int i = 0; i < this->che.n; i++)
		if (this->che.getAll()[i].getnr_ap() == nr_ap) {
			c[x] = this->che.getAll()[i];
			x++;
		}
	return c;

}
Cheltuiala* Service::CheltuieliMare(int suma) {
	Cheltuiala* c = new Cheltuiala[101];
	int x = 0;
	for (int i = 0; i < this->che.n; i++)
		if (this->che.getAll()[i].getsuma() > suma) {
			c[x] = this->che.getAll()[i];
			x++;
		}
	return c;
}
Cheltuiala* Service::CheltuieliMic(int suma) {
	Cheltuiala* c = new Cheltuiala[101];
	int x = 0;
	for (int i = 0; i < this->che.n; i++)
		if (this->che.getAll()[i].getsuma() < suma) {
			c[x] = this->che.getAll()[i];
			x++;
		}
	return c;
}
Cheltuiala* Service::CheltuieliEgal(int suma) {
	Cheltuiala* c = new Cheltuiala[101];
	int x = 0;
	for (int i = 0; i < this->che.n; i++)
		if (this->che.getAll()[i].getsuma() == suma) {
			c[x] = this->che.getAll()[i];
			x++;
		}
	return c;
}
int Service::SumaTip(char* tip) {
	int suma = 0;
	for (int i = 0; i < this->che.n; i++)
		if (strcmp(this->che.getAll()[i].gettip(), tip) == 0)
			suma += this->che.getAll()[i].getsuma();
	return suma;

}
Cheltuiala Service::MaxAp(int nr_ap) {
	Cheltuiala c;
	int suma = 0;
	for (int i = 0; i < this->che.n; i++)
		if (this->che.getAll()[i].getsuma() > suma) {
			suma = this->che.getAll()[i].getsuma();
			c = this->che.getAll()[i];
		}
	return c;
}
Cheltuiala* Service::SortTip(char* tip) {
	Cheltuiala* c = new Cheltuiala[101];
	int suma = 0,m=0;
	for (int i = 0; i < this->che.n; i++)
		if (strcmp(this->che.getAll()[i].gettip(), tip) == 0)
		{
			c[m] = this->che.getAll()[i];
			m++;
		}
	int ok = 0;
	while (!ok) {
		ok = 1;
		for (int i = 0; i < m; i++)
			if (c[i].getsuma() < c[i + 1].getsuma())
			{
				swap(c[i], c[i + 1]);
				ok = 0;
			}
	}

	return c;
	
}
void Service::FiltruTip(char* tip) {
	for (int i = 0; i < this->che.n; i++)
		if (strcmp(this->che.getAll()[i].gettip(), tip) != 0) this->che.delCheltuiala(this->che.getAll()[i].getid());
	
}
void Service::FiltruSuma(int suma) {
	for (int i = 0; i < this->che.n; i++)
		if(this->che.getAll()[i].getsuma()<=suma) this->che.delCheltuiala(this->che.getAll()[i].getid());
}
int Service::lungime() {
	return this->che.n;
}
Cheltuiala* Service::getall() {
	return this->che.getAll();
}


