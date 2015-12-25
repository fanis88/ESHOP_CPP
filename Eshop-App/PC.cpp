#include "pch.h"
#include "PC.h"

PC::PC(int serial, double price) : ProductBase(serial, price) {
}

int PC::getRam() const {
	return this->ram;
}

double PC::getCpu() const {
	return this->cpu;
}

string PC::getDiskType() const {
	return this->diskType;
}

int PC::getDiskSpace() const {
	return this->diskSpace;
}

string PC::getGpu() const {
	return this->gpu;
}

void PC::setRam(int ram) {
	this->ram = ram;
}

void PC::setCpu(double cpu) {
	this->cpu = cpu;
}

void PC::setDiskType(string diskType) {
	this->diskType = diskType;
}

void PC::setDiskSpace(int diskSpace) {
	this->diskSpace = diskSpace;
}

void PC::setGpu(string gpu) {
	this->gpu = gpu;
}