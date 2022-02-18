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
	
	vector <int> v = {1, 4, 5, 6, 7, 9, 9, 10};  //must be sorted

	auto between = v.begin() + 1;
	int exp_s = 12;

	for(int i=0; i<v.size()-2; i++)
	{
		auto l = v.begin();
		auto r = v.end() - 1;

		while(l < r)
		{
			if(l == between) {l++;} 
			if(r == between) {r--;}
			if((*l + *between + *r) == exp_s)
			{
				cout<<*l<<' '<<*between<<' '<<*r<<'\n';
				break;
			}else if((*l + *between  + *r) < exp_s) // if left + between + right < exp_sum then left increments.
			{
				l++;     
			}else{
				r--;   //// if left + between + right > exp_sum then left increments.
			}
		}
		between ++;
		
	}

	return 0;
}