#include <iostream>
#include <vector>
#include <fstream>
#include <conio.h>
#include <string>
#include <stdlib.h>     /* exit, EXIT_FAILURE */
#include <sstream>      // std::stringstream
#include "login.h"
#include <windows.h>
#include "Towers.h"

using namespace std;

login::login(){
	//constructor
	/* 
		SETUP OF TXT FILE
		USERNAME \t PASS \t AVG ABOVE MIN MOVES \t NUM OF GAMES PLAYED
	*/

	login::generate_vector();	

}

void login::generate_vector(){
	//std::vector< std::vector<std::string> > m_playerData
	//   is the member vector data

	string line;
    ifstream myfile ("users.txt");
 
    if ( myfile.is_open() ) {
        while ( getline (myfile,line) ) //while thre is a line to take
        {
           stringstream ss(line); //stringstream constructor
           vector<string> row;	//row in a form of a vec
           string entry;
 
           while (ss >> entry)	//while there is whitespace, i.e, a tab
			   row.push_back(entry); //pushes tab deliminated data into row
           this->m_playerData.push_back(row); //pushes row into vector 
		   //we end up with a 2d array ish structure as a vec
        }
        myfile.close();
    }
    else cout << "Unable to open file";

	/*for(int i=0; i<this->m_playerData.size(); i++){
		for(int j=0; j<(this->m_playerData[0]).size(); j++ ){
			cout << this->m_playerData[i][j];
		}
		cout << endl;
	}
	just prints.*/
}

void login::sign_in() {
	/*
		1) check if name exists
		2) check if password matches password
	*/
	system("cls");
	std::string username;
	std::cout << "enter username >> ";
	std::cin >> username;

	bool success = login::check_login( username );

	if(success){
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 2 );
		std::cout<<"    SUCCESS!!";
		SetConsoleTextAttribute(hConsole, 7 );
		std::cout << "\n\npress any key to cont...\n";
		getch();
		system("cls");
		// GO TO PLAY GAME
		this->m_username = username;
		login::play_game();
	} else {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 4 );
		std::cout << "    FAILURE. TRY AGAIN WITH VALID USERNAME";
		SetConsoleTextAttribute(hConsole, 7 );
		std::cout << "\n\npress any key to cont...\n";
		getch();
		system("cls");
	}
	return ;
}

void login::sign_up() {
	/*
		1) check if name taken
		2) insert data
	*/
	system("cls");
	std::string username;

	std::cout<<"Enter desired username. ( no spaces allowed! )\n"\
			   "    >> ";
	std::cin >> username;

	//after entering a username, check if it exists.
	bool verify = login::check_text(username, 0);
	if ( !verify ) {
		//enter a password and enter it into the 'database'
		std::string password;
		std::cout << "enter a password,  buddy. \n"\
					 "    >> ";
		std::cin >> password;
		//SAVE TO FILE
		ofstream myFile;
		myFile.open("users.txt");
		for(int i=0; i<this->m_playerData.size(); i++){
			myFile << this->m_playerData[i][0] << "\t" << this->m_playerData[i][1] << "\t" << this->m_playerData[i][2] << "\t" << this->m_playerData[i][3];
			myFile << "\n";
		}
		//myFile << "\n";
		myFile << username << "\t" << password << "\t" << "0" << "\t" << 0;
		myFile.close();
		
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 2 );
		std::cout << "    Account created successfulyl! please login to play!";
		SetConsoleTextAttribute(hConsole, 7 );
		std::cout << "\n\npress any key to cont...\n";
		getch();
		system("cls");
		login::clear_vector();
		login::generate_vector();
		return ;
	} else {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 4 );
		std::cout << "Username taken already. try again. \n";
		SetConsoleTextAttribute(hConsole, 7 );
		std::cout << "\n\npress any key to cont...\n";
		getch();
		system("cls");
		return ;
	}
}

bool login::check_login( string username ){

	for( int i = 0; i < this->m_playerData.size(); i++ ){
		if ( this->m_playerData[i][0] == username ){
			std::string password;
			std::cout << "enter your password >> ";
			std::cin >> password;
			if ( this->m_playerData[i][1] == password ) 
				return true;
		}
	}

	return false;
}

bool login::check_text( string txt, int index ) {
	//checks if name or password exists
	//we suffer with search timing this way using vectors. but it makes manipulating easier.
	//for loop to go through each row. then check first entry (0)
	for( int i = 0; i < this->m_playerData.size(); i++ ){
		if ( this->m_playerData[i][index] == txt )
			return true; //found
	}
	return false; //exited without finding
}

void login::print_menu() {
	int choice;

	while(true){
		system("cls");
		std::cout << "1) Login\n"\
			"2) Sign-up\n"\
			"3) EXIT\n"\
			"    >> ";
		std::cin >> choice;
		switch(choice){
			case 1:
				//LOG IN
				login::sign_in();
				break;
			case 2:
				//sign_up
				login::sign_up();
				break;
			case 3:
				exit (EXIT_FAILURE);
				break;
			default:
			std::cout << " wrong choice. \n";
				break;
		}
	}
	
}

void login::clear_vector(){
	this->m_playerData.clear();
}

void login::play_game() {
	// PLAYS TOH
	Towers game;
	game.m_username = this->m_username;
	game.choose();
}

void login::insert_game_data( int score ) {
	// 1 FIND USERNAME IN STRUCTURE
	int index = 0;
	for( index = 0; index < this->m_playerData.size(); index++ ){
		if( this->m_playerData[index][0] == this->m_username )
			break;
	}
	//index is now index of that username.
	int gamesPlayed = atoi((this->m_playerData[index][3]).c_str()); 
	gamesPlayed += 1;
	
	int new_score = atoi((this->m_playerData[index][2]).c_str());
	new_score += score;
	
	// this is c++ 98 so int-> char is confusing
	// basically prints int to ostream then is read by a string in istream...#notspaghetti #trueProductionCode
	string sc = static_cast<ostringstream*>( &(ostringstream() << new_score) )->str();
	string gP = static_cast<ostringstream*>( &(ostringstream() << gamesPlayed) )->str();
	
	// replace new strings with old in m_playerData
	this->m_playerData[index][2] = sc;
	this->m_playerData[index][3] = gP;
	
	//EMPTY THIS INTO THE FILE AND QUIT
	ofstream myFile;
	myFile.open("users.txt");
	for(int i=0; i<this->m_playerData.size()-1; i++){
		myFile << this->m_playerData[i][0] << "\t" << this->m_playerData[i][1] << "\t" << this->m_playerData[i][2] << "\t" << this->m_playerData[i][3];
		myFile << "\n";
	}
	int max = this->m_playerData.size()-1;
	myFile << this->m_playerData[max][0] << "\t" << this->m_playerData[max][1] << "\t" << this->m_playerData[max][2] << "\t" << this->m_playerData[max][3];
	myFile.close();
}

login::~login(){
	login::clear_vector();
	this->m_username="";
}
