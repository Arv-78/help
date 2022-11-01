#include<bits/stdc++.h>
using namespace std;

int main(){
	int L[20], L_id[20], P[20];
	int a[] = {-5, 2, 3, -4, 4};
	int lis = 0, lis_end = 0;
	for(int i = 0; i < 5; i++){
		int pos = lower_bound(a, a + lis, a[i]) - a;

		L[pos] = a[i];
		L_id[pos] = i;
		P[i] = pos? L_id[pos - 1]: -1;
		if(pos + 1 > lis){
			lis = pos + 1;
			lis_end = i;
		}
	}
	//print from lis_end
	stack <int> s;
	s.push(a[lis_end]);

	while(P[lis_end] != -1){
		s.push(a[P[lis_end]]);
		lis_end = P[lis_end];
	}

	while(!s.empty()){
		cout<<s.top()<<' ';
		s.pop();
	}

	return 0;
}