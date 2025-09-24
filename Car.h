#ifndef CAR_H
#define CAR_H
#include "Vehicle.h"
#include <string>
#include<fstream>
using namespace std;


class Car: public Vehicle
{

private: 
	int price;
	string regnr;

public:
	Car(string brand, string modell,string regnnr , int price);
	virtual ~Car();
	string Display() const override;
	void setprice(int price);
	void changeprice(int newPrice);
	int Getprice() const;
	string Getregnr() const;
	string Search(string searchItem) const override;
	void writeTofile(ofstream& outfile) override;
};





#endif
