//================
//Ch15 Pro11 driver 
//CS122 Junjun Huang
//4/21/2011 16:27 done & test
//================
#include <iostream>
#include <time.h>
#include "class.h"
using namespace std;
int main()
{
	srand(time(NULL));
	World test;
	int doodlebug1 = 0;
	while (doodlebug1 < 5)
	{
		int x = rand() % 20;
		int y = rand() % 20;
		if (test.getAt(x,y)==NULL)
		{
			doodlebug1++;
			Doodlebug *doodlebug11 = new Doodlebug(&test,x,y);
		}
	}
	int ant1 = 0;
	while (ant1 < 100)
	{
		int x = rand() % 20;
		int y = rand() % 20;
		if (test.getAt(x,y)==NULL)
		{
			ant1++;
			Ant *ant11 = new Ant(&test,x,y);
		}
	}
	
		string s;
	for (int i=0;i<999;i++)
	{
	test.Display();
	test.SimulateOneStep();
	cout<<"\none more? type n to stop\n";
	char one_more = 'y';
	cin.get(one_more);
	if (one_more=='n'| one_more=='N')
	{
		break;
	}
	else
	{
		cout<<"\nyou have run "<<i+1<<" times\n\n";
	}
	}
	return 0;
}

