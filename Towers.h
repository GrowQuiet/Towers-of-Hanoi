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
		int getSize( ){ return numDisks; }
		// mutators
		
		//functions
		void print() const;
		
		// public data
		//3 rods to move discs onto 
		std::stack<int> m_rod1;
		std::stack<int> m_rod2;
		std::stack<int> m_rod3;
	private :
		// max num of discs should be like 14 idk
		unsigned numDisks;
};

#endif /* TOWERS_H */