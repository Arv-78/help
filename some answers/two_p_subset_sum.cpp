/*
	author : _arv
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF INFINITY;
#define pi 3.142;

int main() //O(n)
{
	/* code */
	int array[] = {1, 3, 2, 5, 1, 1, 2, 3};

	int n = sizeof(array)/sizeof(array[0]);
	int *r = array + 1,*l = array;
	//1. do r++; until sum of *l to *r < sum if = sum found!
	//2. sum of *l to *(r+1) > sum  do l = r; until sum of *l to *(r+!) <= sum 
	
	int sum = *r;
	int x = 8; ///the expected sum
	
	while(r != array + (n-1))//while r is not equal to end
	{
		if((sum + *(r+1)) <= x) // sum between *l and *(r + 1) 
		{
			r++;
			sum += *r;
			if(sum == x)
			{
				cout<<"YES";
				return 0;
			}
		}
		else{   // if sum between *l and *(r + 1) > x
			//l = r;
			sum = *r;
		}
		
	}

	return 0;
}