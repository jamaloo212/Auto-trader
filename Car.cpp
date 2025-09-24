#include "Car.h"
#include <iostream>


Car::Car(string brand, string modell, string regnr, int price):Vehicle(brand, modell),regnr(regnr), price(price)
{
}

Car::~Car()
{
}

string Car::Display() const  
{
	return  " Car onfo: " + Vehicle::Display() + " Regnummber: "+ regnr + " Price: "  +to_string(this->price) + " SEK";
}

void Car::setprice(int price)
{
	this->price = price;
}

void Car::changeprice(int newPrice)
{
	this->price = newPrice;
}

int Car::Getprice() const
{
	return this->price;
}

string Car::Getregnr() const
{
	return this->regnr;
}

string Car::Search(string searchItem) const
{
	if (GetBrand() == searchItem || Getmodell() == searchItem || Getregnr() == searchItem || to_string(Getprice()) == searchItem)
	{
	
		return Display();
	}
	return "";
}
void Car::writeTofile(ofstream& outfile) {
	  
	if (outfile.is_open()) {
		outfile << GetBrand() << " " << Getmodell() << " " << Getregnr() << " " << Getprice() << endl;
	}
	
}




