#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;
int Easy_Mode = 0;//get more info in the main(); if you wan close it change 8 to 0, open it change 0 to 8,
//default is close,  every hex add use general algorithm
void word(int);
int get_long();//get the array's long

void easy_add_hex(int size);//enter less 8, use easy way to add hex
//start general algorithm for add hex
void add_hex  (char n_a_1[], char n_a_2[],int size);//enter more 8, general algorithm
void get_no(char n_a_1[], char n_a_2[], int size);//get hex
void general_algorithm(int n_1[], int n_2[], int size);//start algorithm
typedef  char* charptr; 
typedef  int* intptr; 
int main()
{
	char one_m='n';
	do
	{
	word(1);
	int size;
	size=get_long();
	charptr No_add_1 =new char[size];//value for user enter number1
	charptr No_add_2 =new char[size];//value for user enter number2
	if(size<Easy_Mode)
		//easy way to add hex.if size less than 8. just add number1 and number2.
		//I am not sure this way whether use the hexadecimal processing tools.
		//if I use hexadecimal processing tools please skip this part
		//change size<8 to size<0, then all algorithm will use general algorithm.
	{
		easy_add_hex(size);
	}
	else
	{
		add_hex(No_add_1,No_add_2,size);
	}
	word(5);
	cin>>one_m;
	cin.ignore(100,'\n');
	delete[] No_add_1 ;
	delete[] No_add_2;
	}while(one_m=='y'||one_m=='Y');
	cout<<"\n";
	word(6);
	return 0;
}
void word(int n)//ok
{
	if(n==1)
	{cout<<"Welcome to c++ hex adder!\n";}
	if(n==2)
	{cout<<"How long are the numbers we are about to add:";}
	if(n==3)
	{cout<<"Number 1 pls: ";}
	if(n==4)
	{cout<<"Number 2 pls: ";}
	if(n==5)
	{cout<<"Do you want to add another two numbers? yes or no: ";}
	if(n==6)
	{cout<<"Bye, lab5 !";}
}
int get_long()//ok
{
	word(2);
	int t;
	cin>>t;
	return t;
}
void easy_add_hex(int size)//easy way to add hex //ok
{
	int t1,t2;
	word(3);
	cin>>hex>>t1;//get hex
	word(4);
	cin>>hex>>t2;//get hex
	
	cout.width(14);//format
	cout<<" "<<hex<<t1<<"\n";
	cout<<setw(14)<<"+"<<hex<<t2<<"\n";
	cout<<"-------------------------\n";
	cout.width(14+size);//format 
	cout<<hex<<t1+t2<<"\n";//just get sum.
}
void add_hex  (char n_a_1[],char n_a_2[], int size)//enter more 8, general algorithm //ok
{
	get_no(n_a_1, n_a_2, size);//ask user enter the data
	intptr hex_1 = new int[size];//for number 1 
	intptr hex_2 = new int[size];//for number 2 
	//get hex by int
	ifstream fiu;
	fiu.open("test1.txt");
	if(fiu.fail())
	{cout<<"error1";}
	for (int i=0;i<size;i++)
	{
		fiu>>hex>>hex_1[i];//get value from file by hex
	}
	fiu.close();
	fiu.open("test2.txt");
	if(fiu.fail())
	{cout<<"error2";}
	for (int i=0;i<size;i++)
	{
		fiu>>hex_2[i];//get value from file by hex
	}
	fiu.close();

//diplay hex_1|hex_2
	cout<<setw(9)<<" ";//format
	for (int i=0;i<size;i++)
	{
		cout<<setiosflags(ios::uppercase)<<hex<<hex_1[i];//user uppercase to diplay letter
	}
	cout<<"\n";
	cout<<setw(9)<<"+";//format
	for (int i=0;i<size;i++)
	{
		cout<<setiosflags(ios::uppercase)<<hex<<hex_2[i];//user uppercase to diplay letter
	}
	cout<<"\n";
	cout<<"-------------------------\n";
//diplay hex_1|hex_2 end
general_algorithm(hex_1, hex_2, size);

delete[] hex_1;
delete[] hex_2;
}
void general_algorithm(int n_1[], int n_2[], int size)//start algorithm
{
	int check_last_one=0;
	intptr n_0 = new int[size+1];
	for(int i=0;i<size;i++)
	{
		n_0[i]=0;//初始化，便于后面加1；
	}
	for(int i=size-1;i>-1;i--)
	{
		n_0[i]=n_0[i]+n_1[i]+n_2[i];//get sum, if last one more than F(15), n_0=1;
		if(n_0[i]>15)//more than F, need add 1 to next.
		{
			if(i==0)// 显示中的第一位（算法中的最后一位），如果大于15，check_last_one=1 显示的时候前面加1
			{
				check_last_one=1;
			}
			else//正常运算
			{
			n_0[i-1]=1;
			}
			n_0[i]=n_0[i]-16;//改变为个位数
		}
		
	}
	if(check_last_one==1)
	{cout<<setw(9)<<"1";}//format and add 1
	else
	{cout<<setw(9)<<" ";}//format
	for(int i=0;i<size;i++)
	{
		cout<<setiosflags(ios::uppercase)<<hex<<n_0[i];
	}
	cout<<"\n";
	delete[] n_0;
}
void get_no(char n_a_1[], char n_a_2[],int size)//get hex
{
	word(3);
	for(int i=0;i<size;i++)
	{
		cin>>n_a_1[i];
		
	}
	word(4);	
		for(int i=0;i<size;i++)
	{
		cin>>n_a_2[i];
	}

//save to file, help void add_hex() to get value. 
		ofstream fou;
		fou.open("test1.txt");
		for(int i=0;i<size;i++)
	{
		fou<<n_a_1[i]<<"\n";		
	}
		fou.close();
		fou.open("test2.txt");
		for(int i=0;i<size;i++)
	{
		fou<<n_a_2[i]<<"\n";		
	}
		fou.close();



	
}