#ifndef LOGIN_H
#define LOGIN_H

#include <vector>
#include <string>
#include "Towers.h"

class login{
	public:
		void sign_in(); //alows a user to signup an act
		void sign_up(); //alows a user to sign up for an act
		bool check_text( std::string txt, int index ); 
		/* 
			check_text finds if a desired string in a certain index, defined below, exists.
		
		  txt file format :
			[0] username
			[1] pass
			[2] score (lower is better,0 is lowest)
			[3] # games played

		*/
		bool check_login( std::string username ); //similar to check_txt, but ass for password input.
		void print_menu();
		void generate_vector(); //fills initial vector.
		void clear_vector(); //clears _playerData
		void play_game(); //plays toh game after succesfully logging in
		void insert_game_data( int score ); //reupdates table based off of score
		std::vector< std::vector<std::string> > m_playerData;
		std::string m_username;
		login();
		~login();
};


#endif /* LOGIN_H */
