#include "pch.h"
#include "TV.h"


TV::TV(int serial, double price) : ProductBase(serial, price) {
}

double TV::getScreenSize() const {
	return screenSize;
}

bool TV::getCanShow3d() const {
	return canShow3d;
}

void TV::setScreenSize(double screenSize) {
	this->screenSize = screenSize;
}

void TV::setCanShow3d(bool canShow3d) {
	this->canShow3d = canShow3d;
}
