#ifndef TOWERS_H
#define TOWERS_H

#include <stack>

class Towers {
	public :
<<<<<<< HEAD
		//void print() const;
		void solve();//Has the computer complete the puzzle by calling recSolve()
		void buildSolution(unsigned numberOfDisks,unsigned fromRod,unsigned toRod,unsigned usingRod); //recursively builds the solution to the puzzel of NumberOfDiscs
		private :
		// 3 rods to move discs onto 
		stack<int> m_rod1;
		stack<int> m_rod2;
		stack<int> m_rod3;
		// max num of discs should be like 14
		unsigned discs;
=======
	    // Constructors + destructor
		Towers();
		Towers(int h);
		~Towers();
		// accessors
		int getSize( ){ return m_numDisks; }
		// mutators
		void setSize( const int &size) { m_numDisks = size; }
		//functions
		void display(std::stack<int> &rod1, std::stack<int> &rod2, std::stack<int> &rod3, int numDisks);
		
		// public data
		//3 rods to move discs onto 
		std::stack<int> m_rod1;
		std::stack<int> m_rod2;
		std::stack<int> m_rod3;
		
		int rows;
		
	private :
		// max num of discs should be like 14 idk
<<<<<<< HEAD
		unsigned numDisks;
>>>>>>> 1d0e2156d594bd7755e478535791e569a47ce737
=======
		unsigned m_numDisks;
>>>>>>> 121ca1d03f3cf3479a5c7768f40a8c2ba8741135
};

#endif /* TOWERS_H */