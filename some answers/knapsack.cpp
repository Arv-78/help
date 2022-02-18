/*
	author : _arv
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF INFINITY;
#define pi 3.142;

int main() 
{
	/* code */
	
	int max_sum = 12;
	bool possible[13] = {false};
	possible[0] = true;
	int w[] = {1, 3, 3, 5};
	for(int i=0; i<4; i++)
	{
		for(int k=max_sum; k>=0; k--)
		{
			if(possible[k] == true)
			{
				possible[k + w[i]] = true;
			}
		}
		
	}
	
	for(int i = 0; i<13; i++)
	{
		if(possible[i] == true) {cout<<i<<'\n';}
	}

	return 0;
}