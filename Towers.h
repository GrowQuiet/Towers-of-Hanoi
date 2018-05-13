#ifndef TOWERS_H
#define TOWERS_H

#include <stack>
#include <string>
#include <vector>
#include <queue>

class Towers {
	public :
	    // Constructors + destructor
		Towers();
		Towers(int h);
		~Towers();
		
		// accessors
		int getSize( ){ return m_numDisks; }
		int getMoves( ){ return m_moves; }
		// mutators
		void setSize( const int &size) { m_numDisks = size; }
		void setMoves( const int &moves) { m_moves = moves; }
		void incrementMoves( ) { m_moves += 1; }
		
		//functions
		void display( ); //dislpays recursively 
		void solve();//Has the computer complete the puzzle by calling buildSolution
		void buildSolution(unsigned numberOfDisks,std::stack<std::pair<int,int> > &fromRod,std::stack<std::pair<int,int> > &usingRod,std::stack<std::pair<int,int> > &toRod); //recursively builds the solution to the puzzel of NumberOfDiscs
		void move( std::stack<std::pair<int,int> > &rod1, std::stack<std::pair<int,int> > &rod2); // moves a disk from one rod to another.
		void playerMove(); //idk why we have two lol
		void play(); //allowsfor user input
		bool validateMove(int fromRod, int toRod); //sees if the move desired is valid
		void leaderboard(); //displays username and moves vs min
		void computer_leaderboard();//shows computer moves
		bool checkWin(); //checks to see if the game is wonnered
		void choose(); //main menu to choose what game mode.
		void cheat_solve(); //prints what move should be executed next.
		void cheaterMove(); // cheats play.
		void cheat_header(); //displays what next move SHOULD be...
		void cheatSolution(int n,int one, int two,int three);
		// public data
		/* stack<array<int, 2>> arrs;
		arrs.push({1, 2}); */
		//3 rods to move discs onto 
		std::stack<std::pair<int,int> > m_rod1;
		std::stack<std::pair<int,int> > m_rod2;
		std::stack<std::pair<int,int> > m_rod3; 
		
		//std::stack<int> m_rod1;
		//std::stack<int> m_rod2;
		//std::stack<int> m_rod3;
		
		int rows;
		std::string m_username;
		std::queue< std::vector<int> > m_cheat_solution;
		
	private :
		// max num of discs should be like 14 idk
		unsigned m_numDisks;
 		unsigned m_moves; //# moves performed
};

#endif /* TOWERS_H */

