/*
	author : _arv
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF INFINITY;
#define pi 3.142;

int p(int k)
{
	int i = 3; //depends upon size of array pow(2, 3) == 8
	while(k % (int)(pow(2, i)) != 0)
	{
		i--;
	}
	return pow(2, i);
}

int main() 
{
	/* code */
	//binary indexed tree array implementation
	//formula p(k) = largest value of power of two that divides k completely
	//tree[k] = sum(k-p(k) + 1 , k); //where p(k)<=k if k=8; p(k) = 8(2^3=8)

	int array[] = {1, 3, 4, 8, 6, 1, 4, 2};
	int n = sizeof(array)/sizeof(int);
	int tree[n+1];
	//tree[0] = 0;
	for(int k = 0; k<=n; k++)
	{
		tree[k] = 0;
		for(int i = (k+1)-p(k+1)+1; i <= (k+1); i++)
		{
			tree[k] += array[i-1];
		}
	}
	//prints all values
	for(int i = 0; i<n; i++){
		cout<<tree[i]<<' ';
	}


	//calculate sum(1,6) here k = 6
	int sum = 0;
	int k = 6;
	while(k>=1)
	{
		sum += tree[k-1];
		k -= k&-k;
	}
	cout<<'\n'<<"sum = "<<sum;

	//increase value at tree[x] by 2; 
	int x = 2;
	while(x <= n)
	{
		tree[x-1] += 2;
		x += x&-x;
	}
	//prints all values
	cout<<'\n';
	for(int i = 0; i<n; i++){
		cout<<tree[i]<<' ';
	}
	return 0;
}