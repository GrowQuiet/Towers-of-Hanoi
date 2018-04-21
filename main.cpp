#include <iostream>
#include "Towers.h"
#include <stack>
#include <windows.h>
#include <cstdlib>

using namespace std;

int main() {
	
	Towers test;
	test.display(test.m_rod1, test.m_rod2, test.m_rod3, test.getSize());
	
	return 0;
}