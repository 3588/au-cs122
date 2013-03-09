#include <iostream>
#include <iomanip>
using namespace std;
void Word (int);

int main()
{
	int tmp_int[100];
	tmp_int[0]=1;//f_seat =1 第一次进入,初始化.=0第二次,跳过初始化
	tmp_int[1]=1;//f_seat =1 第一次获取2,3. =0没有位置
	tmp_int[2]=0;//第一排没满
	tmp_int[3]=0;//第二排没满

	tmp_int[4]=1;//f_seat =1 第一次进入,初始化.=0第二次,跳过初始化
	tmp_int[5]=1;//f_seat =1 第一次获取2,3. =0没有位置
	tmp_int[6]=0;//跳过选位子,自动选择前后|前后位满的时候,用.


	
	//start get seat
	char f_b;//choose f|b seat.
	do
	{
		if(tmp_int[2]==0||tmp_int[3]==0)
			{
			Word(0);
			if(tmp_int[6])//自动调整前后
				{
				tmp_int[6]=0;
				}
			else
				{
		do//check the enter f_b
		{
			Word(1);
			cin>>f_b;
		}while(f_b!='f'&&f_b!='F'&&f_b!='b'&&f_b!='B');
				}
			if(f_b=='f'||f_b=='F')//f_seat
		{
		
	int seat[2][3];
	int choose_r_l[4];
	int r_l[2];
	
	//change value to 0
	if(tmp_int[0])//first time
		{
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<3;j++)
		{
			seat[i][j]=0;
		}
	}
		}

	choose_r_l[0]=1;
	choose_r_l[1]=1;
	choose_r_l[2]=0;//行数控制
	
	
		for(int i=choose_r_l[2];i<choose_r_l[0];i++)
	{
		for(int j=0;j<choose_r_l[1];j++)
		{
			if(seat[i][j]==0)
			{

				seat[i][j]=1;
				r_l[0]=i+1;
				r_l[1]=j+1;
				choose_r_l[2]=9;			
				choose_r_l[1]++;
				break;
			}
			else
			{
				if(choose_r_l[1]==3)
				{
					choose_r_l[0]=2;//开始第二行
					choose_r_l[2]=1;//开始第二行
					choose_r_l[1]=1;//初始化到第一列
				}
				else
				{
					choose_r_l[1]++;//加一列
				}
			}
			
		}
	}
		
		if(r_l[0]==2&&r_l[1]==3)
			{
			if(tmp_int[1])
				{
				tmp_int[1]=0;//第二次
				Word(2);
				cout.setf(ios::left);
			cout<<setw(22)<<"Section:";
			cout<<"front"<<"\n";
			cout<<setw(22)<<"Row number::";
			cout<<r_l[0]<<"\n";
			cout<<setw(22)<<"Seat number:";
			cout<<r_l[1]<<"\n";
			Word(3);
				}
			else//第一排满了
				{
				tmp_int[2]=1;
				Word(4);
				char t_1;//get Y or N
				cin>>t_1;
				if(t_1=='y'||t_1=='Y')
				{
				f_b='b';//选后座
				tmp_int[6]=1;//跳过要求用户输入,直接进入选择
				}
				else//不要选
					{
					Word(5);
					}
				} 
			
			tmp_int[1]=0;
			}
		else//选座成功
			{
			Word(2);
			cout.setf(ios::left);
			cout<<setw(22)<<"Section:";
			cout<<"front"<<"\n";
			cout<<setw(22)<<"Row number::";
			cout<<r_l[0]<<"\n";
			cout<<setw(22)<<"Seat number:";
			cout<<r_l[1]<<"\n";
			Word(3);
			}
	tmp_int[0]=0;
		}
		else//b_seat
		{

	int seat_2[2][3];
	int choose_r_l_2[4];
	int r_l_2[2];
	
	//change value to 0
	if(tmp_int[4])//first time
		{
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<3;j++)
		{
			seat_2[i][j]=0;
		}
	}
		}

	choose_r_l_2[0]=1;
	choose_r_l_2[1]=1;
	choose_r_l_2[2]=0;//行数控制
	
	
		for(int i=choose_r_l_2[2];i<choose_r_l_2[0];i++)
	{
		for(int j=0;j<choose_r_l_2[1];j++)
		{
			if(seat_2[i][j]==0)
			{

				seat_2[i][j]=1;
				r_l_2[0]=i+2;
				r_l_2[1]=j+1;
				choose_r_l_2[2]=9;
			
				choose_r_l_2[1]++;
				break;
			}
			else
			{
				if(choose_r_l_2[1]==3)
				{
					choose_r_l_2[0]=2;//开始第二行
					choose_r_l_2[2]=1;//开始第二行
					choose_r_l_2[1]=1;//初始化到第一列
				}
				else
				{
					choose_r_l_2[1]++;//加一列
				}
			}
			
		}
	}
		
		if(r_l_2[0]==3&&r_l_2[1]==3)
			{
			if(tmp_int[5])
				{
				tmp_int[5]=0;//第二次
				Word(2);
				cout.setf(ios::left);
			cout<<setw(22)<<"Section:";
			cout<<"back"<<"\n";
			cout<<setw(22)<<"Row number::";
			cout<<r_l_2[0]<<"\n";
			cout<<setw(22)<<"Seat number:";
			cout<<r_l_2[1]<<"\n";
			Word(3);
				}
			else//第2排满了
				{
				tmp_int[3]=1;
				Word(4);
				char t_1;//get Y or N
				cin>>t_1;
				if(t_1=='y'||t_1=='Y')
				{
				f_b='f';//选f座
				tmp_int[6]=1;//跳过要求用户输入,直接进入选择
				}
				else//不要选
					{
					Word(5);
					}
				} 
			
			tmp_int[5]=0;
			}
		else//选座成功
			{
			Word(2);
			cout.setf(ios::left);
			cout<<setw(22)<<"Section:";
			cout<<"back"<<"\n";
			cout<<setw(22)<<"Row number::";
			cout<<r_l_2[0]<<"\n";
			cout<<setw(22)<<"Seat number:";
			cout<<r_l_2[1]<<"\n";
			Word(3);
			}
	tmp_int[4]=0;
			



		}
}
		else//直接进入|前座满了,选后座.后座满了,选前座.
			{
			//全满
			Word(0);
				do
		{
			Word(1);
			cin>>f_b;
		}while(f_b!='f'&&f_b!='F'&&f_b!='b'&&f_b!='B');//无意义,让程序输出像Sample
		Word(6);
		exit(1);		
			}
	}while(1);
	return 0;
}
void Word (int Word_no)
{
	if(Word_no==0)
	{
		cout<<"Welcome to c++ flight seat assignment interface!\n"
			<<"Plese type f for \"Front\"\n"
			<<"Plese type b for \"back\"\n";
	}
	if(Word_no==1)
	{
		cout<<"Selection: ";
	}
	if(Word_no==2)
	{
		cout<<"Your seat information is the following.\n";
	}
	if(Word_no==3)
	{
		cout<<"Enjoy your flight! Bye!\n\n";
	}
	if(Word_no==4)
	{
		cout<<"Your preferred front section is full. Is the back ok for You? (y for yes and n for no)";
	}
		if(Word_no==5)
	{
		cout<<"Next flight leaves in 3 hours. Please wait for the next flight. Bye!\n";
	}
		if(Word_no==6)
	{
		cout<<"Sorry, the whole plane is full. Next flight leaves in 3 hours. Please wait for the next flight. Bye!\n";
	}
}
