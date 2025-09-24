#include "Motorcycle.h"
#include <iostream>

Motorcycle::Motorcycle(string brand, string modell,int yearModell, float mileage,string regnr, int price):Vehicle(brand, modell), yearModell(yearModell), mileage(mileage),regnr(regnr),price(price)
{
}

Motorcycle::~Motorcycle()
{
}


void Motorcycle::setprice(int price)
{
	this->price = price;
}

void Motorcycle::changeprice(int newPrice)
{
	this->price = newPrice;
}

int Motorcycle::getprice() const
{
	return this->price;
}

float Motorcycle::getMileage() const
{
	return this->mileage;
}

int Motorcycle::GetyearModell() const
{
	return this->yearModell;
}

string Motorcycle::Getregnr() const
{
	return this->regnr;
}


string Motorcycle::Display() const 
{
	return " Motorcycle info: " + Vehicle::Display() +  " Yearmodell: " + to_string(this->yearModell) + " Mileage: " + to_string(this->mileage) +  " Regnumber: " +regnr + " Price : " + to_string(this->price)+ " SEK";
}

string Motorcycle::Search(string searchItem) const
{
	if (GetBrand() == searchItem || Getmodell() == searchItem || to_string(getMileage()) == searchItem || Getregnr() == searchItem || to_string(this->GetyearModell()) == searchItem || to_string(getprice()) == searchItem)
	{
		
		return Display();
	}
	return "";

	
}

void Motorcycle::writeTofile(ofstream& outfile)
{
	if (outfile.is_open()) {
		outfile << GetBrand() <<" "<< Getmodell() <<" "<< GetyearModell() << " " << getMileage()<<" " << Getregnr() << " " << getprice() << endl;
	}
}




