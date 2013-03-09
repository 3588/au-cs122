#include <iostream>
#include <string>
#include <iomanip>

void word(int);//1 Welcome.2 model.3 b price.4 s price.
using namespace std;
int main (){
	string model_n[100];
	double price[203];
	//double u_i=0,s_t=0,t_t=0;
	//0-99 base price, 100-199 sale proce,200=u_i,201=s_t,202=t_t.
	price[200]=0;
	price[201]=0;
	price[202]=0;
	word(1);// 1 Welcome
	for (int i = 0; i<100; i++ ){
			cout <<"Car #"<<i+1<<"\n";
			word(2);//2 model.			
			cin >> model_n[i];
			if(model_n[i]=="END"||model_n[i]=="end")//end
			{
				break;
			}
			word(3);//3 b price.
			cin >> price[i];
			word(4);//4sale price.
			cin >> price[100+i];			
			//u_i++;
			price[200]++;
}
	word(5);
for (int i = 0; i<price[200]; i++ ){	
	cout.setf(ios::fixed);
	cout.setf(ios::left);
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout<<setw(22)<<model_n[i];
	//s_t=(price[100+i]-price[i])*0.35;
	price[201]=(price[100+i]-price[i])*0.35;	
	//cout<<"$"<<s_t<<"\n";
	cout<<"$"<<price[201]<<"\n";	
	//t_t=t_t+s_t;
	price[202]=price[202]+price[201];
}
word(6);
cout.setf(ios::fixed);
cout.setf(ios::showpoint);
cout.precision(2);
//cout<<"$"<<t_t;
cout<<"$"<<price[202]<<"\n";
return 0;
}


void word(int n)
	{
	if(n==1)
		{cout<<"Welcome to our commission calculation system(max 100 cars, END ot end the system)\n\n";}
	if(n==2)
		{cout<<"Please input the car model(use _ to replace space in the model name):";}
	if(n==3)
		{cout<<"Please input the base price: $";}
	if(n==4)
		{cout<<"Please input the sale price: $";}
	if(n==5)
		{cout<<"The commissions are the following.\n";}
	if(n==6)
		{cout<<"\n\nThe total commission of this moth is ";}
	}