/*
 * Pointers.cpp
 *
 *  Created on: Aug 25, 2020
 *      Author: Sayanta
 */

#include <iostream>

int main()
{
	using namespace std;
	int y;
	cin >> y;
	int x=10;
	int *pt1= &x;
	int *pt2=nullptr;
	pt2=&y;
	cout << x << " "<< *pt1 <<endl;
	cout << &x << " " << pt1 << endl;
	cout << y << " " << *pt2 << endl;
	cout << &y << " " << pt2 <<endl;
}

