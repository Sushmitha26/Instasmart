#include <iostream>
#include <string>
#include <list>
#pragma once
#include "RentalPackage.cpp"

#include "User.cpp"
using namespace std;
class Order {
    int id;
    User user;
    list<RentalPackage> rentalPackage;
    string orderedDate;
    string deliveryDate;
    int cost;
    public:
    int getId() {
        return id;
    }
     int getCost() {
        return cost;
	}
	User getUser() {
		return user;
	}
	string getOrderedDate() {
		return orderedDate;
	}
	string getDeliveryDate() {
		return deliveryDate;
	}
	
	list<RentalPackage> getRentalPackage() {
		return rentalPackage;
	}
	void setId(int id) {
		this->id = id;
	}
    void setCost(int cost) {
    	this->cost = cost;
	}
	void setUser(User user) {
		this->user = user;
	}
	void setOrderedDate(string orderedDate) {
		this->orderedDate = orderedDate;
	}
	void setDeliveryDate(string deliveryDate) {
		this->deliveryDate = deliveryDate;
	}
	
	void setRentalPackage(list<RentalPackage> rentalPackage) {
		this->rentalPackage = rentalPackage;
	}
};
