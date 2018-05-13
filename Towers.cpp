#include <iostream>
#include "Towers.h"
#include "login.h"
#include <stack>
#include <queue>
#include <windows.h>
#include <unistd.h>
#include <conio.h>
#include <math.h>
#include <vector>
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
		m_rod1.push(make_pair(i,i));
		//m_rod1.push(i);
	}
	setMoves(0);
	setSize(c);
	rows = c;
}

Towers::Towers( int disks ) {
	//cout << "teest " <<endl;
	// DEFAULT CONSTRUCTOR
	for(int i = disks; i>0; i--) {
		m_rod1.push(make_pair(i,i));
		//m_rod1.push(i);
	}
	setMoves(0);
	setSize(disks);
	rows = disks;
}

void Towers::solve() //auto solve function. calls up recursive sol.
{
	buildSolution(this->m_numDisks,this->m_rod1,this->m_rod2,this->m_rod3);	
}


void Towers::buildSolution(unsigned numberOfDisks,std::stack<std::pair<int,int> > &fromRod,std::stack<std::pair<int,int> > &usingRod,std::stack<std::pair<int,int> > &toRod)
 {
 	if(numberOfDisks!= 0){
 		buildSolution(numberOfDisks-1,fromRod,toRod,usingRod); //moves top disks to the middle, or second, peg.
		this->move(fromRod,toRod);								   // moves the peg.
		this->incrementMoves();
		usleep(500000);
		system("cls");
		this->computer_leaderboard();
		this->display( );
 		buildSolution(numberOfDisks-1,usingRod,fromRod,toRod); //moves bottom disk to final, or third, peg.
 	}	
 	return;
 }
 
 void Towers::move( std::stack<std::pair<int,int> > &fromRod, std::stack<std::pair<int,int> > &toRod){
	toRod.push(fromRod.top());	//takes disk from desired rod and puts disk into desired rod;
	fromRod.pop(); //removes moved disk
 	return;
 }

void Towers::cheatSolution(int n,int one, int two,int three)
 {
 	if(n==1)
	{
		//cout<<"Move Disk "<<n<<" from "<<one<<" to "<<three<<endl;
		vector <int> temp;
		temp.push_back(one);
		temp.push_back(three);
		this->m_cheat_solution.push(temp);
		return;
	}
	
	cheatSolution(n-1,one,three,two);
	
	vector <int> temp;
	temp.push_back(one);
	temp.push_back(three);
	this->m_cheat_solution.push(temp);
	//cout<<"Move Disk "<<n<<" from "<<one<<" to "<<three<<endl;
	cheatSolution(n-1,two,one,three);
 }

void Towers::display( ) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	//difference of heights
	/* 
	    |     |     |
	    *     |     |
	   ***    |     |
	  *****   |  *******    diff = numDisks - rod.size() (dif is | )
	*/
	
	// do = will print a line of stars/spaces, else it prints rod ( | )
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
		hold1 = ( this->m_rod1.top() ).first;
		
		this->m_rod1.pop(); //need to access element below, so hold the top 
			
		int spaces = 0;
		//cout << "gs : " << getSize() << endl;
		spaces = this->getSize() - hold1; 
		
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
			SetConsoleTextAttribute(hConsole, hold1 );
			cout<<(char)483;
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
		
		for(int x=0; x<this->getSize()-1; x++) {
			cout<<" ";
		}
		SetConsoleTextAttribute(hConsole, 111);
		cout<<"|";
		SetConsoleTextAttribute(hConsole, 7);
		for(int x=0; x<this->getSize()-1; x++) {
			cout<<" ";
		}
	}
	// every other rod prints the same way....so i shouldnt
	// copy and paste the code but i will. im going to. 
	// is anyone even reading this.
	cout<<"\t";
	//cout << setw(getSize()*2 - 1);
	if(do2==1){
		hold2 = ( this->m_rod2.top() ).first;
		this->m_rod2.pop(); //need to access element below, so hold the top 
			
		int spaces = 0;
		spaces= this->getSize() - hold2; 
		
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
			SetConsoleTextAttribute(hConsole, hold2 );
			cout<<(char)483;
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
		
		for(int x=0; x<this->getSize()-1; x++) {
			cout<<" ";
		}
		SetConsoleTextAttribute(hConsole, 111);
		cout<<"|";
		SetConsoleTextAttribute(hConsole, 7);
		for(int x=0; x<this->getSize()-1; x++) {
			cout<<" ";
		}
	}
	//cout<<"\t";
	//cout << setw(getSize()*2 - 1);
	cout<<"\t";
	if(do3==1){
		hold3 = ( this->m_rod3.top() ).first;
		this->m_rod3.pop(); //need to access element below, so hold the top 
			
		int spaces = 0;
		spaces= this->getSize() - hold3; 
		
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
			SetConsoleTextAttribute(hConsole, hold3 );
			cout<<(char)483;
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
		
		for(int x=0; x<this->getSize()-1; x++) {
			cout<<" ";
		}
		SetConsoleTextAttribute(hConsole, 111);
		cout<<"|";
		SetConsoleTextAttribute(hConsole, 7);
		for(int x=0; x<this->getSize()-1; x++) {
			cout<<" ";
		}
	}
	
	cout << endl;
	//cout << "ROWS : " << rows << "  " << getSize() << endl;
	rows = rows - 1;
	
	//usleep(1000);
	display	( );
	
	if(do1==1) {
		this->m_rod1.push(make_pair(hold1,hold1));
	}
	if(do2==1) {
		this->m_rod2.push(make_pair(hold2,hold2));
	}
	if(do3==1) {
		this->m_rod3.push(make_pair(hold3,hold3));
	}	
	rows=this->getSize();
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
	    this->m_rod1;
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
							if ( this->m_rod2.empty() || ( (this->m_rod2.top()).first > (this->m_rod1.top()).first ) ){
								return true;
							} else {
								return false;
							}
							break;
						case 3: // 1 -> 3
							if ( this->m_rod3.empty() || ( (this->m_rod3.top()).first > (this->m_rod1.top()).first ) ){
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
							if ( this->m_rod1.empty() || ( (this->m_rod1.top()).first > (this->m_rod2.top()).first ) ){
								return true;
							} else {
								return false;
							}
							break;
						case 3: // 2 -> 3
							if ( this->m_rod3.empty() || ( (this->m_rod3.top()).first > (this->m_rod2.top()).first )){
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
							if ( this->m_rod1.empty() || ( (this->m_rod1.top()).first > (this->m_rod3.top()).first ) ){
								return true;
							} else {
								return false;
							}
							break;
						case 2: // 3-> 2
							if ( this->m_rod2.empty() || ( (this->m_rod2.top()).first > (this->m_rod3.top()).first ) ){
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

void Towers::playerMove(){
	unsigned fromRod, toRod;
	cout<< "\t from ? : ";
		cin>> fromRod ;					   // takes user input
	cout << "\t to? : ";
	    cin>>toRod;
	if(validateMove(fromRod,toRod)){     //checks to see if move is valid
		switch(fromRod){						//goes over all possbile cases for the moves, clears the command prompt, does the move, and prints the resulting puzzle
			case 1:
				switch(toRod){
					case 2:
						system("cls");
						this->leaderboard();
						move(m_rod1, m_rod2);
						this->incrementMoves();
						this->display();
						break;
					case 3:
						system("cls");
						this->leaderboard();
						move(m_rod1, m_rod3);
						this->incrementMoves();
						this->display();
						break;
				}
				break;
			case 2:
				switch(toRod){
					case 1:
						system("cls");
						this->leaderboard();
						move(m_rod2, m_rod1);
						this->incrementMoves();
						this->display();
						break;
					case 3:
						system("cls");
						this->leaderboard();
						move(m_rod2, m_rod3);
						this->incrementMoves();
						this->display();
						break;
				}
				break;
			case 3:
				switch(toRod){
					case 1:
						system("cls");
						this->leaderboard();
						move(m_rod3, m_rod1);
						this->incrementMoves();
						this->display();
						break;
					case 2:
						system("cls");
						this->leaderboard();
						move(m_rod3, m_rod2);
						this->incrementMoves();
						this->display();
						break;
				}
				break;
				default:
					break;
		}
	} else {
		//invalid move
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		
		SetConsoleTextAttribute(hConsole, 4 );
		cout << " PLEASE PUT A VALID INPUT \n";
		SetConsoleTextAttribute(hConsole, 7 );
		return;
	}
}

void Towers::cheaterMove(){
	unsigned fromRod, toRod;
	cout<< "\t from ? : ";
		cin>> fromRod ;					   // takes user input
	cout << "\t to? : ";
	    cin>>toRod;
	if(validateMove(fromRod,toRod)){     //checks to see if move is valid
		switch(fromRod){						//goes over all possbile cases for the moves, clears the command prompt, does the move, and prints the resulting puzzle
			case 1:
				switch(toRod){
					case 2:
						system("cls");
						move(m_rod1, m_rod2);
						Towers::cheat_header();
						this->display();
						break;
					case 3:
						system("cls");
						move(m_rod1, m_rod3);
						Towers::cheat_header();
						this->display();
						break;
				}
				break;
			case 2:
				switch(toRod){
					case 1:
						system("cls");
						move(m_rod2, m_rod1);
						Towers::cheat_header();
						this->display();
						break;
					case 3:
						system("cls");
						move(m_rod2, m_rod3);
						Towers::cheat_header();
						this->display();
						break;
				}
				break;
			case 3:
				switch(toRod){
					case 1:
						system("cls");
						move(m_rod3, m_rod1);
						Towers::cheat_header();
						this->display();
						break;
					case 2:
						system("cls");
						move(m_rod3, m_rod2);
						Towers::cheat_header();
						this->display();
						break;
				}
				break;
				default:
					break;
		}
	} else {
		//invalid move
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		
		SetConsoleTextAttribute(hConsole, 4 );
		cout << " PLEASE PUT A VALID INPUT \n";
		SetConsoleTextAttribute(hConsole, 7 );
		return;
	}
}

void Towers::cheat_solve(){
	// build recursive solution into an arr or something
	// print index for every move
	
	// build solution 
	cheatSolution(this->m_numDisks,1, 2, 3);

	system("cls"); // clears teh screen
	Towers::cheat_header();
	this->display();
	
	while(true){
		if(this->checkWin()){
			break;
		}
		this->cheaterMove(); // asks the player to move disks until they quit or finish the puzzle
	}
	system("cls"); // clears the screen
	this->display(); 
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 3 );
	cout << "congrats, " << this->m_username << ", kinda...\n" ;
	SetConsoleTextAttribute(hConsole, 7 );
	
	system("PAUSE");
}

void Towers::cheat_header() {
	//m_cheat_solution is queue
	//cout<<(this->m_cheat_solution.front())[1];
	if(this->m_cheat_solution.size() == 0){
		cout << "\n\ngoodbye " << this->m_username << " ... \n"\
				"either u won or screwed up somewhere... :) \n";
		system("PAUSE");
		exit (EXIT_FAILURE);
	}
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 4 );
	cout << "--------------\n"\
			"MOVE : "<<(this->m_cheat_solution.front())[0] << "->" << (this->m_cheat_solution.front())[1] << "\n"\
			"--------------\n";
	SetConsoleTextAttribute(hConsole, 7 );
	if(this->m_cheat_solution.size() > 0){
		this->m_cheat_solution.pop();
	} else {
		cout << "\n\ngoodbye " << this->m_username << " ... ";
		system("PAUSE");
		exit (EXIT_FAILURE);
	}
}

void Towers::play(){
	system("cls"); // clears teh screen
	this->leaderboard();
	this->display(); //displays base game
	//this->incrementMoves();
	while(true){
		if(this->checkWin()){
			break;
		}
		this->playerMove(); // asks the player to move disks until they quit or finish the puzzle
	}
	system("cls"); // clears teh screen
	this->leaderboard();
	this->display(); //displays base game
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	cout << "\n USER " ;
		SetConsoleTextAttribute(hConsole, 3 );
	cout << this->m_username ;
		SetConsoleTextAttribute(hConsole, 7 );
	cout << " finished  ";
		SetConsoleTextAttribute(hConsole, 4 );
	cout << this->getMoves() - ( pow(2,this->getSize()) - 1 ) ;
		SetConsoleTextAttribute(hConsole, 7 );
	cout << "  moves above the minimum\n";
	
	login fin;
	fin.m_username = this->m_username;
	//find username in vector.
	fin.insert_game_data( this->getMoves() - ( pow(2,this->getSize()) - 1 ) );
	cout << " \ncheck out the updated txt file ;) \n";
	
	system("PAUSE");
}

void Towers::leaderboard() {
	cout << "--------------------\n"\
			"Name: " << this->m_username <<"\n"\
			"move counter : "<<this->getMoves()<<"    \n"\
			"                    \n"\
			"min moves : "<< pow(2,this->getSize()) -1  <<"        \n"\
			"--------------------\n";
	cout << endl;
}

void Towers::computer_leaderboard() {
	cout << "--------------------\n"\
			"Name: Computer :)   \n"\
			"move counter : "<<this->getMoves()<<"    \n"\
			"                    \n"\
			"min moves : "<< pow(2,this->getSize()) -1  <<"        \n"\
			"--------------------\n";
	cout << endl;
}

void Towers::choose() {
	system("cls");
	int choice;
	cout << "1 ) Play Towers Of Hanoi. \n"\
			"2 ) Watch Computer Solve TOH. \n"\
			"3 ) Cheat mode. (does not help your score). \n"\
			"4 ) EXIT PROGRAM. \n"\
			"    >> ";
	cin >> choice;
	switch( choice ) {
		case 1:
			Towers::play();
			break;
		case 2:
			Towers::solve();
			std::cout << "\n\npress any key to cont...\n";
			getch();
			system("cls");
			break;
		case 3:
			Towers::cheat_solve();
			break;
		case 4:
			exit (EXIT_FAILURE);
			break;
		default:
			break;
	}
}

bool Towers::checkWin() {
	if ( (this->m_rod1.empty() && this->m_rod2.empty() ) && !(this->m_rod3.empty()) ){
		/*
		    IF FIRST TWO STACKS ARE EMPTY AND THIRD ISNT
		*/
		return true;
	}
	else {
		return false;
	}
}

Towers::~Towers() {
	/* DESTRUCTOR 
	   1) EMPTY ALL RODS
	   2) RESET DISKS NUM AND MOVES TO 0 */

	if( !this->m_rod1.empty() ) {
		for(int i=0; i<this->m_rod1.size(); i++)
			this->m_rod1.pop();
	}
	
	if( !this->m_rod2.empty() ) {
		for(int i=0; i<this->m_rod2.size(); i++)
			this->m_rod2.pop();
	}
	
	if( !this->m_rod3.empty() ) {
		for(int i=0; i<this->m_rod3.size(); i++)
			this->m_rod3.pop();
	}
	
	this->rows = 0;
	this->setSize(0);
	this->setMoves(0);
	
}

