/*
	author : _arv
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF INFINITY;
#define pi 3.142;

int ar[] = {1, 3, 4, 8, 6, 1, 4, 2}; 

int pre_cal(int a, int b)
{
	int k = ((b - a)+1)/2;
	if(k == 1) //means b-k = b if (k=1)
	{	//1 2 3
		return (ar[a]<ar[b]? (ar[a]<ar[a+1]? ar[a] : ar[a+1]) : (ar[b]<ar[b-1]? ar[b] : ar[b-1]));  //checks for 2 as well as 3 values
		
	}
	
	return(min(pre_cal(a, b-k),pre_cal(a+k, b)));  //(1,3)(4,6) -> 1,2,3 i.e min(3,4,8) and 4,5,6 i.e min(6,1,4)
}

int main() 
{
	/* code */
	//k = range/2 = ((b-a)+1)/2
	// minimum(a, b) = min(minimum(a,b-k),minimum(a+k, b));

	int k = pre_cal(1, 6);
	cout<<k;
	

	return 0;
}