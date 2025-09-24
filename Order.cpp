#include "Order.h"
#include <iostream>

Order::Order(string vehicletype, string Brand, string modell, int yearmodell):vehicletype(vehicletype),Brand(Brand),modell(modell),yearmodell(yearmodell)
{
}

Order::~Order()
{
}

string Order::to_string() const
{
	return "Vehicletype: " + vehicletype + " Brand: " + Brand + " Modell: " + modell + " Yearmodell: ";
}

void Order::writeToFile(const string filename)
{
	ofstream outFile(filename, ios::app);
	outFile << to_string() << endl;
	outFile.close();
}
