#ifndef STOCK_H
#define STOCK_H
#include "Vehicle.h"
#include "Motorcycle.h"
#include "Truck.h"
#include "Car.h"
#include "Custommer.h"
#include <fstream>


class Stock
{
private: 
	

	Vehicle** vehicles;
	Custommer** custommers;
	int nrOfCustommers;
	int custommerCapacity;
	int capacity;
	int nrOf;
	void expand();
	void expandCustommers();

	

public:
	Stock(int capacity = 5 , int custommerCapacity = 5);
	~Stock();
	void readFromFile(string filename) ;
	void saveToFile() const;
	void printVehicles() const;
	void printTrucks() const;
	void printCars() const;
	void printMotorcycels() const;
	void CreateCustommer();
	void search( string searchItem) const;
	void order(int custommerID);
	void printCustomerOrders(int custommerID) const;
	void Purshevehicle();
	void printVehiclesForCustomer(int customerID) const;



	

};



#endif 




