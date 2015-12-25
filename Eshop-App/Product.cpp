#include "pch.h"
#include "ProductBase.h"


ProductBase::ProductBase(int serial, double price) {
	this->serial = serial;
	this->model = model;
	this->manufacturer = manufacturer;
	this->photoUrl = photoUrl;
	this->description = description;
	this->price = price;
}

int ProductBase::getSerial() {
	return serial;
}

string ProductBase::getModel() {
	return model;
}

string ProductBase::getManufacturer() {
	return manufacturer;
}

string ProductBase::getPhotoUrl() {
	return photoUrl;
}

string ProductBase::getDescription() {
	return description;
}

double ProductBase::getPrice() {
	return price;
}

void ProductBase::setSerial(int serial) {
	this->serial = serial;
}

void ProductBase::setModel(string model) {
	this->model = model;
}

void ProductBase::setManufacturer(string manufacturer) {
	this->manufacturer = manufacturer;
}

void ProductBase::setPhotoUrl(string photoUrl) {
	this->photoUrl = photoUrl;
}

void ProductBase::setDescription(string description) {
	this->description = description;
}

void ProductBase::setPrice(double price) {
	this->price = price;
}

ProductBase::~ProductBase() {
}