/*
 * pathparser.cpp
 *
 *  Created on: 2014/3/5
 *      Author: mikekao
 */

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);

	for (int i=0; i<a.size(); ++i)
		cout << a[i] << endl;

	return 0;
}


