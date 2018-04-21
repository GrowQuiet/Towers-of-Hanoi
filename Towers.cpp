#include <iostream>
#include "Towers.h"
#include <stack>
#include <windows.h>
#include <cstdlib>

using namespace std;

Towers::Towers() {
	//cout << "teest " <<endl;
	// DEFAULT CONSTRUCTOR
	cout << "\t # of disks ?  : ";
	    int c;
		cin >> c;
	for(int i = c; i>0; i--) {
		m_rod1.push(i);
	}
}

void Towers::display(stack<int> &rod1, stack<int> &rod2, stack<int> &rod3, int numDisks) {
	// MAX LENGTH OF A ROD 
	int max_length = ( 2 * getSize() ) - 1;
	//difference of heights
	/* 
	    |     |     |
	    *     |     |
	   ***    |     |
	  *****   |  *******    diff = numDisks - rod.size() (dif is | )
	*/
	int difference1 = numDisks - rod1.size();
	int difference2 = numDisks - rod2.size();
	int difference3 = numDisks - rod3.size();
	
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
		if( numDisks <= rod1.size() ) {
			do1=1;
		}
	}
	if(!rod2.empty()){
		if( numDisks <= rod2.size() ) {
			do3=1;
		}
	}
	if(!rod3.empty()){
		if( numDisks <= rod3.size() ) {
			do3=1;
		}
	}
	
	
	//printing if do is 1
	if(do1==1){
		
		hold1=rod1.top();
		rod1.pop(); //need to access element below, so hold the top 
			
		int spaces = 0;
		spaces=getSize() - hold1; 
		
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
			cout<<"\272";
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
		cout<<"|";
		for(int x=0; x<getSize()-1; x++) {
			cout<<" ";
		}
	}
	// every other rod prints the same way....so i shouldnt
	// copy and paste the code but i will. im going to. 
	// is anyone even reading this.
	if(do2==1){
		
		hold2=rod2.top();
		rod2.pop(); //need to access element below, so hold the top 
			
		int spaces = 0;
		spaces=getSize() - hold2; 
		
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
			cout<<"\272";
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
		cout<<"|";
		for(int x=0; x<getSize()-1; x++) {
			cout<<" ";
		}
	}
	if(do3==1){
		
		hold3=rod3.top();
		rod3.pop(); //need to access element below, so hold the top 
			
		int spaces = 0;
		spaces=getSize() - hold1; 
		
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
			cout<<"\272";
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
		cout<<"|";
		for(int x=0; x<getSize()-1; x++) {
			cout<<" ";
		}
	}
	
	
}

Towers::~Towers() {
	cout << "\nill do this later\n" ;
}