#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "p15.h"
using namespace std;
int main()
{
	vector <Voter> main_voter;
	//get list
	ifstream fin;
	fin.open("15.txt");
	if(fin.fail())
	{
		cout<<"error 1";
		exit(1);
	}
	int g_id;
	string g_vote;
	
	while(!fin.eof())
	{
		fin>>g_id;
		fin>>g_vote;
		Voter v1(g_id, g_vote);
		main_voter.push_back(v1);
	}
	
	fin.close();
	//get list end
	int total_v;
	total_v=main_voter.size();

	int count1[9];
	for (int i=0; i<9;i++)
	{
		count1[i]=0;
	}
	for (int i=0; i<total_v; i++)
	{
		Voter v2=main_voter[i];
		for (int j=0; j<4; j++)
		{
			int t1;
			t1=get_count(v2.get_a_vote(j));
			count1[t1]++;
		}
		
	}

	cout << "1. Mayor\n";
	cout << "A. Pincher, Penny: ";
	get_percentage(cout, count1[0], total_v); 
	cout <<"\n";
	cout << "B. Dover, Skip: ";
	get_percentage(cout, count1[1], total_v); 
	cout <<"\n";
	cout << "C. Perman, Sue: ";
	get_percentage(cout, count1[2], total_v); 
	cout <<"\n";
	cout << "2. Proposition 17\n";
	cout << "D. Yes: ";
	get_percentage(cout, count1[3], total_v); 
	cout <<"\n";
	cout << "E. No: ";
	get_percentage(cout, count1[4], total_v); 
	cout <<"\n";

	cout << "3. Measure 1 \n";
	cout << "F. Yes: ";
	get_percentage(cout, count1[5], total_v); 
	cout <<"\n";
	cout << "G. No: ";
	get_percentage(cout, count1[6], total_v); 
	cout <<"\n";

	cout << "4. Measure 2 \n";
	cout << "H. Yes: ";
	get_percentage(cout, count1[7], total_v); 
	cout <<"\n";
	cout << "I. No: ";
	get_percentage(cout, count1[8], total_v); 
	cout <<"\n";

//search
	cout<<"Enter Id";
	int search_id, find1=0;
	cin>>search_id;
	for (int i=0;i<total_v;i++)
	{
		if (main_voter[i].get_id()==search_id)
		{
			Voter t_v=main_voter[i];
			i=total_v;
			find1=1;
			cout<<"Voter: "<<search_id<<" vote: \n";
			cout << " 1. : "<< t_v.get_1() <<"\n";
			cout << " 2. : "<< t_v.get_2() <<"\n";
			cout << " 3. : " << t_v.get_3()<<"\n";
			cout << " 4. : " << t_v.get_4() <<"\n";
		}
	}
	if (find1==0)
	{
		cout<<"Cannot find it.\n";
	}

	return 0;
}
