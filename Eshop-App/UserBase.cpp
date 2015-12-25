#include "pch.h"
#include "UserBase.h"


UserBase::UserBase(string username, string password) {
	this->username = username;
	this->password = password;
}

string UserBase::getUsername() const {
	return username;
}

string UserBase::getPassword() const {
	return password;
}

void UserBase::setUsername(string username) {
	this->username = username;
}

void UserBase::setPassword(string password) {
	this->password = password;
}