#include "rational.h"
#include <iostream>
#include <cstdlib>


using namespace std;
int main()
{
	//test
	cout<<"test \n";
	Rational a,b(1),c(1,2),d(15,-32),e(-300,-400);
	cout<<b<<"\n"<<c<<"\n"<<d<<"\n"<<e<<"\n";//ok
	Rational a1,b1(1),c1(1,2),d1(15,-32),e1(-300,-400);
	cout<<c1<<"\n"<<b1<<"\n"<<c1<<"\n";//ok
	//cin>>a;//ok
	cout<< d1 - e1 <<"\n";//ok
	return 0;

}