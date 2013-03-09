// This is the solution to lab 3 of CS 122
//Total points: 100
// 2D array usage including index boundaries: 30 points
// File I/O on the status file: 40 points
// logic in assigning seats: 15 points
// User interaction: 15 points


// The status file status.txt initially contains 4 rows and 3 columns of zeros. 0 represents free and 1 represents occupied.

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace std;
const int NUMROWS=4;
const int NUMCOLS=3;

int status[NUMROWS][NUMCOLS];
bool assignSeat(char preference, int& row, int& col);// This function obtains the user prference 'b' or 'f' with variable preference. if there is a free seat in that section, then a row and a column number is returned by reference. It will also return a true as its return value. The corresponding entry in the status array will also be updated. If there is no free seat in the prefered section, a false will be returned. If the whole plane is full, then in addition to returning a false, it also returns a negative row and a negative col.

bool checkStatus(char preference, int& row, int& col);// this function accepts 'b' or 'f' as preference and checks if there is a free seat in the prefered section. it returns true if there is a free seat. It will also return the row and column number of the free seat.  Or else, false is returned. 

bool readStatus (void);// This function reads in the status file into the status array; If everything goes well, it returns true, or else it returns false.

bool writeStatus(void);// This function writes the status array into the status file. 

void printBoardingPass(int row, int col, string section);// print out the boarding pass


int main(){
	bool correct;// a flag to be used in various places.
	char preference, otherChoice;
	int row, col;// row and col to be assigned if any.
	string preferenceWord, otherSection;
	do{
		correct=true;
		cout<<"Welcome to C++ flight seat assignment interface!\n";
		cout<<"Please type f for \"front\"\n";
		cout<<"Please type b for \"back\"\n";
		cout << "Selection: ";		
		cin>>preference;
		if(preference=='f' || preference=='F'){
			preferenceWord="front";
			otherSection="back";
		}
		else if(preference=='b' || preference=='B'){
			preferenceWord="back";
			otherSection="front";
		}
		else{// input is invalid
			correct=false;
			cout << "Your entry is invalid. Please try again.\n";
		}
	}while(!correct);
			
	correct=readStatus();// read in the status into status array;
	if(!correct){
		cout << "Error in reading in the status. Please check status file.\n";
		exit(1);
	}
	correct=assignSeat(preference, row, col);
	if(!correct){//if there is no free seat in the preferred section
		if(row<0 && col<0){
			cout << "Sorry, the whole plane is full. Next flight leaves in 3 hours. Please wait for the next flight. Bye!";
			exit(0);// normal exit
		}
		else{// the preferred section is full but there is a free seat in the other section.
			cout << "Your preferred "<<preferenceWord<<" section is full. Is the " <<otherSection<<" ok for you? (y for yes and n for no)";
			cin>>otherChoice;
			if(otherChoice=='y' || otherChoice=='Y'){
				assignSeat(otherChoice, row, col);
				printBoardingPass(row, col, otherSection);
				correct=writeStatus();
				if(!correct){// writing error
					cout << "Error in writing new status. Please check the status file. \n";
					exit(2);
				}
			}
			else{// the user won't take seats on the other section.
				cout<<" Next flight leaves in 3 hours. Please wait for the next flight. Bye!";
				exit(0);// normal exit
			}
		
		}
	}
	else{// a successful assignment
		printBoardingPass(row, col, preferenceWord);
		correct=writeStatus();
		if(!correct){// writing error
			cout << "Error in writing new status. Please check the status file. \n";
			exit(2);
		}
	}
}

bool assignSeat(char preference, int& row, int& col){
	bool exist;// true means there is a free seat, false means no free seat.
	exist=checkStatus(preference, row, col);
	if(exist){// found a free seat in the preferred section
		status[row][col]=1;// update status array
		return true;
	}
	else{// no free seat in the preferred section
		if(preference=='f' || preference=='F'){
			exist=checkStatus('b', row, col);
		}
		else{
			exist=checkStatus('f', row, col);
		}
		if(exist){// ther other section has free seat(s)
			return false;
		}
		else{// the whole plane is full. 
			row=-1;
			col=-1;
			return false;
		}
	}
}

bool checkStatus(char preference, int&row, int& col){
	int i,j, start, end;

	if(preference=='f' || preference=='F'){
		start=0;
		end=NUMROWS/2;
	}
	else{
		start=NUMROWS/2;
		end=NUMROWS;
	}
	for (i=start;i<end;i++){
		for (j=0;j<NUMCOLS;j++){
			if(status[i][j]==0){// there is a free seat
				row=i;
				col=j;
				return true;
			}
			   
			   
		}
	}
	// after the loop, it hasn't return true yet. Thus there is no free seat.
	return false;
	
}

bool readStatus (void){
	ifstream fin;
	int i,j;
	fin.open("status.txt");
	if(fin.fail()){
		return false;
	}
	for (i=0;i<NUMROWS;i++){
		for (j=0;j<NUMCOLS;j++){
			fin>>status[i][j];
		}
	}
	
	fin.close();
	return true;
}

bool writeStatus(void){
	ofstream fout;
	int i,j;
	fout.open("status.txt");
	if(fout.fail()){
		return false;
	}
	for (i=0;i<NUMROWS;i++){
		for (j=0;j<NUMCOLS;j++){
			fout<<status[i][j]<<" ";
		}
		fout<<endl;
	}
	
	fout.close();
	return true;
}


void printBoardingPass(int row, int col, string section){
	
	cout << "Your seat information is the following.\n";
	cout.setf(ios::left);
	cout << setw(20)<<"Section:"<<section<<endl;
	cout <<setw(20)<<"Row number: "<<row+1<<endl;
	cout << setw(20)<<"Seat number: "<<col+1<<endl;
	cout << "Enjoy your flight! Bye!\n\n";
	return;
}