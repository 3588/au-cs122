#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
using namespace std;
class Rational
{
public:
	//constructor
	Rational(int numerator, int denominator);  //get n/d
	Rational(int whole_number);//get n, d=1
	Rational();//n=0,d=1;
	//constructor end

	//operators
	//bool
	friend bool operator ==(const Rational&, const Rational&);
	friend bool operator<(const Rational&, 	const Rational&);
	friend bool operator<=(const Rational&, const Rational&);
	friend bool operator>(const Rational&, 	const Rational&);
	friend bool operator >=(const Rational&, const Rational&);
	//bool end

	//+,-,*,/
	friend Rational operator+(const Rational&, const Rational&);
	friend Rational operator-(const Rational&, const Rational&);
	friend Rational operator*(const Rational&, const Rational&);
	friend Rational operator/(const Rational&, const Rational&);
	//+,-,*,/ end
	
	
	//test	
	friend istream& operator >>(istream&, 	Rational&);
		//重载 >> 输入值
	friend ostream& operator <<(ostream&, const Rational&);
	//重载 << 输出值
	//test end
	//operators end
private:
	int n;
	int d;
};
//class end
//get gcd
int gcd (int x, int y)
{
	int t; 
	//to positive
	x = abs (x);
	y = abs (y);
	/*
	x/y   
	*/
	if (x==y)
	{
		return x;
	}
	if(x>y)  //exchange
	{
		t = x;
		x = y;
		y = t;
	}
	do	{
		t  = y%x;
		y = x;
		x = t;
	}while (t!=0);
	return y;
}

void normalize_gcd_n_d (int& n, int &d)
{
	int temp;
	temp = gcd(n,d);
	n=n/temp;
	d=d/temp;
	//fix negative
	//d<0 or n and b <0
	//4/-8  =  -1/2 
	if((n>0&&d<0)||(n<0&&d<0))//exchange
	{
		n=-n;
		d=-d;
	}
	else
	{
		//d>0 no change
	}
}
//gcd end
//constructor
Rational::Rational(int numerator, int denominator)  //get n/d
{
	//normalize
	normalize_gcd_n_d(numerator, denominator);//fix n and d
	n = numerator;
	d = denominator;
}
Rational::Rational(int whole_number)//get n, d=1
{
	n = whole_number;
	d = 1;
}
Rational::Rational()//n=0,d=1
{
	n=0;
	d=1;
}
//constructor end
//bool
bool operator ==(const Rational& t1, const Rational& t2)
 {
	 return t1.n * t2.d == t1.n * t2.d;
 }
 bool operator<(const Rational& t1, 	const Rational& t2)
 {
	 return t1.n*t2.d < t2.n*t1.d;  //a*d<c*b === a/b < c/d
 }
 bool operator<=(const Rational& t1, const Rational& t2)
 {
	 return t1.n * t2.d <= t2.n * t1.d; 
 }
 bool operator>(const Rational& t1, 	const Rational& t2)
 {
	 return t1.n * t2.d > t2.n * t1.d;
 }
 bool operator >=(const Rational& t1, const Rational& t2)
 {
	 return t1.n * t2.d >= t2.n * t1.d;
 }
//bool end
 //+,-,*,/
 Rational operator+(const Rational& l, const Rational& r)
  {
	  int n = l.n*r.d+r.n*l.d;
	  int d = l.d*r.d;
	  normalize_gcd_n_d(n,d);
	  Rational  back_n_d(n,d);
	  return back_n_d;

  }
 Rational operator-(const Rational& l, const Rational& r) 
  {
	  int n = l.n*r.d-r.n*l.d;
	  int d = l.d*r.d;
	  normalize_gcd_n_d(n,d);
	  Rational   back_n_d(n,d);
	  return back_n_d;
  }
 Rational operator*(const Rational& l, const Rational& r)
  {
	  int n = l.n*r.n;
	  int d = l.d*r.d;
	  normalize_gcd_n_d(n,d);
	  Rational back_n_d(n,d);
	  return back_n_d;
  }
 Rational operator/(const Rational& l, const Rational& r)
  {
	  int n = l.n*r.d;
	  int d = l.d*r.n;
	  normalize_gcd_n_d(n,d);
	  Rational   back_n_d(n,d);
	  return back_n_d;
  }
 //+,-,*,/ end
 //test
istream& operator >> (istream& cin, Rational& t1)
  {
	  char sign1;
	  cin >> t1.n>> sign1 >> t1.d;
	  if (sign1 != '/')
	 {
		  cout<<"error 1";
		  exit (1);
	  }
	  normalize_gcd_n_d(t1.n, t1.d);
	  return cin;
  }
ostream& operator <<(ostream& out,  const Rational& t1)
  {
	  
	  out << t1.n << '/' << t1.d;
	  return out;
  }
//test end

#endif