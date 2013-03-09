#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>
void  get_from_key_or_file(int[]);//1=key, 2=file
void get_from_key(int[], int[]);//input from keyboard 
void get_from_file(int[], int[]);//input from file 
void max_2_min(int[], int []);//list number, max to min.
void get_same_no(int[],int[],int[],int[]);//1_in,2_new_n,3_int,4_count
void out_no(int[],int[],int[]);
using namespace std;
int main()
	{
	int conf_int[10];
	//conf_int[0] = from_key_or_file
	//conf_int[1] = number for input
	//conf_int[2] = number of same number
	//conf_int[3] for array_new_n[]
	get_from_key_or_file(conf_int);
	int array_in[50], array_new_n[50], array_count[50];
	if(conf_int[0]==1)//from keyboard
		{
		get_from_key(array_in, conf_int);
		}
	else//from file
		{
		get_from_file(array_in, conf_int);
		}
	//start hard work
	max_2_min(array_in,conf_int);
	get_same_no(array_in,array_new_n,conf_int,array_count);
	out_no(array_new_n,conf_int,array_count);		
	return 0;
	}
void get_from_key_or_file(int conf_int[])//1=key, 2=file//ok
	{
	conf_int[0]=0;
	do{
	cout<<"Please choose the array from\n"
		<<"1.Keyboard\n2.File\n";
	cin>>conf_int[0];
		}while(conf_int[0]!=1&&conf_int[0]!=2);
	}
void get_from_key(int array_in[], int conf_int[])//ok
	{
	conf_int[1]=1;
	char get_enter;//get \n
		for (int i=0;i<50;i++)//start get no.
			{			
			cin>>array_in[i];//get no.
			get_enter=cin.get();//change enter 2 \n
			if(get_enter=='\n')//get \n, stop
				{break;}
			conf_int[1]++;//how many input
			}
	}
void get_from_file(int array_in[], int conf_int[])//ok
	{
	conf_int[1]=1;//number for input
	conf_int[9]=0;
	ifstream fin;
	char file_name[100];
	char y_n='y';
	do
	{
	cout<<"Please enter file name: ";
	cin>>file_name;
	cout<<"You enter: "<<file_name<<" it is right?";
	cin>>y_n;
	cin.ignore(200,'\n');
	}while(y_n=='n'||y_n=='N' );
	fin.open(file_name);
	if(fin.fail())
	{cout<<"No file!!!\n";
	exit(1);
	}
	//start read no
	int i=0;
	char get_space;	
	while(!fin.eof())
	{
		fin>>array_in[i];		
		get_space=fin.get();
		if(get_space==' ')
		{
		conf_int[1]++;//how many input
		}
		if(get_space=='\n')
		{
			conf_int[9]++;//check how many \n. skip vertical.
		}
		i++;
	}
	fin.close();
	if(conf_int[9]>1)//skip number is vertical.
	{
	cout<<"Sorry! We can't read this file\n"
		<<"Please check you file\n"
		<<"We only can read the number is  horizontal\n";
	 main();//back to main
	}		
	}
void max_2_min(int array_in[],int conf_int[])//ok
	{
	for (int i=0;i<conf_int[1];i++)
			{
			for (int j=0;j<conf_int[1]-1;j++)
				{
				if(array_in[j]<array_in[j+1])
					{
					int t_1;
					t_1=array_in[j];
					array_in[j]=array_in[j+1];//change value
					array_in[j+1]=t_1;
					}
				}			
			}
}
void get_same_no(int array_in[],int array_new_n[],int conf_int[], int array_count[])//ok
	//conf_int[1] = number for input
	//conf_int[2] = number of same number
{	conf_int[2]=0;
	for (int i=0;i<conf_int[1]-1;i++)//get total same no.
		{
		if(array_in[i]==array_in[i+1])
			{	
				conf_int[2]++;				
			}
		}
	//get new N
	conf_int[3]=0;
	conf_int[4]=0;//array_new_n
	conf_int[5]=0;//array_count
	for (int i=0;i<conf_int[1]-1;i++)//test count
		{
		if(array_in[i]==array_in[i+1])
			{
			if(conf_int[3]==0)//first times =
				{
				array_count[conf_int[5]]=2;//frist time find 2 same no.
				array_new_n[conf_int[4]]=array_in[i];//get N
				conf_int[4]++;//same no, get one N, move to next
				conf_int[3]=1;//if find 2 same no. it is second times.
				}
			else//not first times find same no.
				{
				array_count[conf_int[5]]+=1;//find more two same no.
				}
			}	
			else//no. not same.
			{
			if(conf_int[3]==1)//last is same
				{
				conf_int[5]++;
			array_new_n[conf_int[4]]=array_in[i+1];
				conf_int[4]++;
				array_count[i]=1;
				array_count[conf_int[5]]=1;
				 }
			else// frist one is single
				{
			array_new_n[conf_int[4]]=array_in[i];
				conf_int[4]++;
				conf_int[3]=0;//next no back to first times=
				array_count[conf_int[5]]=1;
				conf_int[5]++;
				}
			
			}
		}
		conf_int[1]-=conf_int[2];//change display no.
}
void out_no(int array_new_n[],int conf_int[],int array_count[])
	{
	cout<<"N"<<setw(10)<<"Count\n";
	for (int i=0;i<conf_int[1];i++)
		{
		cout.setf(ios::left);
		cout<<setw(5)<<array_new_n[i];
		cout<<array_count[i]<<"\n";
		}
	}