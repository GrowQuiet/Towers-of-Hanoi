#ifndef TOWERS_H
#define TOWERS_H

#include <stack>

class Towers {
	public :
		//void print() const;
	private :
		// 3 rods to move discs onto 
		stack<int> m_rod1;
		stack<int> m_rod2;
		stack<int> m_rod3;
		// max num of discs should be like 14
		unsigned discs;
};

#endif /* TOWERS_H */