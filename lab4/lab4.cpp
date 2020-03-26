#include <iostream>
#include "repo.h"
#include "test.h"
#include "test.cpp"
#include "service.h"
#include "service.cpp"
#include "tranzactie.h"
using namespace std;

int main()
{
	test_repo();
	test_serv();
	cout << "succes!";
	cin.get();
	return 0;
}
