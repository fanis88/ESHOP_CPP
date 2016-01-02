#include "pch.h"
#include "Order.h"

Order::Order(string orderNumber) {
	this->orderNumber = orderNumber;
}

string Order::getOrderNumber() {
	return this->orderNumber;
}

Customer Order::getOrderBuyer() {
	return this->orderBuyer;
}

map<ProductBase, int> Order::getOrderItems() {
	return this->orderItems;
}

double Order::getOrderCost() {
	return this->orderCost;
}

string Order::getOrderStatus() {
	return this->orderStatus;
}

void Order::setOrderNumber(string orderNumber) {
	this->orderNumber = orderNumber;
}

void Order::setOrderBuyer(Customer orderBuyer) {
	this->orderBuyer = orderBuyer;
}

void Order::setOrderItems(map<ProductBase, int> orderItems) {
	this->orderItems = orderItems;
}

void Order::setOrderCost(double orderCost) {
	this->orderCost = orderCost;
}

void Order::setOrderStatus(string orderStatus) {
	this->orderStatus = orderStatus;
}