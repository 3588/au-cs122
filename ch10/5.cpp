#include <iostream>

using namespace std;
class CounterType
{
public:
	CounterType(void)
	{
		counter_0=0;
	}
	CounterType(int a)
	{
		if (a<0)
		{
			cout<<"error 0";
			exit(0);
		}
		counter_0=a;
	}
	void CounterType::counter_increase1_decrease1(int a)
	{
		
			if(counter_0+a<0)
			{
			cout<<"error! the value will become negative!"	;
			}
		else
		{
counter_0+=a;
		}
		
	}
	void CounterType::Output_now_no(ostream& ou)
	{
		ou<<counter_0;
	}
	void CounterType::Output_after_no(ostream& ou)
	{
		ou<<counter_0;
	}

private:
	int counter_0;
};
int main()
{
	CounterType c0;
	c0;//初始化
	CounterType c1;
	int a;
	cin>>a;
	c1=CounterType(a);
	cout<<"Current count value is";
	c1.Output_now_no(cout);cout<<"\n";
	for (int i=1; i<=10;i++)
	{
		c1.counter_increase1_decrease1(1);
	}
	c1.Output_after_no(cout);
}