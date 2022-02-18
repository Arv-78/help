/*
	author : _arv
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF INFINITY;
#define pi 3.142;

vector <int> given(INT16_MAX);

vector <int> prefix_sum(INT16_MAX);

int main() //O(n*n)
{
	/* code */
	//longest increasing subsequence
	int array[] = {6, 2, 5, 1, 7, 4, 8, 3};
	//longest[k] = max(longest[k], longest[i]+1) where i<k;
	//for 1 element default longest subsequence is of size 1;(itself)
	int n = sizeof(array)/sizeof(int);
	int longest[n];

	for(int k=0; k<n; k++)
	{	
		longest[k] = 1;
		for(int i=0; i<k; i++)
		{
			if(array[k] > array[i])
			{
				longest[k] = max(longest[k], (longest[i] + 1));
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout<<longest[i]<<' ';
	}
	
	
	return 0;
}