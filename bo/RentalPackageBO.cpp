#include<iostream>
#include<string>
#include<fstream>
#include<list>
#include<iterator>
#include<cstring>
#include<cstdlib>
#include<array>
#pragma once

#include "../domain/RentalPackage.cpp"
#include "ProductBO.cpp"
using namespace std;
class RentalPackageBO {
    public:
        list<RentalPackage> readPackageDetails(fstream &file)
        {
          string s,*s1,*s2;
          RentalPackage rp;
          ProductBO pbo;
          Product p;
          int id,rate;
          list<RentalPackage> rpl;
          list<Product> pl;
          list<Product> pl1;
          fstream f;
          f.open("Product.txt",ios::in);
          pl=pbo.readProductDetails(f);
          int x;
//          while(file)
//          {
//             getline(file,s);
            while(getline(file,s)){
                if(s.compare("")==0){
                    continue;
                }
             s1=splitString1(s);
             //s2=splitString2(s1[2]);
             int j=count(s1[2].begin(),s1[2].end(),'|');
             replace(s1[2].begin(),s1[2].end(),'|',' ');
             int *arr=new int[j+1];
             stringstream ss(s1[2]);
             pl1.clear();
//             size_t j = 0;
//                while (!s2[j].empty())
//                {
//                ++j;
//                }
             for(int i=0;i<=j;i++)
             {
                //sscanf(s2[i].c_str(),"%d",&x);
                //cout<<x;
                ss>>arr[i];
                p=pbo.obtainProductById(pl,arr[i]);
                pl1.push_back(p);
             }
//             sscanf(s1[0].c_str(),"%d",&x);
//             rp.setId(x);
             stringstream ss1(s1[0]);
             ss1>>id;
             rp.setId(id);
             rp.setName(s1[1]);
//             sscanf(s1[3].c_str(),"%d",&x);
//             rp.setRate(x);
             stringstream ss2(s1[3]);
             ss2>>rate;
             rp.setRate(rate);
             if(s1[4]=="true")
             rp.setIsAvailable("true");
             else
             rp.setIsAvailable("false");
             //rp.setIsAvailable(s1[4]);
             rp.setProductList(pl1);
             rpl.push_back(rp);
          }
          f.close();
          return rpl;
        }
        
        string* splitString1(string str)
        {
            string* arr = new string[25];
        	int i=0,s=0;
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
    string* splitString2(string str)
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
    
    void display(list<RentalPackage> pack) {
        //fill your code here
                list<RentalPackage>::iterator i;
        RentalPackage rp; 
        ProductBO pbo;
        //list<Product> prolist;
        printf("%-25s%-25s%-25s\n", "ID","Package","Rate");
        for(i=pack.begin();i!=pack.end();++i)
        {
           rp=*i;
           if(rp.getIsAvailable()=="true")
           {
               printf("%-25d%-25s%-25d\n",rp.getId(),rp.getName().c_str(),rp.getRate());
               //prolist=rp.getProductList();
               pbo.displayProduct(rp.getProductList());
           }
        }
    }
    RentalPackage obtainPackageById(list<RentalPackage> rp,int id){
        //fill your code here
                    list<RentalPackage>::iterator i;
            RentalPackage pr;
            for(i=rp.begin();i!=rp.end();++i)
            {
                //pr=*i;
                //if(id==pr.getId())
                if(i->getId()==id)
                {
                    //return pr;
                    return *i;
                }
            }
            pr.setId(0);
            return pr;
        }
    int calculateCost(list<RentalPackage> rp) {
        //fill your code here
         list<RentalPackage>::iterator i;
        int cost=0;
        for(i=rp.begin();i!=rp.end();++i)
        {
            cost=cost+(i->getRate());
        }  
        return cost;
    }
};
