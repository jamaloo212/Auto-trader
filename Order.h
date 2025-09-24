#ifndef ORDER_H
#define ORDER_H
#include <string>
#include <fstream>
using namespace std;



class Order
{
private:
	string vehicletype;
	string Brand;
	string modell;
	int yearmodell;


public:
	Order(string vehicletype, string Brand, string modell, int yearmodell);
	~Order();
	string to_string() const;
	void writeToFile(const string filename);



};



#endif 
