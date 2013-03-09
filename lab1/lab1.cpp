#include <iostream>
using namespace std;

void welcome_bye (int);
void s_game();
void user1_2(int&);
void check_12(char, int&);
void p_r_s (char,char,int&);
void win_prs(int);
void one_more(int& t_a)
{
	char t_b;
	do{
		t_a=1;
	cout<<"Do you want to play another game? (y for yes and n for no): ";
	cin>>t_b;
	cin.ignore(200,'\n');
if(t_b=='Y'||t_b=='y'||t_b=='n'||t_b=='N')
{t_a=0;}
	}while(t_a);
	if(t_b=='y'||t_b=='Y')
	{t_a=1;}
	else
	{t_a=0;}
}

int main()
{
	int prs, one_m=0;
	 welcome_bye (1);
	 do{
		 s_game();
		 user1_2(prs);
		 win_prs(prs);
		 one_more(one_m);
	 }while(one_m);
	 welcome_bye (2);
	 
	 return 0;

}
void welcome_bye (int t_a)
{
	if(t_a==1)
	{
		cout<<"Welcome to the Paper-Rock_scissor Game!\n";
	}
	else
	{
		cout<<"\n\nBye\n";
	}
}
void s_game()
{
	cout<<"Please input your choice: P or p for paper; R or r for rock; S or s for scissor\n";
}
void user1_2(int& prs)
{
	int check12=0;
	char chose[2];
	do{
	cout<<"User 1: ";
	cin>>chose[0];
	cin.ignore(200,'\n');
	check_12( chose[0], check12);
	if(check12==1)
	{
		cout<<"Enter an invalid input!!!\n";
	}
	}while(check12);
	do
	{
		cout<<"User 2: ";
	cin>>chose[1];
	cin.ignore(200,'\n');
	check_12( chose[1], check12);
	if(check12==1)
	{
		cout<<"Enter an invalid input!!!\n";
	}
	}while(check12);
 p_r_s (chose[0],chose[1],prs);
	
}
void check_12(char t_chose, int& t_check)
{
	if(t_chose=='P'||t_chose=='p'||t_chose=='R'||t_chose=='r'||t_chose=='S'||t_chose=='s')
	{
		t_check=0;
	}
	else
	{
		t_check=1;
	}
}
void p_r_s (char t_chose1, char t_chose2, int& prs)
{
	//test
	//cout<<"test: "<<t_chose1<<" "<<t_chose2;
	if(t_chose1=='P'||t_chose1=='p')
	{
		if(t_chose2=='R'||t_chose2=='r')
		{
			cout<<"User 1 wins becuase ";
			win_prs(1);
		}
			if(t_chose2=='S'||t_chose2=='s')
		{
			cout<<"User 2 wins becuase ";
			win_prs(3);
		}
		if(t_chose2=='P'||t_chose2=='p')
		{
			win_prs(4);
		}
	}


if(t_chose1=='S'||t_chose1=='s')
	{
		if(t_chose2=='R'||t_chose2=='r')
		{
			cout<<"User 2 wins becuase ";
			win_prs(2);
		}
			if(t_chose2=='S'||t_chose2=='s')
		{
			win_prs(4);
		}
		if(t_chose2=='P'||t_chose2=='p')
		{
			cout<<"User 1 wins becuase ";
			win_prs(3);
		}
	}

if(t_chose1=='R'||t_chose1=='r')
	{
		if(t_chose2=='R'||t_chose2=='r')
		{
			win_prs(4);
		}
			if(t_chose2=='S'||t_chose2=='s')
		{
			cout<<"User 1 wins becuase ";
			win_prs(2);
		}
		if(t_chose2=='P'||t_chose2=='p')
		{
			cout<<"User 2 wins becuase ";
			win_prs(1);
		}
	}

}
void win_prs(int prs)
{
	if(prs==1)
	{cout<<"paper cover the rock!\n";};
	if(prs==2)
	{cout<<"rock breaks scissors!\n";};
	if(prs==3)
	{cout<<"scissors cut paper!\n";};
	if(prs==4)
	{cout<<"nobody wins!\n";};
}
//par1_value in function call =111
//par2_ref in function call = 222
//n1 after function call = 10
//n2 after function call = 222

