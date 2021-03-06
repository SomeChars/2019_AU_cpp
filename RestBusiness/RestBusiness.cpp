// RestBusiness.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Guest {

private:
	int size;

public:
	Guest(int size = 1) {
		this->size = size;
	}

	int getSize() const {
		return this->size;
	}
};

class Table {

private:
	bool isFree; // занят столик или нет
	int capability;
	int notFreeSeats;
	int freeSeats;
	std::string name;

public:
	Table(int capability, std::string name): name(name), isFree(true) {
		//this->isFree = true;
		this->capability = capability;
		this->notFreeSeats = 0;
		this->freeSeats = this->capability;
		cout << "create table with capacity = " << this->capability << endl;
	}

	bool IsFree() const {
		return this->isFree;
	}

	void sitDown(Guest g) {
		this->isFree = false;
		this->notFreeSeats = g.getSize();
		this->freeSeats = this->capability - g.getSize();
		cout << "table was occupied by group with size = " << g.getSize() << endl;
	}

	void printInfo() {
		std::cout << "name table = " << this->name << ", capability = " << capability <<
			", freeSeats = " << this->freeSeats << std::endl;
	}
};

class RestourantManager {
private:
	std::vector<Table> tables;
	std::vector<Guest> guestQueue;
public:
	RestourantManager(std::vector<Table> tables) {
		this->tables = tables;
	}

	bool onArrive(Guest g) {
		// 1) проверить, что существует столик за который может сесть гость. Если столик не найден - отказ
		// 2) есть ли свободный столик, куда "влезет" гость
			// 2.1) если такой столик найден - сажаем туда гостя
			// 2.2) если столик не найде - добавляем гостя в очередь
		this->guestQueue.push_back(g);
		return false;
	}

	void printInfo() {
		std::cout << ">TABLES" << std::endl;

		std::vector<Table>::iterator it_tbl = this->tables.begin();
		for (; it_tbl != this->tables.end(); it_tbl++) {
			it_tbl->printInfo();
//			(*it_tbl).printInfo();
		}
	}
};

int main()
{
	Table t1(2, "first");
	Table t2(3, "second");
	Table t3(4, "third");

	std::vector<Table> tables = { t1, t2, t3 };
	RestourantManager *rest = new RestourantManager(tables);
	rest->printInfo();

	Guest g1;
	Guest g2(2);

	rest->onArrive(g1);
//	t1.sitDown(g1);

    std::cout << "t1 isFree()=" << t1.IsFree() << std::endl; 
}
