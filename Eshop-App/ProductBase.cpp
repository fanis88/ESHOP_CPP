#include "pch.h"
#include "ProductBase.h"

ProductBase::ProductBase() {
}

ProductBase::ProductBase(int serial, double price) {
	this->serial = serial;
	this->price = price;
}

int ProductBase::getSerial() {
	return serial;
}

char* ProductBase::getModel() {
	return model;
}

char* ProductBase::getManufacturer() {
	return manufacturer;
}

char* ProductBase::getPhotoUrl() {
	return photoUrl;
}

char* ProductBase::getDescription() {
	return description;
}

double ProductBase::getPrice() {
	return price;
}

void ProductBase::setSerial(int serial) {
	this->serial = serial;
}

void ProductBase::setModel(char* model) {
	this->model = model;
}

void ProductBase::setManufacturer(char* manufacturer) {
	this->manufacturer = manufacturer;
}

void ProductBase::setPhotoUrl(char* photoUrl) {
	this->photoUrl = photoUrl;
}

void ProductBase::setDescription(char* description) {
	this->description = description;
}

void ProductBase::setPrice(double price) {
	this->price = price;
}

ProductBase::~ProductBase() {
}