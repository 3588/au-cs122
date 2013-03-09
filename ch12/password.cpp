#include "password.h"
namespace
{
	string password;

	bool isValid()
	{
		bool pass;
		pass = (password.length() > 7);//1

		if (pass)
		{
			pass = 0;
			for (int i = 0; i < (int)password.length(); i++)
			{
				if (! isalpha(password[i]))
				{
					pass=1;
					break;
				}
			}
		}

		return pass;
	}
}
namespace Authenticate 
{ 
	void inputPassword() 
	{ 
		do 
		{ 
			cout << "Enter your password (at least 8 characters " << 
				"and at least one non-letter)" << endl; 
			cin >> password ; 
		} while (!isValid()); 
	} 
string getPassword() 
	{ 
		return password; 
	}
} 

