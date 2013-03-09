//=======================
//ch15 pro4 class
//cs 122 Junjun Huang
//4/18/2011 v1.0
//4/20/2011 12:15 done & test
//=======================
#ifndef CLASS_H
#define CLASS_H
#include <iostream>
#include <string>
using namespace std;
//============
//Person Class
//============
class Person
{
public:
	Person();
	Person (string theName);
	Person (const Person& theObject);
	string get_Name() const;
	Person& operator=(const Person& rtSide);
	friend istream& operator>>(istream& in_Stream,Person& person_Object);
	friend ostream& operator<<(ostream& out_Stream, const Person& person_Object);
private:
	string name;
};
//=============
//Vehicle class
//=============
class Vehicle
{
public:
	Vehicle();
	Vehicle(string m, int cyl, Person p);
	Vehicle(const Vehicle& theObject);
	string get_Manufacturer() const;
	int get_Cylinders() const;
	Person get_Owner() const;
	void set_Manufacturer(string maker);
	void set_Cylinders(int cylinders);
	void set_Owner (Person p);
	Vehicle& operator=(const Vehicle& rtSide);
	friend istream& operator>>(istream& in_Stream,Vehicle& Vehicle_Object);
	friend ostream& operator<<(ostream& out_Stream, const Vehicle& Vehicle_Object);
private:
	string manufacturer;
	int numCylinders;
	Person owner;
};
//===========
//Truck Class 
//===========
class Truck : public Vehicle
{
public:
	Truck();
	Truck(string m, int cyl, Person p, double load, int tow);
	Truck(const Truck& theObject);
	double getload_Capacity() const;
	int gettowing_Capacity() const;
	void setload_Capacity(double newLoad);
	void settowing_Capacity(int newTowing);

	void output();
	Truck& operator=(const Truck& rtSide);
private:
	double load_Capacity;
	int towing_Capacity;
};
//========================
//Person Class Definitions
//========================
Person::Person()
{
}

Person::Person(string theName)
{
	name=theName;
}

Person::Person(const Person& theObject)
{
	name=theObject.name;
}

string Person::get_Name()const
{
	return name;
}
Person& Person::operator=(const Person& rtSide)
{
	name=rtSide.name;
	return *this;
}

istream& operator>>(istream& in_Stream,Person& person_Object)
{
	in_Stream>>person_Object.name;
	return in_Stream;
}

ostream& operator<<(ostream& out_Stream,const Person& person_Object)

{
	out_Stream<<person_Object.name;
	return out_Stream;
}
//========================
//Vehicle Class Definitions
//========================
Vehicle::Vehicle()
{
}
Vehicle::Vehicle (string m, int c, Person p)
{
	manufacturer=m;
	numCylinders=c;
	owner=p;
}
Vehicle::Vehicle(const Vehicle& theObject)
{
	manufacturer = theObject.manufacturer;
	numCylinders = theObject.numCylinders;
	owner = theObject.owner;
}
string Vehicle::get_Manufacturer() const
{
	return manufacturer;
}
int Vehicle::get_Cylinders() const
{
	return numCylinders;
}
Person Vehicle::get_Owner() const
{
	return owner;
}
void Vehicle::set_Manufacturer (string m)
{
	manufacturer = m;
}
void Vehicle::set_Cylinders(int c)
{
	numCylinders = c;
}
void Vehicle::set_Owner(Person p)
{
	owner = p;
}
Vehicle& Vehicle::operator=(const Vehicle& rtSide)
{
	manufacturer = rtSide.manufacturer;
	numCylinders = rtSide.numCylinders;
	owner = rtSide.owner;

	return *this;
}
 istream& operator>>(istream& in_Stream,Vehicle& Vehicle_Object)
{
	in_Stream>>Vehicle_Object.manufacturer>>Vehicle_Object.numCylinders;
	return in_Stream;
}
 ostream& operator<<(ostream& out_Stream, const Vehicle& Vehicle_Object)
{
	out_Stream<<"\nmanufacturer:"<<Vehicle_Object.manufacturer<<"\nnumCylinders"<<Vehicle_Object.numCylinders;
	return out_Stream;
}
//========================
//Vehicle Class Definitions
//========================
Truck::Truck() : Vehicle(), load_Capacity(0), towing_Capacity(0)
{
}

Truck::Truck(string m, int c, Person p, double l, int t)
:Vehicle(m, c, p), load_Capacity(l), towing_Capacity(t)
{
}

Truck::Truck(const Truck& theObject)
{
	
	load_Capacity = theObject.load_Capacity;
	towing_Capacity = theObject.towing_Capacity;
}

double Truck::getload_Capacity()const
{
	return load_Capacity;
}

int Truck::gettowing_Capacity()const
{
	return towing_Capacity;
}

void Truck::setload_Capacity(double newLoad)
{
	load_Capacity=newLoad;
}

void Truck::settowing_Capacity(int newTowing)
{
	towing_Capacity=newTowing;
}

void Truck::output()
{
	cout<<"\nLoad Capacity:"<<load_Capacity;
	cout<<"\nTow Capacity:"<<towing_Capacity<<"\n\n";


}


Truck& Truck::operator=(const Truck& rtSide)
{

	load_Capacity=rtSide.load_Capacity;
	towing_Capacity=rtSide.towing_Capacity;

	return *this;
}
#endif CLASS_H