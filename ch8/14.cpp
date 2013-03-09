#include <iostream>
#include <fstream>
#include <string>

using namespace std;
void change_2_easy_getA();
void change_2_easy_getB();
string CITY="Palmdale";
int CODE_S=90210,CODE_E=90214;
int main()
	{
		cout<<"A:City is Palmdale\n\n";
	change_2_easy_getA();
		cout<<"B:Zip Code is 90210-90214\n\n";
	change_2_easy_getB();
	return 0;
	}
void change_2_easy_getA()//ok
	{
	ifstream fin;
	fin.open("Addresses.xml");
	string t, name, street, city, state, zip;
	int first_time=2, line_no=1, first_time_city=1;
	while(!fin.eof())
		{
		if(first_time)
			{
			getline(fin,t);
			first_time--;
			}
		else
			{
			if(line_no==1)
				{getline(fin,t);}
			if(line_no==2)
				{getline(fin,name);}
			if(line_no==3)
				{getline(fin,street);}
			if(line_no==4)
				{getline(fin,city);}
			if(line_no==5)
				{getline(fin,state);}
			if(line_no==6)
				{getline(fin,zip);}
			if(line_no==7)
				{getline(fin,t);
				line_no=0;
				}
			line_no++;

			//A
			
			if(city.find(CITY)==12&&line_no==7)
				{
				int n_pos, s_pos, c_pos, st_pos, z_pos;
				int n_pos1, s_pos1, c_pos1, st_pos1, z_pos1;
				n_pos=name.find(">")+1;
				s_pos=street.find(">")+1;
				c_pos=city.find(">")+1;
				st_pos=state.find(">")+1;
				z_pos=zip.find(">")+1;

				n_pos1=name.find("</");
				s_pos1=street.find("</");
				c_pos1=city.find("</");
				st_pos1=state.find("</");
				z_pos1=zip.find("</");
				

	
				string  t_name, t_street, t_city, t_state, t_zip;
				t_name=name.substr(n_pos, n_pos1-n_pos);
				t_street=street.substr(s_pos, s_pos1-s_pos);
				t_city=city.substr(c_pos, c_pos1-c_pos);
				t_state=state.substr(st_pos, st_pos1-st_pos);
				t_zip=zip.substr(z_pos,z_pos1-z_pos);
			
				cout<<t_name<<"\n"<<t_street<<"\n"<<t_city<<" "<<t_state<<" "<<t_zip<<"\n\n";
				city="";				

				}

	
			}
		}


	fin.close();
	
	}


	void change_2_easy_getB()//ok
	{
	ifstream fin;
	fin.open("Addresses.xml");
	string t, name, street, city, state, zip;
	int first_time=2, line_no=1,tt_zip=0;
	while(!fin.eof())
		{
		if(first_time)
			{
			getline(fin,t);
			first_time--;
			}
		else
			{
			if(line_no==1)
				{getline(fin,t);}
			if(line_no==2)
				{getline(fin,name);}
			if(line_no==3)
				{getline(fin,street);}
			if(line_no==4)
				{getline(fin,city);}
			if(line_no==5)
				{getline(fin,state);}
			if(line_no==6)
				{
				getline(fin,zip);

				/*
				用文件来转换数值
				*/
				int s1;
				s1=zip.find(">")+1;
				ofstream fou;
				fou.open("2.txt");
				fou<<zip.substr(s1,5);
				fou.close();
				ifstream fin;
				fin.open("2.txt");
				int tt;
				fin>>tt;
				tt_zip=tt;
				fin.close();
				/*
				用文件来转换数值结束
				*/

				}
			if(line_no==7)
				{getline(fin,t);
				line_no=0;
				}
			line_no++;
		
			for(int i=CODE_S; i<CODE_E+1;i++)
				{
			
			//if(zip.find("90210")==11||zip.find("90211")==11||zip.find("90212")==11||zip.find("90213")==11||zip.find("90214")==11)
				if(tt_zip>CODE_S-1&&tt_zip<CODE_E+1)
					{
				int n_pos, s_pos, c_pos, st_pos, z_pos;
				int n_pos1, s_pos1, c_pos1, st_pos1, z_pos1;
				n_pos=name.find(">")+1;
				s_pos=street.find(">")+1;
				c_pos=city.find(">")+1;
				st_pos=state.find(">")+1;
				z_pos=zip.find(">")+1;

				n_pos1=name.find("</");
				s_pos1=street.find("</");
				c_pos1=city.find("</");
				st_pos1=state.find("</");
				z_pos1=zip.find("</");
				

	
				string  t_name, t_street, t_city, t_state, t_zip;
				t_name=name.substr(n_pos, n_pos1-n_pos);
				t_street=street.substr(s_pos, s_pos1-s_pos);
				t_city=city.substr(c_pos, c_pos1-c_pos);
				t_state=state.substr(st_pos, st_pos1-st_pos);
				t_zip=zip.substr(z_pos,z_pos1-z_pos);
			
				cout<<t_name<<"\n"<<t_street<<"\n"<<t_city<<" "<<t_state<<" "<<t_zip<<"\n\n";
				zip="";
				tt_zip=0;

				}
				}
		
			}
		}


	fin.close();
	
	}