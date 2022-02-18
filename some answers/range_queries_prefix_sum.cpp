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

int main() //O(n)
{
	/* code */
	// 8
	// 1 3 4 8 6 1 4 2 
	// 2
	// 3 6
	// 1 2
	//ans 19 4
	int n;
	cin>>n;
	for(int i=0; i<n; i++)
	{
		int x;
		cin>>x;
		given[i] = x;
	}
	
	prefix_sum[0] = given[0];
	for(int i=1; i<n; i++)
	{
		prefix_sum[i] = prefix_sum[i-1] + given[i];
	}

	int q;
	cin>>q;
	while(q--)
	{
		int a, b;
		cin>>a>>b;
		a--;	
		b--;
		if(a == 0) // if a = 1 then a-- -> a=0
		{
			cout<<prefix_sum[b]<<'\n';
		}
		else{
			cout<<prefix_sum[b] - prefix_sum[a-1]<<'\n';
		}
		
	}
	
	return 0;
}