//please use new_morse.txt.
#include <iostream>
#include <fstream>
#include <Windows.h>
void word(int);
void enter_word(char []);
void change_2_morse(char []);
void morse_2_beep(char);
using namespace std;
int TOTEL_NO=0;//for last word, don't need Beep(20, 300).
int main()
{
	//conf
	int conf_int[2];
	conf_int[0]=200;//默认状态
	//char char_size[200];//old style
	//conf end
	//test ch9
	typedef char* a;
	a char_size;
	char_size=new char[conf_int[0]];
	//test ch9 end

	word(1);//welcome

	/********Main Part**********/
	enter_word(char_size);//ask user enter the word
	change_2_morse(char_size);
	//change word to morse code, than pass to void morse_2_beep(char);
  /********Main Part End**********/
	word(2);
	delete [] char_size;
	return 0;
}


void word(int n)
{
	if(n==1)
	{
		cout<<"Welcome to the C++ Morse Telegraph Machine!\n\n"
			<<"Please enter a sentence (no punctuation or digits): ";
	}
	if(n==2)
	{
		cout<<"\nYour telegraph is sent. Please pay at Paul Cao's office. Thanks for your business.\n";
	}
}
void enter_word(char input[])//ok
	{
	for(int i=0;i<200;i++)
		{
	cin.get(input[i]);
	if(input[i]=='\n')
		{
		break;
		}
	TOTEL_NO++;//add 
		}

	}
void change_2_morse(char input[])//ok
	{	int t_1=TOTEL_NO;
		for(int i=0;i<t_1;i++)
		{
			if(input[i]==' ')//处理空格
			{cout<<"\n";}
		if(input[i]=='\n')//结尾停止
		{
		break;
		}
		else
			{
				TOTEL_NO--;//完成一个字母的转换
			/********Change 2 Morse**********/
		    /*****Moese Code Data from txt*****/	
		char t_input;
		t_input=toupper(input[i]);//统一 字母，data只有大写
		ifstream fin;
	   fin.open("new_morse.txt");//get new one, change Word&No. already + No. to new_morse.txt
	   if(fin.fail())
		{		
		cout<<"error1,can't open the new_morse.txt, try to open morse.txt\n";
		fin.open("morse.txt");//open old wen
		 if(fin.fail())
			 {cout<<"error1,can't open morse.txt\n";
			 exit(1);
			 }
		}
	   char check[5];
	   for(int j=0;j<5;j++)
		   {
		   check[j]='a';//初始化
		   }
	   while(!fin.eof())
		   {
		   fin>>check[0];
		   if(check[0]==t_input)//find word 
			   {
			   fin.get(check[0]);//double check and throw space
			   if(check[0]==' ')
				   {
				   int t1=0;
				   cout<<input[i]<<" ";
				   for(int i=0;i<5;i++)//read morse code
					   {
					   fin.get(check[i]);
					   if(check[i]=='-'||check[i]=='.')
						   {

						   cout<<check[i];
					       morse_2_beep(check[i]);
						   if(TOTEL_NO)
						   {
							   cout<<"beep 0,1\n";
							   Beep(10, 300);

						   }
						   t1=1;
						   }
					   if(check[i]=='\n')//read end
						   {
						   cout<<"read nn \n";
						   if(TOTEL_NO)
							   {
								   cout<<"beep 0,2\n";
						   Beep(10, 600);
						   }
						   break;
						   }
					   }
				   }
			   else
				   {cout<<"check space wrong, or data wrong";}
			   }
		   }
	   fin.close();
	   //alreday change to morse code
	   //change 2 deep
			}
		}
	
	}
void morse_2_beep(char morse)
	{
	if(morse=='-')
		{
			cout<<"beep 2000,300,1\n";
		Beep(2000, 300);
		}
	else
		{
			cout<<"beep 5000,300,1\n";
		Beep(5000, 300);
		}

	}
	