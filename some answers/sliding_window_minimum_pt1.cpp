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
	int array[] = {2, 1, 4, 5, 3, 4, 1, 2};
	deque <int> q;

	int n = sizeof(array)/sizeof(array[0]);

	for(int i=0; i<n; i++)
	{
		if(q.empty())
		{
			q.push_back(array[i]);
		}else 
		{
			if(i >= 4) 
			{
				
				if(array[i-4] == q.front()) 
				{
					q.pop_front();
				}	
				
			}
			if(array[i] <= q.back())
			{
			
				while(array[i] <= q.back())
				{
					
					q.pop_back();
					if(q.empty()) break;
				}
				q.push_back(array[i]);
			}else if(array[i] >= q.back())
			{
				q.push_back(array[i]);
			}
			if(i >= 3)
			{
				cout<<q.front()<<'\n';
			}
		
		}
		
	}

	return 0;
}