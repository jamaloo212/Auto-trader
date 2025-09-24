#include "Vehicle.h"



Vehicle::Vehicle(string brand, string modell):brand(brand), modell(modell)
{
	
}

Vehicle::~Vehicle()
{
}

void Vehicle::SetBrand(string brand)
{
	this->brand = brand;
}

void Vehicle::seModell(string modell)
{
	this->modell = modell;
}

void Vehicle::change(string newBrand, string newmodell)
{
	this->brand = newBrand;
	this->modell = newmodell;
}



string Vehicle::Getmodell() const
{
	return this->modell;
}

string Vehicle::GetBrand() const
{
	return this->brand;
}



string Vehicle:: Display() const {

	return " Brand: " + this->brand +  " Modell: " + this->modell;
}

