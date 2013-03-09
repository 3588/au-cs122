#include <iostream>
#include <fstream>
#include<stdlib.h>
#include<time.h>
using namespace std;
void Test_put_no(int G_n[], int size);//get test number
void Get_total(int G_n[], int size);//get total
void Get_cheep(int G_n[], int& i);//compare two number
typedef int* INT;
int main()
{
	char one_m='n';
	do
	{
	srand((unsigned) time(NULL));//for test
	cout<<"How long?";
	int size=0;
	cin>>size;
	INT Game_No = new int[size];//gte new size
	Test_put_no(Game_No, size);//get test number
	Get_total(Game_No, size);//get total
	cout<<"\n One more?";
	cin>>one_m;
	}while(one_m=='y');
	
	return 0;
}
void Test_put_no(int G_n[], int size)
{
	G_n[0]=0;//frist number = 0

	ofstream fou;//for test 
	fou.open("test.txt");
	fou<<G_n[0]<<"\n";//frist number = 0
	for(int i=0;i<size-1;i++)//put test number
	{
		int a;
		a=rand()%99+1;
		fou<<a<<"\n";
	}
	fou.close();
	ifstream fin;//for test
	fin.open("test.txt");
	if(fin.fail())
	{cout<<"error 1\n";}
	for(int i=0;i<size;i++)//get test number
	{
		fin>>G_n[i];
	}
	fin.close();
}
void Get_total(int G_n[], int size)
{
	for(int i=0;i<size;i++)//get test number
	{
		cout<<G_n[i]<<"\n";
	}

    G_n[size]=100;//和最后一个数字做比较.防止忽略最后一个数字
	int total=0;
	int i=0;
	do
	{
	total=total+G_n[i];
	//test
	//cout<<"test total: "<<total<<"\n";
	Get_cheep(G_n,i);
	//test
	//cout<<"test i: "<<i<<"\n";
	
	}while(i<size);
	cout<<total;
}

void Get_cheep(int G_n[], int& i)//compare two number
{

	if(G_n[i+1]<G_n[i+2])
	{i=i+1;}//adjacent < jump over the adjacent. i move to adjacent
	else
	{i=i+2;}// jump over the adjacent  < adjacent. i move to  jump over the adjacent 
}