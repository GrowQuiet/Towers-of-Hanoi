#include <iostream>
#include "Towers.h"
#include <stack>
#include <queue>
#include <windows.h>
#include <unistd.h>
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()


using namespace std;


void Towers::solve() 
{
	recSolve(numDisks,1,3,2)	
}

void buildSolution(unsigned numberOfDisks,unsigned fromRod,unsigned toRod,unsigned usingRod)
{
	queue<pair<int,int>> moves;
	if(numberOfDisks == 1)
	{
		moves.push((fromRod,toRod));
	}
	else
	{
		recSolve(numberOfDisks-1,fromRod,usingRod,toRod);
		moves.push((fromRod, toRod));
		recSolve(numberOfDisks-1,usingRod,toRod,fromRod);
	}
	for(int i = 0; i < moves.size();i++){
		cout<<moves.pop()<<endl;
	}
	return;
}

Towers::Towers() {
	//cout << "teest " <<endl;
	// DEFAULT CONSTRUCTOR
	cout << "\t # of disks ?  : ";
	    int c;
		cin >> c;
	for(int i = c; i>0; i--) {
		m_rod1.push(i);
	}
	setSize(c);
	rows = c;
}

void Towers::display(stack<int> &rod1, stack<int> &rod2, stack<int> &rod3, int numDisks) {
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//difference of heights
	/* 
	    |     |     |
	    *     |     |
	   ***    |     |
	  *****   |  *******    diff = numDisks - rod.size() (dif is | )
	*/
	
	// do = will print a line of stars/spaces
    // hold = temp var

	int do1=0, do2=0, do3=0;
	int hold1=0, hold2=0, hold3=0; 	
	
	if( rod1.empty() && rod2.empty() && rod3.empty() ){
		//nothing to print. print over
		cout << endl;
		return;
	}
	
	//sets the 'do' vars to 1 if printing needed
	if(!rod1.empty()){
		if( rows <= rod1.size() ) {
			do1=1;
		}
	}
	if(!rod2.empty()){
		if( rows <= rod2.size() ) {
			do2=1;
		}
	}
	if(!rod3.empty()){
		if( rows <= rod3.size() ) {
			do3=1;
		}
	}
	
	
	//printing if do is 1
	if(do1==1){
		
		hold1=rod1.top();
		rod1.pop(); //need to access element below, so hold the top 
			
		int spaces = 0;
		//cout << "gs : " << getSize() << endl;
		spaces = getSize() - hold1; 
		
		int z1=(hold1*2);

		
		/*
		    each rod has to print spaces then stars then spaces
			ex : (- = space )
			
			--*--
			-***-
			*****
			
		*/
		
		for(int i=0; i<spaces; i++) {
		    cout<<" ";
		}	
		
		for(int i=0; i<z1-1; i++){
			cout<<"\334";
		}
		for(int i=0; i<5; i++)
		{
			cout<<" ";
		}
	} else {
		//nothing to print besides rod
		/*
		    ex :
			
			    |
				|
				|
			   ---
		*/
		
		for(int x=0; x<getSize()-1; x++) {
			cout<<" ";
		}
		SetConsoleTextAttribute(hConsole, 111);
		cout<<"|";
		SetConsoleTextAttribute(hConsole, 7);
		for(int x=0; x<getSize()-1; x++) {
			cout<<" ";
		}
	}
	// every other rod prints the same way....so i shouldnt
	// copy and paste the code but i will. im going to. 
	// is anyone even reading this.
	cout<<"\t";
	if(do2==1){
		
		hold2=rod2.top();
		rod2.pop(); //need to access element below, so hold the top 
			
		int spaces = 0;
		spaces= getSize() - hold2; 
		
		int z1=(hold2*2);

		
		/*
		    each rod has to print spaces then stars then spaces
			ex : (- = space )
			
			--*--
			-***-
			*****
			
		*/
		
		for(int i=0; i<spaces; i++) {
		    cout<<" ";
		}	
		
		for(int i=0; i<z1-1; i++){
			cout<<"\334";
		}
		for(int i=0; i<spaces; i++)
		{
			cout<<" ";
		}
	} else {
		//nothing to print besides rod
		/*
		    ex :
			
			    |
				|
				|
			   ---
		*/
		
		for(int x=0; x<getSize()-1; x++) {
			cout<<" ";
		}
		SetConsoleTextAttribute(hConsole, 111);
		cout<<"|";
		SetConsoleTextAttribute(hConsole, 7);
		for(int x=0; x<getSize()-1; x++) {
			cout<<" ";
		}
	}
	cout<<"\t";
	if(do3==1){
		
		hold3=rod3.top();
		rod3.pop(); //need to access element below, so hold the top 
			
		int spaces = 0;
		spaces= getSize() - hold3; 
		
		int z1=(hold3*2);

		
		/*
		    each rod has to print spaces then stars then spaces
			ex : (- = space )
			
			--*--
			-***-
			*****
			
		*/
		
		for(int i=0; i<spaces; i++) {
		    cout<<" ";
		}	
		
		for(int i=0; i<z1-1; i++){
			cout<<"\334";
		}
		for(int i=0; i<spaces; i++)
		{
			cout<<" ";
		}
	} else {
		//nothing to print besides rod
		/*
		    ex :
			
			    |
				|
				|
			   ---
		*/
		
		for(int x=0; x<getSize()-1; x++) {
			cout<<" ";
		}
		SetConsoleTextAttribute(hConsole, 111);
		cout<<"|";
		SetConsoleTextAttribute(hConsole, 7);
		for(int x=0; x<getSize()-1; x++) {
			cout<<" ";
		}
	}
	
	cout << endl;
	//cout << "ROWS : " << rows << "  " << getSize() << endl;
	rows = rows - 1;
	
	//usleep(1000);
	display	(rod1, rod2, rod3, m_numDisks);
	
	if(do1==1) {
		rod1.push(hold1);
	}
	if(do2==1) {
		rod2.push(hold2);
	}
	if(do3==1) {
		rod3.push(hold3);
	}	
	
}
Towers::~Towers() {
	cout << "\nill do this later\n" ;
}
