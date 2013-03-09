#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cctype>

using namespace std;

void dotBeep(void);
void dashBeep(void);
void silence(void);
string searchForChar(char target);// search for the target character in the morse file. It returns the Morse code of the target char as a string. If no match is found, it returns an empty string. 
void morseMachine(char character, string morseCode);// displays the morse code and beeps accordingly for the morse code of a character.
const int silenceFrequency=20;
const int silenceDuration = 300;
const int dotFrequency = 5000;
const int dashFrequency = 2000;
const int dotDuration = 300;
const int dashDuration = 900;
int main(){
	string input;
	string morse;
	int i;
	cout <<"Welcome to the C++ Morse Telegraph Machine!\n\n";
	cout <<"Please enter a sentence (no punctuation or digits): ";
	getline(cin, input);// read in the input

	
	// generate the display and sound
	for (i=0;i<input.size(); i++){// iterate through every input character
		if(input.at(i)==' '){// if it is space, then the silence beep is 7 times of a regular silence beep
			for (int j=0;j<7;j++){
				silence();
			}
		}
		else{// display the Morse code and sound
			morse=searchForChar(toupper(input.at(i)));// search for the morse code
			if(morse.empty()){
				cout<<"You have entered an illegal character! Program terminates.\n";
				exit(2);
			}
			morseMachine(input.at(i), morse);// display the morse code and sound of a character
			if(i!=input.size()-1){//if not the last character, then display 3 silence sounds
				for (int j=0;j<3;j++){
					silence();
				}
			}
		}
	}
	cout<<"Your telegraph is sent. Please pay at Paul Cao's office. Thanks for your business.\n";
	return 0;
}
void dotBeep(void){
	Beep(dotFrequency, dotDuration);
	return;
}

void dashBeep(void){
	Beep(dashFrequency, dashDuration);
}

void silence(void){
	Beep (silenceFrequency, silenceDuration);
}
string searchForChar(char target){
	string morse;
	char character;
	ifstream fin;
	fin.open("morse.txt");// open the morse code input file
	if(fin.fail()){
		cout<<"Can't open morse.txt. Check input file!";
		exit(1);
	}
	while(!fin.eof()){
		fin>>character;
		fin>>morse;
		if(character==target){//found the target
			fin.close();
			return morse;
		}
	}
	if(fin.eof()){
		fin.close();
		return "";
	}

}
void morseMachine(char character, string morseCode){
	int i;
	cout <<character<<" ";
	for(i=0;i<morseCode.size();i++){
		cout<<morseCode.at(i);
		//send out the beeps now
		if(morseCode.at(i)=='.'){// a dot in the morse code
			dotBeep();
		}
		else if(morseCode.at(i)=='-'){// a dash in the morse code
			dashBeep();
		}
		if(i<morseCode.size()-1){//if not the last dot or dash of the morse code, need to output a silence beep
			silence();
		}
		else{// simply return since the whole morse code has been displayed.
			cout<<endl;
			return;

		}
	}

}