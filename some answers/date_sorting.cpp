/*
	author : arv
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF INFINITY;
#define pi 3.142;

/*
20 1 2014
25 3 2010
3 12 1676
18 11 1982
19 4 2015
9 4 2015
*/

bool sorted(tuple<int, int, int> t1, tuple<int, int, int> t2)
{
	if(get<2>(t1) == get<2>(t2))
	{
		if(get<1>(t1) == get<1>(t2))
		{
			return(get<0>(t1) < get<0>(t2));
		}else{
			return(get<2>(t1) < get<2>(t2));
		}
	
	}else{
		return(get<2>(t1) < get<2>(t2));
	}
}

int main() 
{
	/* code */
	vector <tuple<int, int, int>> ages;
	int N;
	cin>>N;
	while(N--)
	{
		int date; int month; int year;
		cin>>date>>month>>year;
		ages.push_back(make_tuple(date, month, year));
	}
	
	sort(ages.begin(), ages.end(), sorted);
	cout<<'\n';
	for(tuple<int, int, int> t : ages)
	{
		cout<<get<0>(t)<<" "<<get<1>(t)<<" "<<get<2>(t)<<'\n';
	}
 
	return 0; 
}