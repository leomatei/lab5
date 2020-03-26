#include "Repo.h"
#include <iostream>
#include <string>
using namespace std;

Repo::Repo() {
	this->n = 0;
}
Repo::~Repo() {
	this->n = 0;
}
void Repo::addCheltuiala(Cheltuiala c) {
	this->cheltuieli[this->n++] = c;
}
void Repo::updateCheltuiala(Cheltuiala c) {
	int i = 0;
	while (this->cheltuieli[i].getid() != c.getid())
		i++;
	this->cheltuieli[i] = c;
}
void Repo::delCheltuiala(int id) {
	int i = 0,gasit=0;
	while (gasit == 0 && i < this->n) {
		if (this->cheltuieli[i].getid() == id) gasit = 1;
		i++;
	}
	if (gasit) {
		this->cheltuieli[i - 1] = this->cheltuieli[this->n - 1];
		this->n--;
	}
}
Cheltuiala* Repo::getAll() {
	return this->cheltuieli;
}