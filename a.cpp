/*
	author : arv
*/

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;

int main()
{
	
	#ifndef ONLINE_JUDGE
 
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);
 
    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);
 
	#endif
	while(1){
		int T, NOD, j = 1;
		float DP, L, CP, MP;
		float DR[101] = {0.0};
		scanf("%d %f %f %d", &T, &DP, &L, &NOD);
		 MP = L / T;
		 CP = L + DP;
		if(T < 0) break;
		while(NOD --){
			int i;
			scanf("%d", &i);
			scanf("%f",&DR[i]);
		}
		CP = CP - (CP * DR[0]);
		
		while(T--){
			if(DR[j] == 0){
				DR[j] = DR[j-1];
			}
			CP = CP - (CP * DR[j]);
			L = L - MP;
			if(CP > L) break;
			j++;
		}
		printf("%d %s\n", j, (j == 1)? "month" : "months");
	}
			
	
	return 0;
}
