#include <iostream>
#include "Towers.h"
#include <stack>
#include <queue>

using namespace std;

<<<<<<< HEAD
void Towers::solve() 
{
	recSolve(numDisks,1,3,2)	
}
=======
void buildSolution(unsigned numberOfDisks,unsigned fromRod,unsigned toRod,unsigned usingRod)
{
	queue<pair<int,int>> moves;
	if(numberOfDisks == 1)
	{
		moves.push((fromRod,toRod));
	}
	else
	{
		recSolve(numberOfDisks-1,fromRod,usingRod,toRod);
		moves.push((fromRod, toRod));
		recSolve(numberOfDisks-1,usingRod,toRod,fromRod);
	}
	for(int i = 0; i < moves.size();i++){
		cout<<moves.pop()<<endl;
	}
	return;
}
=======
Towers::Towers() {
	cout << "teest " <<endl;
	
}

>>>>>>> 1d0e2156d594bd7755e478535791e569a47ce737
