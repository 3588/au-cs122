#include <iostream>

using namespace std;

int Get_chocolate(int dollars, int coupons);
int main(){
	int dollars;
	int chocolate;
	
	cout << "Enter number of dollars you want to spend on chocolate.\n";
	cin >> dollars;
	chocolate =  Get_chocolate(dollars, 0);
	cout << "You can get " << chocolate << " chocolate with $" << dollars << ".\n";
	return 0;
}

int  Get_chocolate(int dollars, int coupons){
	if ((dollars == 0) && (coupons < 6)){
		return 0;
	}
	int chocolate = dollars;
	coupons += chocolate;
	return chocolate +  Get_chocolate(coupons / 6, coupons % 6);
}
