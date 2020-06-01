#include<iostream>
#include<string>
#pragma once
using namespace std;
class Address {
    int id;
    string street;
    string city;
    string state;
    string country;
    int pincode;
    public:
    int getId() {
        return id;
    }
    string getStreet() {
        return street;
	}
	string getCity() {
		return city;
	}
	string getState() {
		return state;
	}
	string getCountry() {
		return country;
	}
	int getPincode() {
		return pincode;
	}
	void setId(int id) {
		this->id = id;
	}
	void setStreet(string street) {
		this->street = street;
	}
	void setCity(string city) {
		this->city = city;
	}
	void setState(string state) {
		this->state = state;
	}
	void setCountry(string country) {
		this->country = country;
	}
	void setPincode(int pincode) {
		this->pincode = pincode;
	}
};
