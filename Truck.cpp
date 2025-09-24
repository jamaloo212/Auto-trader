#include "Truck.h"
#include <iostream>


Truck::Truck(string brand, string modell, int capacity, int weight,string regnr, int price): Vehicle(brand, modell), capacity(capacity), weight(weight),regnr(regnr),price(price)
{
}


Truck::~Truck()
{
}


void Truck::setprice(int price)
{
	this->price = price;
}

void Truck::changeprice(int newPrice)
{
	this->price = newPrice;
}

int Truck::GetCapacity() const
{
	return this->capacity;
}

int Truck::getWeight() const
{
	return this->weight;
}

string Truck::Getregnr() const
{
	return this->regnr;
}


int Truck::GetPrice() const
{
	return this->price;
}


string Truck::Display() const
{
	return  " Truck info: " + Vehicle::Display() + + ", Capacity in L : " + to_string(this->capacity)  + ", Weight in ton: " + to_string(this->weight) +  ", Regnumber: " + regnr + " Price: " + to_string(this->price) + " SEK";
}

string Truck::Search(string searchItem) const
{
	if (GetBrand() == searchItem || Getmodell() == searchItem || to_string(GetCapacity()) == searchItem || to_string(getWeight()) == searchItem || Getregnr() == searchItem || to_string(GetPrice()) == searchItem)
	{
		return Display();
	}
	
	return "";
		
	
}

void Truck::writeTofile(ofstream& outfile)
{
	if (outfile.is_open()) {
		outfile << GetBrand() << " " << Getmodell() <<" " << GetCapacity() <<" " << getWeight() << " " << Getregnr() << " " << GetPrice() << std::endl;
	}
}

