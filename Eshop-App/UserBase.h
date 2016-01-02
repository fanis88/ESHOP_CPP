#pragma once
#include <string>
using namespace std;

class UserBase {
public:
	UserBase();
	UserBase(string username, string password);
	string getUsername() const;
	string getPassword() const;
	void setUsername(string username);
	void setPassword(string password);
private:
	string username;
	string password;
};
