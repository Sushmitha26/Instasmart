#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
#include<list>
#include<iterator>
#include<cstring>
#include<cstdlib>
#include<array>
#pragma once

#include "../domain/Address.cpp"
#include "../domain/User.cpp"
#include "AddressBO.cpp"

using namespace std;

class UserBO
{
     public:
        friend class OrderBO;
        void addUserDetails(fstream &file,User user)
        { 
            file<<user.getId()<<","<<user.getName()<<","<<user.getContactNumber()<<","<<user.getUsername()<<","<<user.getPassword()<<"|"<<user.getAddress().getId()<<endl;
        }
    
        list<User> readUserDetails(fstream &file)
        {
             string str,*a,str1,*b; 
               list<User> l;
               User user;
               AddressBO abo;
               fstream f;
               int x;
               long y;
               f.open("address.txt");
               while (file) { 
         
                 getline(file, str);
                 a = splitString2(str);
                 sscanf(a[0].c_str(),"%d",&x);
                 user.setId(x);
                 user.setName(a[1]);
                 user.setUsername(a[2]);
                 user.setPassword(a[3]);
                 user.setEmail(a[4]);
                 user.setRoleName(a[5]);
                 b = splitString1(a[6]);
                 sscanf(b[0].c_str(),"%ld",&y);
                 user.setContactNumber(y);
                 sscanf(b[1].c_str(),"%d",&x);
                 user.setAddress(abo.readAddressDetails(f,x));
                 l.push_back(user);
            
               }
           return l;
           
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
        string* splitString2(string str)
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
    User validateUser(list<User> user,User us) {
       list<User>::iterator it; 
        for(it=user.begin();it!=user.end();++it) 
        {
            if(it->getPassword()==us.getPassword() && it->getUsername()==us.getUsername()) 
              {
                  return *it;
              }
        }
        User u;
        u.setId(-1);
        return u;
    }
    bool checkEmailExist(list<User> user,string email) {
        list<User>::iterator it; 
        for(it = user.begin(); it != user.end(); ++it) 
        {
            if(it->getEmail()==email) 
            return true;
            else 
            return false;    
        }      
    }
    int getUserID(list<User> user) {
        list<User>::iterator it;
        int id=1;
        for (it = user.begin(); it != user.end(); it++)
        {
            id++;
        }
        return id;
    }
    User obtainUserById(list<User> user,int id) {
       list<User>::iterator it;
        for (it = user.begin(); it != user.end(); it++)
        {
            if(it->getId()==id)
               return *it; 
        }
        User u;
        u.setId(-1);
        return u;
    }

};
