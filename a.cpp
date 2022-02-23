/*
	author : arv
*/

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;


int main(){
	int s[10], N = 10;

	for(int i = 0; i < N; i++) s[i] = i;

	for(int i = 0; i < (1 << N); i++){
		for(int j = 0; j < N; j++){
			if(i & (1 << j)){
				printf("%d ", s[j]);
			}
		}
		printf("\n");
	}
	
	return 0;
}