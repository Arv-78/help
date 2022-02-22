/*
	author : arv
*/

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;


int main(){
	vector <iii> v;

    iii A = make_pair(ii(5, 24), -1982);
	iii B = make_pair(ii(5, 24), -1980);
	iii C = make_pair(ii(11, 13), -1983);
	v.push_back(A);
	v.push_back(B);
	v.push_back(C);

	sort(v.begin(), v.end());

	for(int i = 0; i<v.size(); i++){
		printf("%d \t %d \t %d \n", v[i].first.first, v[i].first.second, v[i].second);
	}
	return 0;
}