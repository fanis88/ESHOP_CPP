#pragma once
#include <string>
using namespace std;

class ProductBase
{
public:
	ProductBase(int serial, double price);
	int getSerial();
	string getModel();
	string getManufacturer();
	string getPhotoUrl();
	string getDescription();
	double getPrice();
	void setSerial(int serial);
	void setModel(string model);
	void setManufacturer(string manufacturer);
	void setPhotoUrl(string photoUrl);
	void setDescription(string description);
	void setPrice(double price);
	virtual ~ProductBase();
protected:
	int serial;
	string model;
	string manufacturer;
	string photoUrl;
	string description;
	double price;
};

