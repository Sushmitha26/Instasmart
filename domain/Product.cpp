#include<iostream>
#include<string>
#pragma once
using namespace std;
class Product {
    private:
    int id;
    string name;
    string brand;
    string type;
    string isAvailable;
    public:
    int getId() {
        return id;
    }
	string getName() {
		return name;
	}
	string getBrand() {
		return brand;
	}
	string getType() {
		return type;
	}
	string getIsAvailable() {
		return isAvailable;
	}
	void setId(int id) {
		this->id = id;
	}
	void setName(string name) {
		this->name = name;
	}
	void setBrand(string brand) {
		this->brand = brand;
	}
	void setType(string type) {
		this->type = type;
	}
	void setIsAvailable(string isAvailable) {
		this->isAvailable = isAvailable;
	}
};
