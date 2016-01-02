#pragma once
#include "Customer.h"

class Person : public Customer
{
public:
	Person(string username, string password);
	string getName();
	string getSurname();
	string getIdentity();
	void setName(string name);
	void setSurname(string surname);
	void setIdentity(string identity);
	Order order();
private:
	string name;
	string surname;
	string identity;
};