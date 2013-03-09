//=======================
//ch15 pro4 driver
//cs 122 Junjun Huang
//4/18/2011 v1.0
//4/20/2011 12:15 done & test
//=======================
#include <iostream>
#include <string>
#include "class.h"
using namespace std;
int main()
{
	string manufacturer;
	int num_Cylinders;
	string owner_name;
	double load_Capacity;
	int towing_Capacity;
	cout << "Enter the manufacturer: ";
	cin >> manufacturer;
	cout << "Enter the cylinders: ";
	cin >> num_Cylinders;
	cout << "Enter the owner: ";
	cin >> owner_name;
	cout << "Enter the load capacity: ";
	cin >> load_Capacity;
	cout << "Enter the towing capacity: ";
	cin >> towing_Capacity;


	Truck truck1;
	Person owner1(owner_name);

	truck1.set_Owner(owner1);
	truck1.set_Manufacturer(manufacturer);
	truck1.set_Cylinders(num_Cylinders);
	truck1.setload_Capacity(load_Capacity);
	truck1.settowing_Capacity(towing_Capacity);

	cout<<"\n2\n\n";

	cout << "Enter the manufacturer: ";
	cin >> manufacturer;
	cout << "Enter the cylinders: ";
	cin >> num_Cylinders;
	cout << "Enter the owner: ";
	cin >> owner_name;
	cout << "Enter the load capacity: ";
	cin >> load_Capacity;
	cout << "Enter the towing capacity: ";
	cin >> towing_Capacity;

	Person owner2(owner_name);
	Truck truck2(manufacturer, num_Cylinders, owner2, load_Capacity,
		towing_Capacity);

//=========
//test code
//=========

	cout << "Truck1 ..." << "\n";
	cout << "Manufacturer: " << truck1.get_Manufacturer() << "\n";
	cout << "Number of Cylinders: " << truck1.get_Cylinders() << "\n";
	cout << "Owner: " << truck1.get_Owner() << "\n";	
	cout << "Load Capacity: " << truck1.getload_Capacity() << "\n";
	cout << "Towing Capacity: " << truck1.gettowing_Capacity()<< "\n";
	cout << "\n";

	cout << "Truck2\n";
	cout << "Manufacturer: " << truck2.get_Manufacturer() <<"\n";
	cout << "Number of Cylinders: " << truck2.get_Cylinders() << "\n";
	cout << "Owner: " << truck2.get_Owner() << "\n";	
	cout << "Load Capacity: " << truck2.getload_Capacity() << "\n";
	cout << "Towing Capacity: " << truck2.gettowing_Capacity() << "\n";
	cout << "\n";

	return 0;
}