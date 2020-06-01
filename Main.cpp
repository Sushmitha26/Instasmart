#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include<sstream>
#include <vector>
#include <algorithm>
#include "bo/OrderBO.cpp"
#include "bo/RentalPackageBO.cpp"
#include "bo/UserBO.cpp"
#include "domain/Order.cpp"
//#include "MyException.cpp"


using namespace std;
string *splitString(string str) {
    string *arr = new string[25];
    int i = 0;
    string delimiter = "/";
    size_t pos = 0;
	string token;
	while ((pos = str.find(delimiter)) != string::npos) {
		token = str.substr(0, pos);
		arr[i] = token;
		str.erase(0, pos + delimiter.length());
		i++;
	}
	arr[i] = str;
	return arr;
}
int main() {
	char c, l;
	//MyException myex;
	int choice;
	int pincode;
  	long long contactnumber;
    fstream file;
    fstream outFile;
	fstream wentOut;
	fstream inFile;
	fstream productFile;
	fstream rentalPackageFile;
	fstream orderFile;
	fstream orderOutFile;
	rentalPackageFile.open("rentalpackage.txt",ios::in);
	wentOut.open("address.txt",ios::app);
    outFile.open("user.txt",ios::app);
	inFile.open("user.txt",ios::in);
	productFile.open("product.txt",ios::in);
	orderFile.open("order.txt",ios::in);
	orderOutFile.open("order.txt",ios::app);
    //file.open("user.txt",ios::app);
	string name, username, password, email;
	string street, city, state, country;
    User user;
    UserBO ubo;
    Address address;
    AddressBO add;
	string orderdate;
	string deliveryDate;
	string productIds;
	OrderBO obo;
	Order order;
	RentalPackageBO rbo;
	int *arr,num;
    list<User> userList;
    list<Address> addressList;
	do {
		cout << "Menu:" << endl;
		cout << "1.Sign Up" << endl;
		cout << "2.Login" << endl;
		cout << "Enter your choice" << endl;
		cin >> choice;
        userList = ubo.readUserDetails(inFile);
		list<RentalPackage> rentalPackageList = rbo.readPackageDetails(rentalPackageFile);
      	list<Address> addresslist;
      	list<User> :: iterator it;
		list<Address> :: iterator it1;
      	for(it=userList.begin();it!=userList.end();it++) {
      		addressList.push_back(it->getAddress());
		  }
        cin.ignore();
		if (choice == 1) {
    	      User user;
			UserBO userbo;
			Address a;
			AddressBO addbo;
			list<User> details;
			fstream file;
			file.open("user.txt", ios::in);
			details = userbo.readUserDetails(file);
          //  cout << "No of users in user.txt file :"<<details.size();
			int id = userbo.getUserID(details);
			// file.close();
			id++;
			user.setId(id);
			cout << "Enter the name" << endl;
			cin.ignore();
			getline(cin, name, '\n');
			user.setName(name);
			cout << "Enter the username" << endl;
			cin >> username;
			user.setUsername(username);
			cout << "Enter the password" << endl;
			cin >> password;
			user.setPassword(password);
			cout << "Enter the Email" << endl;
			cin >> email;
			// fstream file1;
			// det=userbo.readUserDetails(file1);
			bool e = userbo.checkEmailExist(details, email);
			// file1.close();
			if (e == true)
				cout << "Already Registered!!!" << endl;
			else {
				user.setEmail(email);
				cout << "Enter the contact number" << endl;
				cin >> contactnumber;
				user.setContactNumber(contactnumber);
				//            cout<<"Enter the rolename";
				//            cin>>rolename;
				user.setRoleName("Customer");
				list<Address> adetails;
				fstream gfile;
				gfile.open("address.txt", ios::in);
				//adetails = addbo.getAddressDetails(gfile);
				int id = addbo.getAddressID(adetails);
				// cout<<id;
				id++;
				gfile.close();
				a.setId(id);
				cout << "Enter the Street" << endl;
				cin >> street;
				a.setStreet(street);
				cout << "Enter the City" << endl;
				cin >> city;
				a.setCity(city);
				cout << "Enter the State" << endl;
				cin >> state;
				a.setState(state);
				cout << "Enter the Country" << endl;
				cin >> country;
				a.setCountry(country);
				cout << "Enter the Pincode" << endl;
				cin >> pincode;
				a.setPincode(pincode);
				user.setAddress(a);
				fstream addfile;
				addfile.open("address.txt", ios::app);
				addbo.addAddressDetails(addfile, a);
				// Address add= getAddressDetails(address);
				fstream file1;
				file1.open("user.txt", ios::app);
				// file1.open ("user.txt",ios::app);
				userbo.addUserDetails(file1, user);
        	cout << "Successfully Registered!!!" << endl;
				file1.close();
				addfile.close();
			}
			file.close();
          
           
		}
		User logUs;
		ProductBO pbo;
		list<Product> productList = pbo.readProductDetails(productFile);
		if (choice == 2) {
			cout << "Enter the username" << endl;
			cin >> username;
			logUs.setUsername(username);
			cout << "Enter the password" << endl;
			cin >> password;
			logUs.setPassword(password);
			// cout << username << "\t" << password << endl;
			logUs = ubo.validateUser(userList,logUs);
            
			if(logUs.getId() == -1) {
				cout << "Invalid username and password" << endl;
			}
			else {
				cout << "Welcome to Instasmart" << endl;
				do {
				cout << "Menu:\n1.View Package\n2.Order Package\n3.My Orders\n4.Cancel Order\n5.Logout" << endl;
				cout << "Enter your choice" << endl;
				cin >> choice;
				switch(choice) {
					case 1:
						cout << "Package Details" << endl;
						rbo.display(rentalPackageList);
						break;
					case 2:
					{
						cout << "Enter Order Date" << endl;
						cin >> orderdate;
						cout << "Available Package Details" << endl;
						//printf("%-25s%-25s%-25s\n", "ID","Package","Rate");
						rbo.display(rentalPackageList);
						cout << "Enter the Package ID's to order (Comma Separated)" << endl;
						cin >> productIds;
						num = count(productIds.begin(),productIds.end(),',');
						arr = new int[num+1];
						replace(productIds.begin(),productIds.end(),',',' ');
						stringstream ss(productIds);
						list<RentalPackage> rp1;
						list<RentalPackage> :: iterator it1;
						for(int i=0;i<=num;i++) {
							ss >> arr[i]; 
							RentalPackage rp2 = rbo.obtainPackageById(rentalPackageList,arr[i]);
							if(rp2.getId() == -1 || rp2.getIsAvailable().compare("false") == 0) {
								cout << "Inavlid choice" << endl;
								break;
							} else {
								rp1.push_back(rp2);
							}
							
						}
						cout << "Enter the delivery date" << endl;
						cin >> deliveryDate;
						list<Order> orderList = obo.readOrderDetails(orderFile);
						int orderId = obo.getOrderID(orderList);
						order.setId(orderId);
						order.setOrderedDate(orderdate);
						order.setDeliveryDate(deliveryDate);
						order.setRentalPackage(rp1);
						user = ubo.obtainUserById(userList,logUs.getId());
						order.setUser(user);
						order.setCost(rbo.calculateCost(rp1));
						replace(orderdate.begin(),orderdate.end(),'/',' ');
						replace(deliveryDate.begin(),deliveryDate.end(),'/',' ');
						stringstream so(orderdate);
						stringstream sd(deliveryDate);
						int ood,oom,ooy,dd,dm,dy;
						so >> ood;
						so >> oom;
						so >> ooy;
						sd >> dd;
						sd >> dm;
						sd >> dy;
						if((dy > ooy) || ((dm > oom) && (dy == ooy)) || ((dd > ood) && (dm == oom) && (dy == ooy))) {
							obo.addOrderDetails(orderOutFile,order);
							cout << "The package has been ordered. Thank You!!!" << endl;
						}
						else {
							cout << "Invalid Delivery Date" << endl;
						}
						break;
					}
            
					case 3:
						{
							list<Order> fullOrderList = obo.readOrderDetails(orderFile);
//							list<Order> orderList;
							list<Order> :: iterator it2;
//							for(it2=fullOrderList.begin();it2!=fullOrderList.end();it2++) {
//								if(logUs.getId() == it2->getUser().getId()) {
//									orderList.push_back(*it2);
//								}
//							}
							if(fullOrderList.empty()){
								cout << "Your Order cart is Empty" << endl;
							} 
                            else {
							printf("%-15s%-15s%-15s%-15s\n", "ID","OrderedDate","DeliveryDate","Cost");
							//cout << logUs.getId() << endl;
//							orderList.clear();
//							for(it2=fullOrderList.begin();it2!=fullOrderList.end();it2++) {
//								if(logUs.getId() == it2->getUser().getId()) {
//									orderList.push_back(*it2);
//								}
//							}
							//obo.display(orderList);
							for(it2=fullOrderList.begin();it2!=fullOrderList.end();it2++) {
								printf("%-15d%-15s%-15s%-15d\n", it2->getId(),it2->getOrderedDate().c_str(),it2->getDeliveryDate().c_str(),it2->getCost());
                                cout << endl << "Packages :" << endl;
								//printf("%-25s%-25s%-25s\n", "ID","Package","Rate");
								rbo.display(it2->getRentalPackage());
							}
							}
							break;
						}
					case 4:
					{
						list<Order> fullOrderList = obo.readOrderDetails(orderFile);
                      
							//list<Order> orderList;
							list<Order> :: iterator it2;
							if(fullOrderList.empty()) {
								cout << "Your Order cart is Empty" << endl;
							} else {
							printf("%-15s%-15s%-15s%-15s\n", "ID","OrderedDate","DeliveryDate","Cost");
							//cout << logUs.getId() << endl;
//							for(it2=fullOrderList.begin();it2!=fullOrderList.end();it2++) {
//								if(logUs.getId() == it2->getUser().getId()) {
//									orderList.push_back(*it2);
//								}
//							}
							//obo.display(orderList);
							for(it2=fullOrderList.begin();it2!=fullOrderList.end();it2++) {
								printf("%-15d%-15s%-15s%-15d\n", it2->getId(),it2->getOrderedDate().c_str(),it2->getDeliveryDate().c_str(),it2->getCost());
								cout << endl << "Packages :" << endl;
								//printf("%-25s%-25s%-25s\n", "ID","Package","Rate");
								rbo.display(it2->getRentalPackage());
							}
							}
							cout << "Enter the Order ID for cancel" << endl;
							int cancelId;
							string cancelDate;
							cin >> cancelId;
							cout << "Enter the date to cancel the order" << endl;
							cin >> cancelDate;
                            cin.ignore();
							//cout << cancelId << "\t" << cancelDate << endl;
							int od,om,oy,cd,cm,cy;
							order = obo.obtainOrderById(fullOrderList,cancelId);
							orderdate = order.getOrderedDate();
							replace(orderdate.begin(),orderdate.end(),'/',' ');
							stringstream sm(orderdate);
							sm >> od;
							sm >> om;
							sm >> oy;
							// cout << od << "\t" << om << "\t" << oy << endl;
							replace(cancelDate.begin(),cancelDate.end(),'/',' ');
							stringstream sc(cancelDate);
							sc >> cd;
							sc >> cm;
							sc >> cy;
							// cout << cd << "\t" << cm << "\t" << cy << endl; 
							if((oy != cy) || (om != cm) || (cd-od > 1) || (cd-od < 0)) {
								obo.what();
                                //myex.what();
							}
							else {
								obo.cancelOrder(fullOrderList,cancelId);
								cout << "Your order has been cancelled" << endl;
							}
							
						break;
					}
					case 5:
					cout << "Thank You" << endl;
						return 0;
					
				}
					cout << "Do you want to go to Menu?(Y/N)" << endl;
					cin >> c;
                    if(c == 'N')
                        return 0;
				}
				while(c != 'N');
			}
//			 list<Product> :: iterator it2;
//			 for(it2=productList.begin();it2!=productList.end();it2++) {
//			 	cout << it2->getId() << "\t" << it2->getName() << "\t" << it2->getBrand() << "\t" << it2->getType() << "\t" << it2->getIsAvailable() << endl;
//			 }
		}
		cout << "Do you want to Continue?(Y/N)" << endl;
		cin >> l;
        if(l == 'N')
            return 0;
	} while (l != 'N');
	return 0;
}











