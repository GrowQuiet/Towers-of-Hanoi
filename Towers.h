#ifndef TOWERS_H
#define TOWERS_H

#include <stack>

class Towers {
	public :
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
		unsigned m_numDisks;
};

#endif /* TOWERS_H */