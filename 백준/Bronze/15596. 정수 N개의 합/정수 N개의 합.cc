#include<iostream>
#include<vector>
using namespace std;
long long sum(std::vector<int>&a)
{
	long long result = 0;
	for (vector<int>::iterator iter = a.begin();iter < a.end();iter++)
		result += *iter;


	return result;
}