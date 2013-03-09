#include <iostream>
#include <cstdlib>
using namespace std;

class Odometer//里程表
{
public:
	void reset();
	void Set_Fuel_Efficiency(double New_Fuel_Efficiency);
	void Total_Mile(int Add_mile);
	double Gallons_4_gas();

private:
	int miles;
	double fuel_efficiency;
};
void Odometer::reset()
{
	miles = 0;
	fuel_efficiency=0;
}
void Odometer::Set_Fuel_Efficiency(double New_Fuel_Efficiency)
{
	fuel_efficiency = New_Fuel_Efficiency;
}
void Odometer::Total_Mile(int Add_mile)
{
	miles += Add_mile;
}
double Odometer::Gallons_4_gas()
{
	return (miles / fuel_efficiency);
}
int main()
{
	// Two test trips
	Odometer t1;
	t1.reset();
	t1.Set_Fuel_Efficiency(15);
	t1.Total_Mile(100);
	cout << "After 100 miles, " << t1.Gallons_4_gas() <<" gallons used." << "\n";
	t1.Total_Mile(10);
	cout << "After 10 miles more, " <<t1.Gallons_4_gas() <<" gallons used." << "\n";
	cout << "\n";
	Odometer t2;
	t2.reset();
	t2.Set_Fuel_Efficiency(65);
	t2.Total_Mile(100);
	cout << "After 100 miles, " << t2.Gallons_4_gas() <<" gallons used." << "\n";
	t2.Total_Mile(200);
	cout << "After  200 miles more, " << t2.Gallons_4_gas() <<" gallons used." << "\n";
	return 0;
}
