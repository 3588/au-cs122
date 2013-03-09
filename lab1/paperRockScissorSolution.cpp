/* This is the solution to CS 122 lab 1
 Total points: 60 points
 Problem 1: 40 points
 Problem 2: 20 points
 */



/* Problem 2: The answers is the following. Each line of outputs is 5 points.
 par1_value in function call = 111
 par2_ref in function call = 222
 n1 after function call = 10
 n2 after function call = 222
 */ 

/* Problem 1:
 Read inputs: 8 points
 if statement to check if the inputs are valid: 4 points
 if statements to judge the result: 20 points
 Condition to terminate the loop: 4 points
 Coding: 4 points
 
 The code is the following
 */


#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
	/* Variable declarations */
	char input1, input2; // input1 is to accept the input from user 1 and similarly input2 is for user 2
	char flag; // the flag to see if the user wants to terminate the game
	
	do{
		/* Solicit user inputs */
		cout << "Welcome to the Paper-Rock-Scissor Game!\n";
		cout << "Please input your choice: P or p for paper; R or r for rock; S or s for scissor\n";
		cout << "User 1: ";
		cin >>input1;
		cout << "User 2: ";
		cin >>input2;
		
		/* write an if statement here to check if the two inputs are valid (only P, p, R,r, S,s are valid inputs)*/
		
		if(!(input1=='P' || input1=='p' || input1=='R' || input1=='r' ||input1=='S' || input1=='s') || !(input2=='P' || input2=='p' || input2=='R' || input2=='r' ||input2=='S' || input2=='s')){
			cout << "Your input is invalid. Program terminates!";
			exit(1);
		}
		
		
		
		/* Process user input 
		 Based on the input from user 1, we can divide alll possibilities into three scenarios:
		 if the first user gives a paper (P or p), then we can make judgements on the game based on what the second user gives.
		 Similarly, we can test if the first user gives a rock or a scissor. The first scenario is given. please complete the 2nd and 3rd scenario.
		 */
		
		/* If the first user gives paper*/
		if(input1=='P' || input1=='p'){
			if(input2=='R' || input2=='r'){
				cout << "User 1 wins because paper covers rock!\n";
			}
			else if(input2=='S' || input2=='s'){
				cout << "User 2 wins because scissor cuts paper!\n";
			}
			else{
				cout << "Nobody wins!\n";
			}
		}
		/* If the first user gives rock*/
		if(input1=='R' || input1=='r'){
			if(input2=='P' || input2=='p'){
				cout << "User 2 wins because paper covers rock!\n";
			}
			else if(input2=='S' || input2=='s'){
				cout << "User 1 wins because rock breaks scissor!\n";
			}
			else{
				cout << "Nobody wins!\n";
			}
		}		
		/*if the first user gives scissor*/
		if(input1=='S' || input1=='s'){
			if(input2=='R' || input2=='r'){
				cout << "User 2 wins because rock breaks scissor!\n";
			}
			else if(input2=='P' || input2=='p'){
				cout << "User 1 wins because scissor cuts paper!\n";
			}
			else{
				cout << "Nobody wins!\n";
			}
		}
		cout << "Do you want to play another game? (y for yes and n for no): ";
		cin >> flag;
		
	}while(flag=='y' || flag=='Y');
	
	return 0;
	
	
}