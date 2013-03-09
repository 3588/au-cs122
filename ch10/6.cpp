#include <iostream>
#include <cstdlib>
#include <cctype>
using namespace std;
class Month
{
public:
	//start constructors
	Month(int No_2_Month);
	//数字变月份
	//1 for January
  Month(char frist_Letter_1, char frist_Letter_2, char frist_Letter_3);
  //读取月份 
  Month(void)
  {
	  //nothing
  }
  //end constructors  
//start get value
  void Get_No_4_Month(istream&);
  //获得数字,来表示月份
  void Get_Letter_2_No(istream&);
  //获得字母,转换到数字（月份）
//end get value
//output
  void output_No_4_Month(ostream&);
  //用数字来表示月份
  void output_Name_4_Month(ostream&);
  //用字母来表示月份
//end output
private:
  int m;
};
Month::Month(int No_2_Month)//数字变月份
{
	if(No_2_Month>12)
	{
		cout<<"error 1";
		exit(1);	
	}
	else
	{
  m = No_2_Month;
	}
	}
Month::Month(char frist_Letter_1, char frist_Letter_2, char frist_Letter_3)//字母转化为数字
{
	//统一格式
	frist_Letter_1 = tolower(frist_Letter_1);
	frist_Letter_2 = tolower(frist_Letter_2);
	frist_Letter_3 = tolower(frist_Letter_3);
	int check_1=0;
	//Jan 1,Jun 6 ,Jul 7
	if (frist_Letter_1=='j')
	{
		
		if ( frist_Letter_2=='a')
		{
			m=1;//jan
			check_1=1;
		}
		if (frist_Letter_2=='u')
		{
			
			if ( frist_Letter_3=='n')
			{
				m = 6; // jun
				check_1=1;
			}
			if (frist_Letter_3=='l')
			{
				m = 7; // jul
				check_1=1;
			}
		}
	}
		//end Jan 1,Jun 6 ,Jul 7
		//Feb 2
	if (frist_Letter_1=='f')
	{	
		if (frist_Letter_2=='e')
		{
				if (frist_Letter_3=='b')
				{
					m = 2; // feb
					check_1=1;
				}
		}
	}
		//end Feb 2
		//Mar 3, May 5
		if (frist_Letter_1=='m')
		{
		
			if (frist_Letter_2=='a')
			{
				if (frist_Letter_3=='r')
					m = 3; // mar
				check_1=1;
				if(frist_Letter_3=='y')
					m = 5; // may
				check_1=1;
			}
		}
		//end Mar 3, May 5
		//Apr 4, Aug 8
		if (frist_Letter_1=='a')
		{
		
			if (frist_Letter_2=='p')
				if (frist_Letter_3=='r')
					m = 4; // apr
			check_1=1;
			if(frist_Letter_2=='u')
				if (frist_Letter_3=='g')
					m = 8; // aug
			check_1=1;
		}
		//end Apr 4, Aug 8
		//Sep 9
		if(frist_Letter_1=='s')
		{
			if (frist_Letter_2=='e')
			{
				if (frist_Letter_3=='p')
				{
					m = 9; // sep
					check_1=1;
				}
		
			}
		}
		//end Sep 9
		//oct 10
		if (frist_Letter_1=='o')
		{

			if (frist_Letter_2=='c')
				if (frist_Letter_3=='t')
					m = 10; // oct
			check_1=1;
		}
		//end oct 10
		//Nov 11
		if (frist_Letter_1=='n')
		{
			if (frist_Letter_2=='o')
				if (frist_Letter_3=='v')
					m = 11; // nov
			check_1=1;
		}
		//end nov 11
		//dec 12
		if (frist_Letter_1=='d')
		{
			if (frist_Letter_2=='e')
				if (frist_Letter_3=='c')
					m = 12; // dec
			check_1=1;
		}
		//end dec 12
		if (check_1==0)
		{
			cout<<"error 0";
			exit(0);
		}
	}
void Month::Get_No_4_Month(istream& in)
{
	in>>m;
}
void Month::Get_Letter_2_No(istream& in)
{
	char frist_Letter_1, frist_Letter_2, frist_Letter_3;
	in >> frist_Letter_1 >> frist_Letter_2 >> frist_Letter_3;
	//统一格式
	frist_Letter_1 = tolower(frist_Letter_1);
	frist_Letter_2 = tolower(frist_Letter_2);
	frist_Letter_3 = tolower(frist_Letter_3);
	int check_1=0;
	//Jan 1,Jun 6 ,Jul 7
	if (frist_Letter_1=='j')
	{

		if ( frist_Letter_2=='a')
		{
			m=1;//jan
			check_1=1;
		}
		if (frist_Letter_2=='u')
		{

			if ( frist_Letter_3=='n')
			{
				m = 6; // jun
				check_1=1;
			}
			if (frist_Letter_3=='l')
			{
				m = 7; // jul
				check_1=1;
			}
		}
	}
	//end Jan 1,Jun 6 ,Jul 7
	//Feb 2
	if (frist_Letter_1=='f')
	{	
		if (frist_Letter_2=='e')
		{
			if (frist_Letter_3=='b')
			{
				m = 2; // feb
				check_1=1;
			}
		}
	}
	//end Feb 2
	//Mar 3, May 5
	if (frist_Letter_1=='m')
	{

		if (frist_Letter_2=='a')
		{
			if (frist_Letter_3=='r')
				m = 3; // mar
			check_1=1;
			if(frist_Letter_3=='y')
				m = 5; // may
			check_1=1;
		}
	}
	//end Mar 3, May 5
	//Apr 4, Aug 8
	if (frist_Letter_1=='a')
	{

		if (frist_Letter_2=='p')
			if (frist_Letter_3=='r')
				m = 4; // apr
		check_1=1;
		if(frist_Letter_2=='u')
			if (frist_Letter_3=='g')
				m = 8; // aug
		check_1=1;
	}
	//end Apr 4, Aug 8
	//Sep 9
	if(frist_Letter_1=='s')
	{
		if (frist_Letter_2=='e')
		{
			if (frist_Letter_3=='p')
			{
				m = 9; // sep
				check_1=1;
			}

		}
	}
	//end Sep 9
	//oct 10
	if (frist_Letter_1=='o')
	{

		if (frist_Letter_2=='c')
			if (frist_Letter_3=='t')
				m = 10; // oct
		check_1=1;
	}
	//end oct 10
	//Nov 11
	if (frist_Letter_1=='n')
	{
		if (frist_Letter_2=='o')
			if (frist_Letter_3=='v')
				m = 11; // nov
		check_1=1;
	}
	//end nov 11
	//dec 12
	if (frist_Letter_1=='d')
	{
		if (frist_Letter_2=='e')
			if (frist_Letter_3=='c')
				m = 12; // dec
		check_1=1;
	}
	//end dec 12
	if (check_1==0)
	{
		cout<<"error 0";
		exit(0);
	}
	}
void Month::output_No_4_Month(ostream& out)
{
  out<<m;
}
void Month::output_Name_4_Month(ostream& out)
{
  if (m==1) out << "Jan";
 if (m==2) out << "Feb";
 if (m==3) out << "Mar";
 if (m==4) out << "Apr";
 if (m==5) out << "May";
 if (m==6) out << "Jun ";
 if (m==7) out << "Jul ";
 if (m==8) out << "Aug";
 if (m==9) out << "Sep";
 if (m==10) out << "Oct";
 if (m==11) out << "Nov";
 if (m==12) out << "Dec";
}
//end class  

int main()
{
	cout<<"test month(int)\n";//ok
	int i = 1;
	while (i <= 12)
	{
		Month m(i);
		m.output_No_4_Month(cout);
		cout << " ";
		m.output_Name_4_Month(cout);
		cout<<"\n";
		i++;
	}
	cout<<"\n\n\n";
	//首字母
	cout<<"test month(char,char,char)\n";
	Month ml;
	ml = Month( 'j', 'a', 'n');//1
	ml.output_No_4_Month(cout);
	cout << " ";
	ml.output_Name_4_Month(cout);
	cout<<"\n";

	ml = Month( 'f', 'e', 'b');//2
	ml.output_No_4_Month( cout );
	cout << " ";
	ml.output_Name_4_Month(cout); 
	cout<<"\n";
	ml = Month( 'm', 'a', 'r');//3
	ml.output_No_4_Month( cout ); 
	cout << " ";
	ml.output_Name_4_Month(cout);
	cout<<"\n";
	ml = Month( 'a', 'p', 'r');//4
	ml.output_No_4_Month( cout );
	cout << " ";
	ml.output_Name_4_Month(cout);
	cout<<"\n";
	ml = Month( 'm', 'a', 'y');//5
	ml.output_No_4_Month( cout ); cout << " ";
	ml.output_Name_4_Month(cout); cout<<"\n";
	ml = Month( 'j', 'u', 'n');//6
	ml.output_No_4_Month( cout ); cout << " ";
	ml.output_Name_4_Month(cout); cout<<"\n";
	ml = Month( 'j', 'u', 'l');//7
	ml.output_No_4_Month( cout ); cout << " ";
	ml.output_Name_4_Month(cout); cout<<"\n";
	ml = Month( 'a', 'u', 'g');//8
	ml.output_No_4_Month( cout ); cout << " ";
	ml.output_Name_4_Month(cout); cout<<"\n";
	ml = Month( 's', 'e', 'p');//9
	ml.output_No_4_Month( cout ); cout << " ";
	ml.output_Name_4_Month(cout); cout<<"\n";
	ml = Month( 'o', 'c', 't');//10
	ml.output_No_4_Month( cout ); cout << " ";
	ml.output_Name_4_Month(cout); cout<<"\n";
	ml = Month( 'n', 'o', 'v');//11
	ml.output_No_4_Month( cout ); cout << " ";
	ml.output_Name_4_Month(cout); cout<<"\n";
	ml = Month( 'd', 'e', 'c');//12
	ml.output_No_4_Month( cout ); cout << " ";
	ml.output_Name_4_Month(cout); cout<<"\n";

	cout<<"get_no_4_month(cin)\n";
	Month m1;
	m1.Get_No_4_Month(cin);
	m1.output_No_4_Month(cout); cout << " ";
	m1.output_Name_4_Month(cout); cout<<"\n";
		cout<<"get_letter_2_no(cin)\n";
	Month m2;
	m2.Get_Letter_2_No(cin);
	m2.output_No_4_Month(cout);cout << " ";
	m2.output_Name_4_Month(cout); cout<<"\n";
return 0;
}
