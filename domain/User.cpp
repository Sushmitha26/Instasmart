#include<iostream>
#include<string>
using namespace std;
#pragma once
#include "Address.cpp"
class User {
    private:
    int id;
    string name;
    string username;
    string password;
    string email;
    string roleName;
    Address address;
    long contactNumber;
    public:
    Address getAddress() {
        return address;
    }
    void setAddress(Address address) {
        this->address = address;
    }
     int getId() {
            return id;
    	}
		 string getName() {
			return name;
		}
		 string getUsername() {
			return username;
		}
		 string getPassword() {
			return password;
		}
		 string getEmail() {
			return email;
		}
		 long getContactNumber() {
			return contactNumber;
		}
		 string getRoleName() {
			return roleName;
		}
		 void setId(int id) {
			this->id = id;
		}
		 void setName(string name) {
			this->name = name;
		}
		 void setUsername(string username) {
			this->username = username;
		}
		 void setPassword(string password) {
			this->password = password;
		}
		 void setEmail(string email) {
			this->email = email;
		}
		 void setContactNumber(long contactNumber) {
			this->contactNumber = contactNumber;
		}
		 
		 void setRoleName(string roleName) {
			this->roleName = roleName;
		}
		 
};

