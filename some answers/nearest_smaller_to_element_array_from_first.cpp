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
	stack <int> st;
	int val[] = {1, 3, 4, 2, 5, 3, 4, 2};
	int n = sizeof(val)/sizeof(val[0]);
	st.push(val[0]);
	for(int i=1; i< n; i++)
	{
		if(st.top() < val[i])
		{
			cout<<st.top()<<" <- "<<val[i]<<'\n';
			st.push(val[i]);
			
		}else{
			while(st.top() >= val[i])
			{
				st.pop();
				if(st.empty())
				{
					cout<<"invalid";
					continue;
				}
			}
			cout<<st.top()<<" <- "<<val[i]<<'\n';
			st.push(val[i]);
		}
	}

	return 0;
}