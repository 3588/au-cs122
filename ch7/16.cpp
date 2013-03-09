//one question: how to pass no_1[][] to function call? 
//I must put number in second [], I readed 7.4.3 I have to user global value if I want to pass? on the other hand, i did't success when I use the way from 7.4.3.

#include <iostream>
#include <ctime>
#include<iomanip>
#include<cstdlib>
void get_no(int []);

using namespace std;
int main()
	{
	int no_1[4][4];//for layout

	//build table to 0
		for(int i=0;i<4;i++)
		{	
		for(int j=0;j<4;j++)
			{no_1[i][j]=0;}
		no_1[0][0]=8;
	    no_1[2][1]=8;
		}

		//build table end

		//get 1-7
	int no_2[7]={1,2,3,4,5,6,7};
	//get 1-7 
	//change to 0
	int no_3[4][4];
		for(int i=0;i<4;i++)//change to 0
		{	
		for(int j=0;j<4;j++)
			{no_3[i][j]=0;}
		}
		no_3[0][0]=8;
		no_3[2][1]=8;


			
		//change to 0 end

		//get no
		srand((unsigned)time(0));
		int l,r,chekck=7,i=0;
		while(chekck)//第一次填入
			{
			l=rand()%4;
			r=rand()%4;
			//cout<<"1: "<<l<<"\n";
			//cout<<"r: "<<r<<"\n";
			if(no_3[l][r]==0)
				{
				no_3[l][r]=no_2[i];
				//cout<<no_3[l][r]<<"新数值\n";
				chekck--;
				i++;
				}
			else
				{
				//cout<<"再一次";
				}
			}
		chekck=7;
		i=0;
		while(chekck)//第二次填入
			{
			l=rand()%4;
			r=rand()%4;
			//cout<<"1: "<<l<<"\n";
			//cout<<"r: "<<r<<"\n";
			if(no_3[l][r]==0)
				{
				no_3[l][r]=no_2[i];
				//cout<<no_3[l][r]<<"新数值\n";
				chekck--;
				i++;
				}
			else
				{
			//	cout<<"再一次";
				}
			}
			
		//get no end






	//guess
	int pass1=7, check=0;//猜对7次结束.
	do
		{
		//绘图
		cout<<"   1 2 3 4\n";
	cout<<"---------------\n";
	int no_1_1=1;
	for(int i=0;i<4;i++)
		{
		cout<<no_1_1<<" |";
		for(int j=0;j<4;j++)
			{if(no_1[i][j]==0)//如果是空值,变成*
			{cout<<"* ";}
			else
			{cout<<no_1[i][j]<<" ";}//不是空值,显示数字
			}
		no_1_1++;
		cout<<"\n";
		}

	int l1,r1,l2,r2;
	do
	{
	cout<<"Please enter your choose\n"
		<<"List number and Row number:";
	cin>>l1>>r1;
	if(no_1[l1-1][r1-1]!=0)//检查如果已经存在
		{check=1;
	cout<<"error, the number already in table.";
		}
	else
		{no_1[l1-1][r1-1]=no_3[l1-1][r1-1];
	check=0;//通过
		}
	}while(check);

	cout<<"   1 2 3 4\n";
	cout<<"---------------\n";
	no_1_1=1;//初始化第一排
	for(int i=0;i<4;i++)
		{
		cout<<no_1_1<<" |";
		for(int j=0;j<4;j++)
			{if(no_1[i][j]==0)
			{cout<<"* ";}
			else
			{cout<<no_1[i][j]<<" ";}
			}
		no_1_1++;
		cout<<"\n";
		}
	do{
	cout<<"Please enter your guess\n"
		<<"List number and Row number:";
	cin>>l2>>r2;
	if(no_1[l2-1][r2-1]!=0)//检查如果已经存在
		{check=1;
	cout<<"error, the number already in table.";
		}
	else
		{
	if(no_3[l1-1][r1-1]==no_3[l2-1][r2-1])//猜想成立
		{
		no_1[l2-1][r2-1]=no_3[l2-1][r2-1];
		pass1--;
		cout<<"pass it, you need to find "<<pass1<<" more\n";
		}
	else{no_1[l1-1][r1-1]=0;
		cout<<"wrong!! you need to find "<<pass1<<" more\n";}
			}
		}while(check);
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		}while(pass1);
		
		cout<<"you pass the game";
	//test



	



	

	
	
	return 0;
	}
