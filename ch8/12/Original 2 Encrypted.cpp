#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	while(1)
		{
char t1,t2,t3;
cout<<"enter pass";
cin>>t1>>t2>>t3;
cout<<t1<<t2<<t3<<"\n";
int tt1,tt2,tt3;
tt1=t1;
tt2=t2;
tt3=t3;
cout<<tt1<<tt2<<tt3<<"\n";
int key1;
cout<<"enter key";
cin>>key1;

if(tt1+key1>126)
	{tt1= 32+tt1+key1-127;}
else
	{tt1= tt1+ key1;}

if(tt2+key1>126)
	{tt2= 32+tt2+key1-127;}
else
	{tt2= tt2+ key1;}

if(tt3+key1>126)
	{tt3= 32+tt3 +key1-127;}
else
	{tt3= tt3+key1;}


cout<<"add key(int)\n"<<tt1<<"\n"<<tt2<<"\n"<<tt3<<"\n";
char ttt1,ttt2,ttt3;
ttt1=tt1;
ttt2=tt2;
ttt3=tt3;
cout<<"add key(char)\n"<<ttt1<<"\n"<<ttt2<<"\n"<<ttt3<<"\n";
ofstream fou;
fou.open("test12.txt", ios::app);

fou<<t1<<t2<<t3;
fou<<"          ";
fou<<key1;
fou<<"        ";
fou<<tt1<<" "<<tt2<<" "<<tt3<<" ";
fou<<"    ";
fou<<ttt1<<ttt2<<ttt3;
fou<<"\n---------------------------------------------------------------------"<<"\n";
fou.close();
	}
return 0;
}

// Pause

