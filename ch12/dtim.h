#ifndef TEST27_H
#define TEST27_H
#include <iostream>
using namespace std;
class DigitalTime{
public:
	friend bool operator ==(const DigitalTime& time1, const DigitalTime& time2);
	DigitalTime(int the_hour, int the_minute);
	DigitalTime( );

	void advance(int minutes_added);
	void advance(int hours_added, int minutes_added);
	friend istream& operator >>(istream& ins, DigitalTime& the_object);
	friend ostream& operator <<(ostream& outs, const DigitalTime& the_object);
	//Pro 1
	void interval_since(const DigitalTime& a_previous_time ,int& hours_in_interval,	int& minutes_in_interval) const;

private:
	int hour;
	int minute;
};
//Pro 1
void DigitalTime::interval_since(const DigitalTime& a_previous_time ,int& hours_in_interval,	int& minutes_in_interval) const
{
	DigitalTime counts;

	counts.hour = hour - a_previous_time.hour;
	counts.minute = minute - a_previous_time.minute;

	if (hour < a_previous_time.hour || 
		hour == a_previous_time.hour && minute < a_previous_time.minute)
	{
		cout << "'Previous' time is in the previous day" 
			<< endl;
		counts.hour = 24 + (hour - a_previous_time.hour);
	}

	if ( counts.minute < 0)
	{
		counts.hour--;
		counts.minute = counts.minute + 60;
	}
	hours_in_interval = counts.hour;
	minutes_in_interval = counts.minute;

}
void read_hour(istream& ins, int& the_hour);
void read_minute(istream& ins, int& the_minute);
int digit_to_int(char c);
bool operator ==(const DigitalTime& time1, const DigitalTime& time2)
{
	return (time1.hour == time2.hour && time1.minute == time2.minute);
}
DigitalTime::DigitalTime(int the_hour, int the_minute){
	if (the_hour < 0 || the_hour > 23 || the_minute < 0 || the_minute > 59)
	{
		cout << "Illegal argument to DigitalTime constructor.";
		exit(1);
	}
	else
	{
		hour = the_hour;
		minute = the_minute;
	}
}
DigitalTime::DigitalTime( ) {
	hour=0;
	minute=0;
}
void DigitalTime::advance(int minutes_added)
{
	int gross_minutes = minute + minutes_added;
	minute = gross_minutes%60;

	int hour_adjustment = gross_minutes/60;
	hour = (hour + hour_adjustment)%24;
}
void DigitalTime::advance(int hours_added, int minutes_added)
{
	hour = (hour + hours_added)%24;
	advance(minutes_added);
}
ostream& operator <<(ostream& outs, const DigitalTime& the_object)
{
	outs << the_object.hour << ':';
	if (the_object.minute < 10)
		outs << '0';
	outs << the_object.minute;
	return outs;
}
istream& operator >>(istream& ins, DigitalTime& the_object)
{
	read_hour(ins, the_object.hour);
	read_minute(ins, the_object.minute);
	return ins;
}

int digit_to_int(char c)
{
	return ( static_cast<int>(c) - static_cast<int>('0') );
}
void read_minute(istream& ins, int& the_minute)
{
	char c1, c2;
	ins >> c1 >> c2;

	if (!(isdigit(c1) && isdigit(c2)))


	{
		cout << "Error illegal input to read_minute\n";
		exit(1);
	}

	the_minute = digit_to_int(c1)*10 + digit_to_int(c2);

	if (the_minute < 0 || the_minute > 59)
	{
		cout << "Error illegal input to read_minute\n";
		exit(1);
	}
}
void read_hour(istream& ins, int& the_hour)
{
	char c1, c2;
	ins >> c1 >> c2;
	if ( !( isdigit(c1) && (isdigit(c2) || c2 == ':' ) ) )
	{
		cout << "Error illegal input to read_hour\n";
		exit(1);
	}

	if (isdigit(c1) && c2 == ':')
	{
		the_hour = digit_to_int(c1);
	}
	else 
	{
		the_hour = digit_to_int(c1)*10 + digit_to_int(c2);
		ins >> c2;
		if (c2 != ':')
		{
			cout << "Error illegal input to read_hour\n";
			exit(1);
		}
	}
	if ( the_hour < 0 || the_hour > 23 )
	{
		cout << "Error illegal input to read_hour\n";
		exit(1);
	}
}
#endif