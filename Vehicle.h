#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>
#include <fstream>

using namespace std;


class Vehicle
{

private:

	string brand;
	string modell;

	


public:

	Vehicle(string brand, string modell);
	virtual ~Vehicle();
	void SetBrand(string brand);
	void seModell(string modell);
	void change(string newBrand, string newmodell);
	string Getmodell() const;
	string GetBrand()const;
	virtual string Display() const = 0;
	virtual string Search(string searchItem) const = 0;
	virtual void writeTofile(ofstream& outfile ) = 0;


};







#endif
