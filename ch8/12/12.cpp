#include <iostream>
void get_word(char enter_word[], int temp_no[]);
void change_word_2_int(char [], int [],  int []);
void add_key_2_word_back_char(char [], int [], int [],int);
using namespace std;
int main()
	{
		while(1){// 2/10/2011 add
	char enter_word[100];
	int temp_no[100];
	//no[0]=total_enter
	//no[1]=add_key
	int char_no[100];
	get_word(enter_word, temp_no);
	change_word_2_int(enter_word,temp_no,char_no);
	for(int i=1;i<101;i++)
		{
		cout<<"\nKye = "<<i<<": ";
		add_key_2_word_back_char(enter_word,temp_no,char_no,i);
		}
	getchar();// 2/10/2011 add
	}// 2/10/2011 add
return 0;
	}
void get_word(char enter_word[], int temp_no[])//ok
	{
	temp_no[0]=0;
	do
		{
		cin.get(enter_word[temp_no[0]]);
		temp_no[0]++;
		}while(enter_word[temp_no[0]-1]!='\n');
		temp_no[0]-=1;//fix the length
	}

void change_word_2_int(char enter_word[], int temp_no[],  int char_no[])
	{
	for(int i=0; i<temp_no[0]; i++)
		{
		char_no[i]=enter_word[i];
		}
	
	}

void add_key_2_word_back_char(char enter_word[], int temp_no[],  int char_no[], int key)
	{
	int t_char_no[100];
		for(int i=0; i<temp_no[0]; i++)
		{
		t_char_no[i]=char_no[i];
		t_char_no[i]+=126;
		t_char_no[i]-=key;
		}
		for(int i=0; i<temp_no[0]; i++)
		{
		while(t_char_no[i]>126)
			{
			t_char_no[i]-=126;
			}
		if(t_char_no[i]<32)
			{
			t_char_no[i]=t_char_no[i]+95;
			}
		}
		for(int i=0; i<temp_no[0]; i++)
		{
	enter_word[i]=t_char_no[i];
	cout<<enter_word[i];
		}

	}

