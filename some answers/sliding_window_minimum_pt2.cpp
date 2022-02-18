/*
	author : _arv
*/

#include<bits/stdc++.h>
#define INF INT16_MAX;

using namespace std;

int main()
{
	/* code */
	int array[] = {2, 1, 4, 5, 3, 4, 1, 2};
	deque <int> q = {1, 4, 5};

	int n = sizeof(array)/sizeof(array[0]);
	
	cout<<q.front()<<'\n';
	for(int i=4; i<n; i++)
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
				while(array[i] <= q.back() && !q.empty())
				{
					q.pop_back();
				}
				q.push_back(array[i]);
			}else if(array[i] >= q.back())
			{
				q.push_back(array[i]);
			}
			
		cout<<q.front()<<'\n';
		
	}

	return 0;	
}