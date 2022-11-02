#include<bits/stdc++.h>
using namespace std;

int main(){
	// int L[20], L_id[20], P[20];
	
	// int lis = 0, lis_end = 0;
	// for(int i = 0; i < 5; i++){
	// 	int pos = lower_bound(a, a + lis, a[i]) - a;

	// 	L[pos] = a[i];
	// 	L_id[pos] = i;
	// 	P[i] = pos? L_id[pos - 1]: -1;
	// 	if(pos + 1 > lis){
	// 		lis = pos + 1;
	// 		lis_end = i;
	// 	}
	// }
	// //print from lis_end
	// stack <int> s;
	// s.push(a[lis_end]);

	// while(P[lis_end] != -1){
	// 	s.push(a[P[lis_end]]);
	// 	lis_end = P[lis_end];
	// }

	// while(!s.empty()){
	// 	cout<<s.top()<<' ';
	// 	s.pop();
	// }

	int a[] = {-5, 2, 3, -4, 4};

	int lis[5];
	int lis_sz = sizeof(lis)/sizeof(*lis);
	fill_n(lis, sizeof(lis)/sizeof(*lis), 1);

	int max_lis = 0;
	for(int i = 0; i < sizeof(a)/sizeof(*a); i++){
		for(int j = 0; j < i; j++){
			if(a[i] > a[j] && lis[i] < lis[j] + 1)
				lis[i] = lis[j] + 1;
		}
		if(max_lis < lis[i]) max_lis = lis[i];
	}

	stack <int> s;
	int i;
	for(i = 0; i < lis_sz; i++){
		if(max_lis == lis[i]){
			s.push(a[i]);
			break;
		}
	}
	max_lis --;
	for(i - 1; i >= 0; i--){
		if(max_lis == lis[i] && s.top() > a[i]){
			s.push(a[i]);
			max_lis--;
		}
	}

	while(!s.empty()){
		cout<<s.top()<<'\n';
		s.pop();
	}

	return 0;
}