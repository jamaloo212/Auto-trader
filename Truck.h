#ifndef TRUCK_H
#define TRUCK_H
#include "Vehicle.h"
#include <string>
#include<fstream>
using namespace std;


class Truck: public Vehicle
{



private:
	int capacity;
	int weight;
	int price;
	string regnr;


public:
	Truck(string brand, string modell, int capacity, int weight,string regnr, int price);
	virtual ~Truck();
	void setprice(int price);
	void changeprice(int newPrice);
	int GetCapacity() const;
	int getWeight() const;
	string Getregnr() const;
	int GetPrice() const;
	string Display() const override;
	string Search(string searchItem) const override;
	void writeTofile(ofstream& outfile) override;





};




#endif