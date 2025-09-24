#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H
#include "Vehicle.h"
#include <string>
#include<fstream>
using namespace std;


class Motorcycle:public Vehicle
{

private:

	float mileage;
	int yearModell;
	int price;
	string regnr;

public:
	Motorcycle(string brand, string modell, int yearModell, float mileage, string regnr, int price);
	virtual ~Motorcycle();
	void setprice(int price);
	void changeprice(int newPrice);
	int getprice() const;
	float getMileage() const;
	int GetyearModell() const;
	string Getregnr() const;
	string Display() const override;
	string Search(string searchItem) const override;
	void writeTofile(ofstream& outfile) override;




};






#endif