#ifndef CUSTOMMER_H
#define CUSTOMMER_H

#include <string>
#include <vector>
#include "Vehicle.h"
#include "Order.h"
#include "Motorcycle.h"
#include "Truck.h"
#include "Car.h"
#include <fstream>

using namespace std;

class Custommer
{

private:
	string firstname;
	string lastname;
	string tel;
	int custommerID;
	int capacity;
	int nrOfvehicles;
	Vehicle** vehicles;
	vector <Order*> orders;
	void expand();
	
	

public:

	Custommer(string firstname,string lastname, string tel, int custommerID = 0, int capacity = 2,int nrOfvehicles=0);
	~Custommer();
	void ChangeContact(string newTel);
	void SetCustommerID(int custommerID);
	string GetName() const;
	string getTelnr() const;
	int getCustommerID()const;
	int getnrOfvehicle() const;
	int getCapacity()const;
	string to_String() const;
	void readFromFile(string filename);
	void writeToFile(string filename);
	void writeVehicleToFile(Vehicle* vehicle);
	void createContract(Vehicle *vehicle);
	void addVehicle(Vehicle* vehicle);
	void addorder(Order* order);
	void printOrders() const;
	void printVehicles()const;





};






#endif 
