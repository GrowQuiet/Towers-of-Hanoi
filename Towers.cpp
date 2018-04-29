#include <iostream>
#include "Towers.h"
#include <stack>
#include <queue>
#include <windows.h>
#include <unistd.h>
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()

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
	setSize(c);
	rows = c;
}


void Towers::solve() 
{
	buildSolution(this->m_numDisks, this->m_rod1, this->m_rod2, this->m_rod3);	
}


void Towers::buildSolution(unsigned numberOfDisks,std::stack<int> &fromRod,std::stack<int> &usingRod,std::stack<int> &toRod)
 {
 	if(numberOfDisks!= 0){
 		buildSolution(numberOfDisks-1,fromRod,toRod,usingRod); //moves top disks to the middle, or second, peg.
		move(fromRod,toRod);								   // moves the peg.
 		buildSolution(numberOfDisks-1,usingRod,fromRod,toRod); //moves bottom disk to final, or third, peg.
 	}	
 
 	return;
 }
 
 void Towers::move( std::stack<int> &fromRod, std::stack<int> &toRod){
	toRod.push(fromRod.top());	//takes disk from desired rod and puts disk into desired rod;
	fromRod.pop(); //removes moved disk
 	return;
 }
void Towers::playerMove(){
	unsigned fromRod, toRod;
	cout<< "\t Where would you like to move from and where would you like it to go?";
	cin>> fromRod >> toRod;
	if(this->validateMove(fromRod,toRod)){
		switch(fromRod){
			case 1:
				switch(toRod){
					case 2:
						system("cls");
						move(m_rod1, m_rod2);
						this->display(this->m_numDisks);
						break;
					case 3:
						system("cls");
						move(m_rod1, m_rod3);
						this->display(this->m_numDisks);
						break;
				}
				break;
			case 2:
				switch(toRod){
					case 1:
						system("cls");
						move(m_rod2, m_rod1);
						this->display(this->m_numDisks);
						break;
					case 3:
						system("cls");
						move(m_rod2, m_rod3);
						this->display(this->m_numDisks);
						break;
				}
				break;
			case 3:
				switch(toRod){
					case 1:
						system("cls");
						move(m_rod3, m_rod1);
						this->display(this->m_numDisks);
						break;
					case 2:
						system("cls");
						move(m_rod3, m_rod2);
						this->display(this->m_numDisks);
						break;
				}
				break;
				default:
					break;
		}
	}
}
void Towers::play(){
	system("cls");
	this->display(this->m_numDisks);
	while(true){

		this->playerMove();
		
	}
}

void Towers::display( int numDisks ) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	srand(time(0));  // Initialize random number generator.
	
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
	
	if( this->m_rod1.empty() && this->m_rod2.empty() && this->m_rod3.empty() ){
		//nothing to print. print over
		cout << endl;
		return;
	}
	
	//sets the 'do' vars to 1 if printing needed
	if(!this->m_rod1.empty()){
		if( rows <= this->m_rod1.size() ) {
			do1=1;
		}
	}
	if(!this->m_rod2.empty()){
		if( rows <= this->m_rod2.size() ) {
			do2=1;
		}
	}
	if(!this->m_rod3.empty()){
		if( rows <= this->m_rod3.size() ) {
			do3=1;
		}
	}
	
	
	//printing if do is 1
	if(do1==1){
		
		hold1=this->m_rod1.top();
		this->m_rod1.pop(); //need to access element below, so hold the top 
			
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
			SetConsoleTextAttribute(hConsole, ( (rand() % 15) + 1 ) );
			cout<<"\270";
			SetConsoleTextAttribute(hConsole, 7 );
		}
		for(int i=0; i<spaces; i++) {
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
	//cout << setw(getSize()*2 - 1);
	if(do2==1){
		
		hold2=this->m_rod2.top();
		this->m_rod2.pop(); //need to access element below, so hold the top 
			
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
			SetConsoleTextAttribute(hConsole, ( (rand() % 15) + 1 ) );
			cout<<"\334";
			SetConsoleTextAttribute(hConsole, 7 );
		}
		for(int i=0; i<spaces; i++) {
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
	//cout<<"\t";
	//cout << setw(getSize()*2 - 1);
	cout<<"\t";
	if(do3==1){
		
		hold3=this->m_rod3.top();
		this->m_rod3.pop(); //need to access element below, so hold the top 
			
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
			SetConsoleTextAttribute(hConsole, ( (rand() % 15) + 1 ) );
			cout<<"\334";
			SetConsoleTextAttribute(hConsole, 7 );
		}
		
		for(int i=0; i<spaces; i++) {
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
	display	( this->getSize() );
	
	if(do1==1) {
		this->m_rod1.push(hold1);
	}
	if(do2==1) {
		this->m_rod2.push(hold2);
	}
	if(do3==1) {
		this->m_rod3.push(hold3);
	}	
	rows = this->getSize();
}

bool Towers::validateMove(int fromRod, int toRod){
	/* CHECKS IF MOVING FROM A ROD TO DESIRED IS LEGAL
	        1) isnumeric?
			2) out of range [1,3] only
			3) check if fromRod is not empty
			4) make sure toRod.top is > fromRod.top
			can move if passes all tests
			*/
			
	/*
	 LOGIC IN THIS FUNCTION
	 if ( numbers are valid inputs )
	   if ( fromRod isnt empty )
	     if ( toRod .top > fromRod.top or toRod is empty)
	       retrun true
	*/
	
	if ( ( fromRod > 0 && toRod > 0 ) && ( fromRod < 4 && toRod < 4 ) && ( fromRod != toRod ) ) {
	    /* fromRod&&toRod interval [1,3] and theyre not equal to eachother */
	    //this->m_rod1;
		switch(fromRod){
	    	case 1: //MOVING FROM ONE
	    		if ( this->m_rod1.empty() ) {
					/* EMPTY, CANNOT MOVE */
					return false;
				} else { 
					/* ABLE TO MOVE */
					switch(toRod){
						//CANT MOVE TO ROD 1 FROM 1
						case 2: // 1 -> 2
							if ( this->m_rod2.empty() || ( this->m_rod2.top() > this->m_rod1.top() ) ){
								return true;
							} else {
								return false;
							}
							break;
						case 3: // 1 -> 3
							if ( this->m_rod3.empty() || ( this->m_rod3.top() > this->m_rod1.top() ) ){
								return true;
							} else {
								return false;
							}
							break;
						default: 
							std::cout<< "impossible to get here.\n";
							break;
					}					
				}
				break;
	    	case 2: //MOVING FROM TWO
	    		if ( this->m_rod2.empty() ) {
					/* EMPTY, CANNOT MOVE */
					return false;
				} else {
					/* ABLE TO MOVE */
					switch(toRod){
						//CANT MOVE TO ROD 2 FROM 2
						case 1: // 2-> 1
							if ( this->m_rod1.empty() || ( this->m_rod1.top() > this->m_rod2.top() ) ){
								return true;
							} else {
								return false;
							}
							break;
						case 3: // 2 -> 3
							if ( this->m_rod3.empty() || ( this->m_rod3.top() > this->m_rod2.top() ) ){
								return true;
							} else {
								return false;
							}
							break;
						default: 
							std::cout<< "impossible to get here.\n";
							break;
					}
				}
				break;
	    	case 3: //MOVING FROM THREE
	    		if ( this->m_rod3.empty() ) {
					/* EMPTY, CANNOT MOVE */
					return false;
				} else {
					/* ABLE TO MOVE */
					switch(toRod){
						//CANT MOVE TO ROD 3 FROM 3
						case 1: // 3-> 1
							if ( this->m_rod1.empty() || ( this->m_rod1.top() > this->m_rod3.top() ) ){
								return true;
							} else {
								return false;
							}
							break;
						case 2: // 3-> 2
							if ( this->m_rod2.empty() || ( this->m_rod2.top() > this->m_rod3.top() ) ){
								return true;
							} else {
								return false;
							}
							break;
						default: 
							std::cout<< "impossible to get here.\n";
							break;
					}
				}
				break;
	    	default: 
	    		std :: cout << "invalid input but impossible to get here. \n";
	    		break;
		}
		return true;
	}
	//will never get here
	return false;
}

Towers::~Towers() {
	cout << "\nill do this later\n" ;
}

