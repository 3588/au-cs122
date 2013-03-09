#ifndef P15_h
#define P15_h
//.h
#include <iostream>
#include <fstream>
#include <string>
//#include <vector>
using namespace std;
class Voter
{
public:
	//c
	Voter(int i_d, string a_i);//ok
	Voter()
	{

	}
	int get_id();//ok
	int get_t_vote();//ok
	char get_a_vote(int id1);//ok

	string get_1();//vote for mayor
	string get_2();//proposition
	string get_3();//measure1
	string get_4();//measure2

	//c end
private:
	int id;
	string votes;//0-3
};
Voter::Voter(int i_d, string a_i)
{
	id = i_d;
	votes = a_i;
}
int Voter::get_id()
{
	return id;
}
int Voter::get_t_vote()
{
	//获得长度
	return votes.length();
}
char Voter::get_a_vote(int id1)
{//back abcdefghi
	return votes.at(id1);
}
string Voter::get_1()//vote for mayor
{
	//test
	//cout<<"get_1";
	string mayor;
	char vote_m;
	vote_m=votes.at(0);
	if (vote_m=='A')
	{mayor="Pincher, Penny";}
	else if (vote_m=='B')
	{mayor="Dover, Skip";}
	else if (vote_m=='C')
	{mayor="Perman, Sue";}
	return mayor;
}
string Voter::get_2()//proposition
{
	if (votes.at(1)=='D')
	{return "Yes";} 
	else
	{return "No";}
}
string Voter::get_3()//measure1
{
	if (votes.at(2)=='F')
	{return "Yes";}
	else
	{return "No";}
}
string Voter::get_4()//measure2
{
	if (votes.at(3)=='H')
	{return "Yes";}
	else
	{return "No";}
}
void get_percentage(ostream& out, int No_c, int total)
{
	//no_c/total
	//fix point
	out.setf(ios::fixed);
	out.setf(ios::showpoint);
	out.precision(2);
	double tt;
	//test
	//cout<<"\ntest\n"<<No_c<<"\n"<<total<<"\n";
	tt=(No_c*100/total);
	out<<tt<<"%";
}
int get_count( char Choose1 )
{
	if(Choose1=='A')
		return 0;
	else if (Choose1=='B')
		return 1;
	else if (Choose1=='C')
		return 2;
	else if (Choose1=='D')
		return 3;
	else if (Choose1=='E')
		return 4;
	else if (Choose1=='F')
		return 5;
	else if (Choose1=='G')
		return 6;
	else if (Choose1=='H')
		return 7;
	else if (Choose1=='I')
		return 8;
}
//.h end
#endif