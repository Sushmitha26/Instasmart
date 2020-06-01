#include <cstring>
#include <cstdlib>
#include<iostream>
#include<string>
#include<fstream>
#include<list>
#include<iterator>
#pragma once
#include "../domain/User.cpp"

using namespace std;

class AddressBO
{
    public:
    void addAddressDetails(fstream &file,Address address)
        {   
           //fill your code here
           file<<address.getId()<<","<<address.getStreet()<<","<<address.getCity()<<","<<address.getState()<<","<<address.getCountry()<<","<<address.getPincode();
           
        }
    
       Address readAddressDetails(fstream &file,int id) {
          //fill your code here
          string *s,st;
      Address a;
      while(file)
      {
          getline(file,st);
          s=splitString(st);
          int x,y;
          sscanf(s[0].c_str(),"%d",&x);
          if(x==id)                
          {
            a.setId(id);
            a.setStreet(s[1]);
            a.setCity(s[2]);
            a.setState(s[3]);
            a.setCountry(s[4]);
            sscanf(s[5].c_str(),"%d",&y);
            a.setPincode(y);
            return a;
          }
      }
          
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
        int getAddressID(list<Address> add) {
            list<Address>::iterator it;
            int id=0;
            for (it = add.begin(); it != add.end(); it++)
            {
                id++;
            }
            return id;
        }
};


