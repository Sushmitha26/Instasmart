#include<iostream>
#include<string>
#include<fstream>
#include<list>
#include<iterator>
#include <cstring>
#include <cstdlib>
#include<array>
#pragma once

#include "../domain/User.cpp"
#include "../domain/RentalPackage.cpp"
#include "../domain/Order.cpp"
#include "UserBO.cpp"
#include "RentalPackageBO.cpp"
#include "../MyException.cpp"

//using namespace std;
class OrderBO : public MyException {
    
    public:
    void cancelOrder(list<Order> listo, int id)
    {
        fstream outFile;
        outFile.open("order.txt",ios::out);
        list<Order> :: iterator it;
        for(it=listo.begin();it!=listo.end();it++) {
            if(it->getId() == id) {
                break;
            }

        }
        listo.erase(it);
        updateOrderDetails(outFile,listo);
    }
    void updateOrderDetails(fstream &file,list<Order> order)
    {   
         list<Order> :: iterator it;
         for(it=order.begin();it!=order.end();it++) {
             addOrderDetails(file,*it);
         }   
    }
     void addOrderDetails(fstream &file,Order order)
    {   
           fstream file1;
            file1.open("rentalpackage.txt",ios::in);
            RentalPackageBO rbo;
            list<RentalPackage> rp;
            list<RentalPackage> :: iterator it;
            User user;

           user = order.getUser();
           file << order.getId() << ",";
           
           file << user.getId() << ",";
            rp = order.getRentalPackage();
            for(it=rp.begin();it!=rp.end();it++) {
                file << it->getId() << "|";
            }
           file << ",";
           file << order.getOrderedDate() << ",";
           file << order.getDeliveryDate() << ",";
           file << order.getCost() << endl;

    }
            
    list<Order> readOrderDetails(fstream &file)
        {
            fstream orderFile;
            fstream rentalFile;
            fstream userFile;
            Order order;
            list<Order> orderList;
            int id;
            User user;
            UserBO ubo;
            int uid;
            list<RentalPackage> rentalPackage;
            string orderedDate;
            string deliveryDate;
            int cost;
            string packageIds;
            RentalPackageBO rbo;
            list<RentalPackage> rp;
            string input;
            orderFile.open("order.txt",ios::in);
            rentalFile.open("rentalpackage.txt",ios::in);
            userFile.open("user.txt",ios::in);
            list<User> userList = ubo.readUserDetails(userFile);
            rp = rbo.readPackageDetails(rentalFile);
            
            while(getline(orderFile,input)) {
                if(input.compare("") == 0) {
                    continue;
                }
                replace(input.begin(),input.end(),',',' ');
                stringstream ss(input);
                ss >> id;
                ss >> uid;
                ss >> packageIds;
                int num = count(packageIds.begin(),packageIds.end(),'|');
                replace(packageIds.begin(),packageIds.end(),'|',' ');
                int *arr = new int[num];
                stringstream su(packageIds);
                rentalPackage.clear();
                for(int i=0;i<num;i++) {
                    su >> arr[i];
                    RentalPackage rentPack = rbo.obtainPackageById(rp,arr[i]);
                    rentalPackage.push_back(rentPack);
                }
                ss >> orderedDate;
                ss >> deliveryDate;
                ss >> cost;
                order.setId(id);
                user = ubo.obtainUserById(userList,uid);
                order.setUser(user);
                order.setOrderedDate(orderedDate);
                order.setDeliveryDate(deliveryDate);
                order.setCost(cost);
                order.setRentalPackage(rentalPackage);
                orderList.push_back(order);
            }
            return orderList;
           
        }
        string* splitString(string str)
        {
            string* arr = new string[25];
            int i=0;
        	string delimiter = ",";
        	size_t pos = 0;
        	string token;
        	str+=",";
        	while ((pos = str.find(delimiter)) != string::npos) 
        	{
                token = str.substr(0, pos);
                arr[i]=token;
                str.erase(0, pos + delimiter.length());
                i++;
        	}
        return arr; 
    }
    string* splitString1(string str)
        {
            string* arr = new string[25];
            int i=0;
        	string delimiter = "|";
        	size_t pos = 0;
        	string token;
        	str+="|";
        	while ((pos = str.find(delimiter)) != string::npos) 
        	{
                token = str.substr(0, pos);
                arr[i]=token;
                str.erase(0, pos + delimiter.length());
                i++;
        	}
        return arr; 
    }
     void display(list<Order> order) {
         list<Order> :: iterator it;
         it = order.begin();
        for(;it!=order.end();it++) {
            printf("%-15d%-15s%-15s%-15d\n", it->getId(),it->getOrderedDate().c_str(),it->getDeliveryDate().c_str(),it->getCost());
        }
    }
    int getOrderID(list<Order> order) {
        list<Order>::iterator it;
        int id=1;
        for (it = order.begin(); it != order.end(); it++)
        {
            id++;
        }
        return id;
    }
    Order obtainOrderById(list<Order> order,int id) {
       
       Order order1;
       list<Order> :: iterator it;
       for(it=order.begin();it!=order.end();it++) {
           if(it->getId() == id) {
               return *it;
           }
       }
       order1.setId(-1);
       return order1;
    }

    virtual const char* what() const throw(){
        //fill your code here
        try {
            string s = "error";
//            if((oy != cy) || (om != cm) || (cd-od > 1) || (cd-od < 0)) { 
//                throw(s);
//            }
//            else {
//                obo.cancelOrder(fullOrderList,cancelId);
//    		    cout << "Your order has been cancelled" << endl;
//            }
            throw(s);
        } catch(string s) {
            cout << "Order cancelling is valid for one day from ordered date" << endl;
        }
        return "Error";
    }
};
