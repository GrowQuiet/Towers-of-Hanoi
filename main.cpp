#include <iostream>
#include "Towers.h"
#include <stack>
#include <windows.h>
#include <cstdlib>
#include <unistd.h>
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()


using namespace std;

int main() {
	
	Towers test;
	//cout << " getSize () : " << test.getSize() << endl;
	//usleep(2323232323223);
	test.display(test.m_rod1, test.m_rod2, test.m_rod3, test.getSize());
	
	return 0;
}
