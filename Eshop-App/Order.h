#pragma once
#include "ProductBase.h"
#include "Customer.h"

class Order
{
public:
	Order(string orderNumber);
	string getOrderNumber();
	Customer getOrderBuyer();
	map<ProductBase, int> getOrderItems();
	double getOrderCost();
	string getOrderStatus();
	void setOrderNumber(string orderNumber);
	void setOrderBuyer(Customer orderBuyer);
	void setOrderItems(map<ProductBase, int> orderItems);
	void setOrderCost(double orderCost);
	void setOrderStatus(string orderStatus);
private:
	string orderNumber;
	Customer orderBuyer;
	map<ProductBase, int> orderItems;
	double orderCost;
	string orderStatus;
};