#pragma once
#include <string>
using namespace std;

class ProductBase
{
public:
	ProductBase();
	ProductBase(int serial, double price);
	int getSerial();
	char* getModel();
	char* getManufacturer();
	char* getPhotoUrl();
	char* getDescription();
	double getPrice();
	void setSerial(int serial);
	void setModel(char* model);
	void setManufacturer(char* manufacturer);
	void setPhotoUrl(char* photoUrl);
	void setDescription(char* description);
	void setPrice(double price);
	virtual ~ProductBase();
protected:
	int serial;
	char* model;
	char* manufacturer;
	char* photoUrl;
	char* description;
	double price;
};

