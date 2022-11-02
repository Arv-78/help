#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int table[20][20];

	int a[] = {2, 3, 1, 4, 6, 8, 10, 9, 5, 7};
	int b[] = {3, 1, 4, 6, 8, 10, 9, 5, 7, 2};
	int N = 10;
	fill_n(*table, sizeof table / sizeof **table, 0);

	int i, j;

	for(i = 1; i <= N; i++){
		for(j = 1; j <= N; j++){
			if(a[i - 1] == b[j - 1]){
				table[i][j] = table[i - 1][j - 1] + 1;
			}else{
				table[i][j] = max(table[i - 1][j], table[i][j - 1]);
			}
		}
	}
	//LCS at table[N][N]
	cout<<table[N][N];

	return 0;
}