/*
	author : arv
*/

#include <bits/stdc++.h>

using namespace std;

#define ALL(x) 
#define UNIQUE(c) 

int main(){
	//gives unique elements in the array
	int a[] = {1, 2, 2, 2, 3, 3, 2, 2, 1};
	vector<int> v(a, a + 9);
	sort(v.begin(), v.end());
	//unique replaces the first duplicate elemets with unique i.e. {1, 2, 3,...}
	//unique returns iterator to last element which is not removed
	int d = (unique(v.begin(), v.end()) - v.begin()); //gives distance between to iterators
	v.resize(d);//resize to d = 3 elements
	for(int i = 0; i < d; i++){
		printf("%d\n", v[i]);
	}
	return 0;
}