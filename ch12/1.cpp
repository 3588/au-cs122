#include <iostream>
#include "dtim.h"
using namespace std;
int main()
{
	cout << "Test Programming Problem 1" << endl << endl;
	DigitalTime current(5,45), previous(2,30);
	int hours, minutes;
	char ans;
	do 
	{
		//1
		current.interval_since(previous, hours, minutes);
		cout << "The time interval between " << previous<< " and " << current <<"\n"
			<< "is " << hours << " hours and "<< minutes << " minutes \n";
		//2
		cout << "Enter a current time in 24 hour notation  ";
		cin >> current;
		cout<< "Enter a previous time in 24 hour notation ";
		cin >> previous;
		current.interval_since(previous, hours, minutes);
		cout << "The time interval between " << previous<< " and " << current <<"\n"
			<< "is " << hours << " hours and "<< minutes << " minutes \n";
		cout<<"One more y/n";
		cin>>ans;
	} while (ans=='Y'||ans=='y');
	return 0;
}


