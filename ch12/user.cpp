#include "user.h"
namespace
{
	string username;

	bool isValid()
	{
		bool pass;
		pass = (username.length() == 8);//1
		if (pass)
		{
			for (int i = 0; i < (int)username.length(); i++)
			{
				if (isalpha(username[i]))
				{
					pass = 1;
				}
				else
				{
					pass=0;
					break;
				}
			}
		}

		return pass;
	}
}

namespace Authenticate
{
	void inputUserName() 
	{ 
		do 
		{ 
			cout << "Enter your username (8 letters only)" << endl; 
			cin >> username; 
		} while (!isValid()); 
	} 

	string getUserName() 
	{ 
		return username; 
	}
}
