#include <iostream>
#include <cstring>
#include <string>
#include <cctype>
void word(int);
void get_word(char [], int []);
void get_total_word(char [], int []);
void change_word_2_lowercase(char [], int []);
void change_word_2_list(char [], int []);
void display_word(char [], int []);

using namespace std;


int main()
	{
	int temp_no[100];
	//no[0]=total_word(with space)
	//no[1]=total_word(without space)
	//no[2]=total_single_word
	//no[3]=temp use for how many same words in one word
	word(1);
	char enter_word[100];
	get_word(enter_word, temp_no);
	get_total_word(enter_word, temp_no);
	change_word_2_lowercase(enter_word, temp_no);
	change_word_2_list(enter_word, temp_no);
	display_word(enter_word, temp_no);

	
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
void get_total_word(char enter_word[], int temp_no[])//ok
	{
	temp_no[1]=0;
	for(int i=0; i<temp_no[0]; i++)
		{
		if(enter_word[i]==' ')
			{temp_no[1]++;}
		}
	temp_no[1]+=1;//fix length	
	}
void change_word_2_lowercase(char enter_word[], int temp_no[])//ok
	{
	temp_no[2]=0;
	for(int i=0; i<temp_no[0]; i++)
		{
		enter_word[i]=tolower(enter_word[i]);
		
	if(isalpha(enter_word[i]))
		{
		enter_word[temp_no[2]]=enter_word[i];
		temp_no[2]++;
		}
		}
	}
void change_word_2_list(char enter_word[], int temp_no[])//ok
	{
	for (int i=0; i<temp_no[2]-1; i++)
		{
		for (int j=i+1; j<temp_no[2]; j++)
			{			
			if(enter_word[i]>enter_word[j])
				{
				char t;
				t=enter_word[j];
				enter_word[j]=enter_word[i];
				enter_word[i]=t;
				}
			}
		}
	}
void display_word(char enter_word[], int temp_no[])
	{
	 temp_no[3]=0;
	if(temp_no[1]>1)
		{
	cout<<temp_no[1]<<" Words\n";
		}
	else
		{
		cout<<temp_no[1]<<" Word\n";
		}
	for(int i=1; i<temp_no[2]+1; i++)
		{
		if(enter_word[i]!=enter_word[i-1])
			{
			if(temp_no[3]==0)//ÎÞÖØ¸´
				{
			cout<<"1 "<<enter_word[i-1]<<"\n";
				}
			else
				{
				cout<<temp_no[3]+1<<" "<<enter_word[i-1]<<"\n";
				temp_no[3]=0;
				}
			}
		else
			{
			temp_no[3]++;
			}
		}
	}
void word(int n)
	{
	if(n==1)
		{
		cout<<"Enter words: ";
		}
	}