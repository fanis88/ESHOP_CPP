#pragma once
#include "ProductBase.h"

class PC : public ProductBase {
public:
	PC(int serial, double price);
	int getRam() const;
	double getCpu() const;
	string getDiskType() const;
	int getDiskSpace() const;
	string getGpu() const;
	void setRam(int ram);
	void setCpu(double cpu);
	void setDiskType(string diskType);
	void setDiskSpace(int diskSpace);
	void setGpu(string gpu);
private:
	int ram;
	double cpu;
	string diskType;
	int diskSpace;
	string gpu;
};
