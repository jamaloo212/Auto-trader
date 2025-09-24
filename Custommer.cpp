#include "Custommer.h"
#include "iostream"



void Custommer::expand()
{
	this->capacity *= 2;
	Vehicle** temp = new Vehicle * [this->capacity]();
	for (int i = 0; i < this->nrOfvehicles; i++)
	{
		temp[i] = this->vehicles[i];
	}
	delete[] this->vehicles;
	this->vehicles = temp;
	
}

Custommer::Custommer(string firstname,string lastname, string tel, int custommerID, int capacity,int nrOfvehicles):firstname(firstname),lastname(lastname),tel(tel),custommerID(custommerID),capacity(capacity),nrOfvehicles(nrOfvehicles)
{
	vehicles = new Vehicle * [capacity]();
}

Custommer::~Custommer()
{
	
	for (int i = 0; i < nrOfvehicles; i++)
    {
        delete this->vehicles[i];  
    }
    delete[] this->vehicles; 

    for (int i = 0; i < orders.size(); i++)
    {
        delete orders[i];
    }

}

void Custommer::ChangeContact(string newTel)
{
	this->tel = newTel;
}

void Custommer::SetCustommerID(int custommerID)
{
	this->custommerID = custommerID;
}

string Custommer::GetName() const
{
	return this->firstname + " " + this->lastname;
}

string Custommer::getTelnr() const
{
	return this->tel;
}
int Custommer::getCustommerID() const
{
	return this->custommerID;
}

int Custommer::getnrOfvehicle() const
{
	return this->nrOfvehicles;
}

int Custommer::getCapacity() const
{
	return this->capacity;
}

string Custommer::to_String() const
{
	return "Name: " + firstname +  " " + lastname +  " Telnr: " + tel + " " + "CustommerID: " + to_string(this->custommerID) + " Garage capacity: " + to_string(this->capacity) + " Number of Vehicles: " + to_string(nrOfvehicles);
}

void Custommer::readFromFile(string filename)
{
	ifstream file(filename);


	if (filename== "Order.txt")
	{
		if (file.is_open()) {
			std::string vehicletype, brand, modell;
			int yearmodell, custommerID;

			while (file >> custommerID >> vehicletype >> brand >> modell >> yearmodell) {
				Order* order = new Order(vehicletype, brand, modell, yearmodell);
				orders.push_back(order);
			}
	}
		else
		{
			if (custommerID == getCustommerID())
			{
			
				if (nrOfvehicles >= capacity)
				{
					expand();
				}
				
			}
		}
	
		file.close();
	}
}

void Custommer::writeToFile(const string filename)
{
	ofstream outFile(filename, ios::app);
	

	outFile << firstname << " " << lastname << " " << tel << " " << custommerID << " " << capacity << " " << nrOfvehicles << endl;

	outFile.close();
}




void Custommer::writeVehicleToFile(Vehicle* vehicle)
{
	std::string filename;

	if (dynamic_cast<Car*>(vehicle)) {
		filename = "PurshedCar.txt";
	}
	else if (dynamic_cast<Motorcycle*>(vehicle)) {
		filename = "PurshedMotorcycle.txt";
	}
	else {
		filename = "PurshedTruck.txt";
	}

	std::ofstream outfile(filename, std::ios::app);

	if (dynamic_cast<Motorcycle*>(vehicle)) {
		Motorcycle* motorcycle = dynamic_cast<Motorcycle*>(vehicle);
		if (motorcycle) {
			outfile << getCustommerID() <<
				" " << motorcycle->GetBrand() << " "
				<< motorcycle->Getmodell() << " "
				<< motorcycle->GetyearModell() << " "
				<< motorcycle->getMileage() << " "
				<< motorcycle->Getregnr() << " "
				<< motorcycle->getprice() << endl;
		}
	}
	else if (dynamic_cast<Truck*>(vehicle)) {
		Truck* truck = dynamic_cast<Truck*>(vehicle);
		if (truck) {
			outfile << getCustommerID() <<
				" " << truck->GetBrand() << " "
				<< truck->Getmodell() << " "
				<< truck->GetCapacity() << " "
				<< truck->getWeight() << " "
				<< truck->Getregnr() << " "
				<< truck->GetPrice() << endl;
		}
	}
	else
	{
		Car* car = dynamic_cast<Car*>(vehicle);

		if (car) {
			outfile << getCustommerID() <<
				" " << car->GetBrand() << " "
				<< car->Getmodell() << " "
				<< car->Getregnr() << " "
				<< car->Getprice() << endl;
		}

	}

}


void Custommer::createContract(Vehicle* vehicle)
{
	
	std::string filename = GetName() +" "+ to_string(getCustommerID())  + "(" + to_string(nrOfvehicles) + ")" + " contract" + ".txt";
	std::ofstream file(filename);
	if (file.is_open()) {
		file << "Customer ID: " << getCustommerID() << endl;
		file << "Name: " << GetName() << endl;
		file << "Telephone: " << getTelnr() << "\n";
		file << "Vehicle: " << vehicle->Display() << "\n";
		file << "---------------------------\n";
		file.close();
	}
}

void Custommer::addVehicle(Vehicle* vehicle)
{
	if (nrOfvehicles >= capacity)
	{
		expand();
	}

	vehicles[nrOfvehicles++] = vehicle;
	createContract(vehicle);
	
	
}

void Custommer::addorder(Order* order)
{
	orders.push_back(order);

}


void Custommer::printOrders() const {
	if (orders.empty()) {
		cout << "No orders found for customer ID: " << custommerID << endl;
		return;
	}

	cout << "Orders for " << GetName() <<" custommer ID " << custommerID << endl;

	for (int i = 0; i < orders.size(); i++)
	{
		cout << orders[i]->to_string() << endl;
	}
}

void Custommer::printVehicles() const
{

	if (vehicles == nullptr) {
		cout << "Vehicles array is null." << endl;
		return;
	}
	for (int i = 0; i < nrOfvehicles; ++i) {
		if (vehicles[i] != nullptr) {
			cout << vehicles[i]->Display() << endl;
		}
	
	}
}


