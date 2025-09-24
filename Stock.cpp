#include "Stock.h"
#include <iostream>


using namespace std;
void Stock::expand()
{
    this->capacity *= 2;
    Vehicle** temp = new Vehicle * [this->capacity] {nullptr};
    for (int i = 0; i < this->nrOf; i++)
    {
        temp[i] = this->vehicles[i];
    }
    delete[] this->vehicles;
    this->vehicles = temp;
}

void Stock::expandCustommers()
{
    custommerCapacity *= 2;
    Custommer** temp = new Custommer * [custommerCapacity] {nullptr};
    for (int i = 0; i < nrOfCustommers; i++) {
        temp[i] =this-> custommers[i];
    }
    delete[] this->custommers;
   this-> custommers = temp;
}

Stock::Stock(int capacity, int custommerCapacity) :capacity(capacity), custommerCapacity(custommerCapacity), nrOf(0),nrOfCustommers(0),
    vehicles(new Vehicle* [capacity] {nullptr}),
    custommers(new Custommer* [custommerCapacity] {nullptr}) 
{}

Stock::~Stock()
{
    for (int i = 0; i < nrOf; i++)
    {
        delete this->vehicles[i];
    }
    delete[] this->vehicles;
    for (int i = 0; i < nrOfCustommers; i++)
    {
        delete this->custommers[i];
    }
    
    delete[] this->custommers;
}

void Stock::readFromFile(std::string filename) {
    fstream file(filename);
    string brand, modell, regnumber, vehicletype;
    int price, weight, custommerID, yearModel, capacityTruck;
    float mileage;

    while (file) { 
        Vehicle* newVehicle = nullptr;

        if (filename == "Motorcycle.txt") {
            if (file >> brand >> modell >> yearModel >> mileage >> regnumber >> price) {
                if (nrOf >= capacity) {
                    expand();
                }
                vehicles[nrOf++] = new Motorcycle(brand, modell, yearModel, mileage, regnumber, price);
            }
        }
        else if (filename == "Car.txt") {
            if (file >> brand >> modell >> regnumber >> price) {
                if (nrOf >= capacity) {
                    expand();
                }
                vehicles[nrOf++] = new Car(brand, modell, regnumber, price);
            }
        }
        else if (filename == "Truck.txt") {
            if (file >> brand >> modell >> capacityTruck >> weight >> regnumber >> price) {
                if (nrOf >= capacity) {
                    expand();
                }
                vehicles[nrOf++] = new Truck(brand, modell, capacityTruck, weight, regnumber, price);
            }
        }
        else if (filename == "Order.txt") {
            if (file >> custommerID >> vehicletype >> brand >> modell >> yearModel) {
                Order* order = new Order(vehicletype, brand, modell, yearModel);
                bool custommerfound = false;
                for (int i = 0; i < nrOfCustommers; i++) {
                    if (custommerID == custommers[i]->getCustommerID()) {
                        custommers[i]->addorder(order);
                        custommerfound = true;
                        
                    }
                }
                if (custommerfound == false) {
                    delete order; 
                }  
            }
        }
        else if (filename == "PurshedCar.txt") {
            if (file >> custommerID >> brand >> modell >> regnumber >> price) {
                newVehicle = new Car(brand, modell, regnumber, price);
            }
        }
        else if (filename == "PurshedMotorcycle.txt") {
            if (file >> custommerID >> brand >> modell >> yearModel >> mileage >> regnumber >> price) {
                newVehicle = new Motorcycle(brand, modell, yearModel, mileage, regnumber, price);
            }
        }
        else if (filename == "PurshedTruck.txt") {
            if (file >> custommerID >> brand >> modell >> capacityTruck >> weight >> regnumber >> price) {
                newVehicle = new Truck(brand, modell, capacityTruck, weight, regnumber, price);
            }
        }
        else {
            std::string name, tel, lastname;
            int capacityVehicle, nrOfvehicles;
            if (file >> name >> lastname >> tel >> custommerID >> capacityVehicle >> nrOfvehicles) {
                if (nrOfCustommers >= custommerCapacity) {
                    expandCustommers();
                }
                custommers[nrOfCustommers++] = new Custommer(name, lastname, tel, custommerID, capacityVehicle, nrOfvehicles);
            }
        }

        if (newVehicle) {
            bool customerFound = false;
            for (int i = 0; i < nrOfCustommers; i++) {
                if (custommerID == custommers[i]->getCustommerID()) {
                    custommers[i]->addVehicle(newVehicle);
                    customerFound = true;
                    
                }
            }

            if (customerFound == false) {
                delete newVehicle;
            }

        }

       
    }

    file.close();
}



void Stock::saveToFile() const
{
    std::ofstream carFile("Car.txt");
    std::ofstream motorcycleFile("Motorcycle.txt");
    std::ofstream truckFile("Truck.txt");

    for (int i = 0; i < nrOf; i++) {
        if (vehicles[i]) {
            if (dynamic_cast<Car*>(vehicles[i])) {
                vehicles[i]->writeTofile(carFile);
            }
            else if (dynamic_cast<Motorcycle*>(vehicles[i])) {
                vehicles[i]->writeTofile(motorcycleFile);
            }
            else if (dynamic_cast<Truck*>(vehicles[i])) {
                vehicles[i]->writeTofile(truckFile);
            }
        }
    }
    carFile.close();
    motorcycleFile.close();
    truckFile.close();
}



void Stock::printVehicles() const {
    for (int i = 0; i < nrOf; ++i) {
            cout<< i+1 << ":" << vehicles[i]->Display() << std::endl; 
    }
}

void Stock::printTrucks() const {
    for (int i = 0; i < nrOf; ++i) {
        Truck* truck = dynamic_cast<Truck*>(this->vehicles[i]);
        if (truck != nullptr) {
             cout<<i+1 <<": " << truck->Display() << endl;
        }
    }
}

void Stock::printCars() const {
    for (int i = 0; i < nrOf; i++)
    {
        Car* car = dynamic_cast<Car*>(this->vehicles[i]);
        if (car != nullptr)
        {
            cout <<i+1<<": " << car->Display() << endl;
        }
    }
}

void Stock::printMotorcycels() const
{
    for (int i = 0; i < nrOf; i++)
    {
        Motorcycle* motorcycle = dynamic_cast<Motorcycle*>(this->vehicles[i]);
        if (motorcycle != nullptr)
        {
            cout <<i+1<<": " << motorcycle->Display() << endl;
        }
    }
}

void Stock::CreateCustommer() 
{
    string name, tel, lastname;
    int custommerID;

    cout << "Please enter your name: " << endl;
    cin >> name;
    cout << "Please Enter your lastname: " << endl;
    cin >> lastname;
    cout << "Please Enter your phonenumer: " << endl;
    cin >> tel;
    cout << "Please enter your CustommerId (last 4 digits of your social security number): " << endl;
    cin >> custommerID;
    if (nrOfCustommers >= custommerCapacity) {
        expandCustommers();
    }

    Custommer* newCustommer = new Custommer(name,lastname, tel, custommerID);
    custommers[nrOfCustommers++] = newCustommer;
    newCustommer->writeToFile("custommer.txt");
}

void Stock::search(string searchItem) const
{
    bool didfind = false;
    for (int i = 0; i < nrOf; ++i) {
        string result = vehicles[i]->Search(searchItem);
        if (result != "")
        {
            cout << result << endl;
            didfind = true;
        }
    }
    if (didfind == false) {
        cout << "Nothing found in stock" << endl;
    }
   
}

void Stock::order(int custommerID)
{
    bool custommerfound = false;
    readFromFile("custommer.txt");
    for (int i = 0; i < nrOfCustommers; i++)
    {
        if (custommerID == custommers[i]->getCustommerID())
        {
            custommerfound = true;
            string vehicletype;
            cout << "Please enter the vehicle type: " << endl;
            cin >> vehicletype;
            string brand;
            cout << "Please enter the vehicle brand: " << endl;
            cin >> brand;
            string modell;
            cout << "PLease enter the modell: " << endl;
            cin >> modell;
            int yearmodell;
            cout << "Please enter the yearmodell: ";
            cin >> yearmodell;
            Order* newOrder = new Order(vehicletype, brand, modell, yearmodell);
            custommers[i]->addorder(newOrder);
            ofstream file("Order.txt",ios::app);

            if (file.is_open())
            {
               
                file <<custommerID<<" " <<vehicletype<<" " << " " << brand << " " << modell << " " << yearmodell << endl;
            }
            file.close();
            break;

        }
    }
    if (custommerfound== false)
    {
        cout << "You are not registred as customer in our register. " << endl;
        CreateCustommer();
    }
    
}

void Stock::printCustomerOrders(int custommerID) const {
    for (int i = 0; i < nrOfCustommers; i++) {
        if (custommerID == custommers[i]->getCustommerID()) {
            custommers[i]->printOrders();
            return;
        }
    }
    cout << "Customer with ID " << custommerID << " not found." << endl;
}

void Stock::Purshevehicle()
{
    int customerID;
    std::cout << "Please enter your customer ID: ";
    std::cin >> customerID;

    for (int i = 0; i < nrOfCustommers; ++i) {
        if (custommers[i]->getCustommerID() == customerID) {
            cout << "All available vehicles:\n";
            printVehicles();
            int choice;
            cout << "Please enter the number of the vehicle you want to buy: ";
            cin >> choice;
            if (choice > 0 && choice <= nrOf) {
                custommers[i]->addVehicle(vehicles[choice - 1]);
                custommers[i]->writeVehicleToFile(vehicles[choice - 1]);

                
                for (int j = choice - 1; j < nrOf - 1; ++j) {
                    vehicles[j] = vehicles[j + 1];
                }
                
                --nrOf;
                saveToFile();
                cout << "Your purshe is sucessecfulled and the contract is avaliebel in  text file . " << endl;
                return;
            }
            else {
                std::cout << "Invalid vehicle number." << endl;
                return;
            }
        }
    }
    cout << "You are not a customer. Please become a customer first, then you can buy a vehicle." << endl;
}



void Stock::printVehiclesForCustomer(int customerID) const {


    bool found = false;

    for (int i = 0; i < nrOfCustommers; i++) {

        if (custommers[i] != nullptr && custommers[i]->getCustommerID() == customerID) {
            cout << "Vehicles for customer ID " << customerID << ":" << endl;
            custommers[i]->printVehicles();
            found = true;
        }
    }
}



