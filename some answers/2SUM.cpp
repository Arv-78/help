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
	auto l = v.begin();
	auto r = v.end() - 1;
	int exp_s = 12;
	for(int i=0; i<v.size(); i++)
	{
		if(*l + *r == exp_s)
		{
			cout<<*l<<' '<<*r;
			return 0;
		}else if(*l + *r < exp_s) // if left + right < exp_sum then left increments.
		{
			l++;     
		}else{
			r--;   //// if left + right > exp_sum then left increments.
		}
	}

	return 0;
}