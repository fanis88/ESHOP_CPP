#pragma once
#include "ProductBase.h"

class TV : public ProductBase {
public:
	TV(int serial, double price);
	double getScreenSize() const;
	bool getCanShow3d() const;
	void setScreenSize(double screenSize);
	void setCanShow3d(bool canShow3d);
private:
	double screenSize;
	bool canShow3d;
};