/* This is the solution to lab 2
 Total points: 70
 input part: 20 points
 partially filled array processing: 20 points
 Compute Commission: 20 points
 coding: 10 points
 */

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int SIZE=20;// const for array size. Allow the max size to be 20
int main(){
	string model[SIZE];
	double basePrice[SIZE],salePrice[SIZE],commission[SIZE];
	int i;
	int filledSize;
	double totalCommission=0;
	cout << "Welcome to our commission calculation system!\n";
	for (i=0;i<SIZE;i++){
		cout << "\nCar #"<<i+1<<endl;
		cout << "Please input the car model (use _ to replace space in the model name): ";
		cin>>model[i];
		if(model[i]=="END"){// the end of user input
			filledSize=i;
			break;
		}
		cout << "Please input the base price: $";
		cin>>basePrice[i];
		cout << "Please input the sale price: $";
		cin >>salePrice[i];
	}
	cout << "The commissions are the following.\n";
	cout.setf(ios::showpoint);
	cout.setf(ios::fixed);
	cout.precision(2);
	cout.setf(ios::left);
	for(i=0;i<filledSize;i++){
		commission[i]=(salePrice[i]-basePrice[i])*.35;
		cout <<setw(25)<<model[i]<<" $" <<commission[i]<<endl;
		totalCommission+=commission[i];
	}
	
	cout << "\n\nThe total commission of this month is $"<<totalCommission<<endl;
	return 0;
}
