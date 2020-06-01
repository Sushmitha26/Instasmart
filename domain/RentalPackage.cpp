#include<iostream>
#include<list>
#include<string>
#pragma once
#include "Product.cpp"

using namespace std;
class RentalPackage {
    private:
    int id;
    string name;
    list<Product> productList; 
    int rate;
    string isAvailable;
    public:
    int getId() {
        return id;
    }
    string getName() {
    	return name;
	}
	int getRate() {
		return rate;
	}
	string getIsAvailable() {
		return isAvailable;
	}
	list<Product> getProductList() {
		return productList;
	}
	void setId(int id) {
		this->id = id;
	}
	void setName(string name) {
		this->name = name;
	}
	void setRate(int rate) {
		this->rate = rate;
	}
	void setIsAvailable(string isAvailable) {
		this->isAvailable = isAvailable;
	}
	void setProductList(list<Product> productList) {
		this->productList = productList;
	}
};
