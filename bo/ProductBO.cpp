
#include<iostream>
#include<string>
#include<fstream>
#include<list>
#include<iterator>
#include <cstring>
#include <cstdlib>
#pragma once

#include "../domain/Product.cpp"
#include "../domain/RentalPackage.cpp"
using namespace std;
class ProductBO {
    public:
    
        list<Product> readProductDetails(fstream &file)
        {
            string input,*s;//,name,brand,type,avail,*s;
            int id;
            list<Product> productList;
            Product product;
            fstream productFile;
            productFile.open("product.txt",ios::in);
            
            while(getline(productFile,input)){
                if(input.compare("")==0){
                    continue;
                }
                s=splitString(input);
                stringstream ss(s[0]);
                ss>>id;
                product.setId(id);
                product.setName(s[1]);
                product.setBrand(s[2]);
                product.setType(s[3]);
                //cout<<s[4]<<"\n";
                product.setIsAvailable(s[4]);
//                if(s[4]=="true")
//                    product.setIsAvailable("true");
//                else
//                    product.setIsAvailable("false");
                
                productList.push_back(product);
            }
            return productList;
        }
//          //fill your code here
//          string l,*s;
//          list<Product> lp;
//          Product p;
//          int x;
//          while(file)
//          {
//              getline(file,l);
//              s=splitString(l);
//              sscanf(s[0].c_str(),"%d",&x);
//              p.setId(x);
//              p.setName(s[1]);
//              p.setBrand(s[2]);
//              p.setType(s[3]);
//              p.setIsAvailable(s[4]);
//              lp.push_back(p);
//          }
//          return lp;
//        }
        Product obtainProductById(list<Product> p,int id)
        {
            //fill your code here
            list<Product>::iterator i;
            Product pr;
            for(i=p.begin();i!=p.end();++i)
            {
                //pr=*i;
                //if(id==pr.getId())
                if(i->getId()==id)
                {
                    //return pr;
                    return *i;
                }
            }
            pr.setId(-1);
            return pr;
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
    void displayProduct(list<Product> p) {
        //fill your code here
                list<Product>::iterator i;
        Product pr;
        printf("%-15s%-15s%-15s%-15s\n", "ID","Product","Brand","Type");
        for(i=p.begin();i!=p.end();++i)
        {
           pr=*i;
           if(i->getIsAvailable()=="true")
           printf("%-15d%-15s%-15s%-15s\n",pr.getId(),pr.getName().c_str(),pr.getBrand().c_str(),pr.getType().c_str());
        }
    }
    
};










