/*
	author: arv
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	
	int t,count = 1;
	while(scanf("%d", &t) != EOF){
		if(count != 1)cout<<'\n';
		count++;
		int nop = t;
		char names [t + 1][13];
		for(int i = 0; i < nop; i++){
			scanf("%s", names[i]);
		}

		int money[t + 1] = {0};
		int left[t + 1] = {0};

		while(t--){
			char giver[100];
			int m, N;
			scanf("%s", giver);
			scanf("%d %d", &m, &N);
			int each = 0; int leftm = 0;
			if(N != 0){
				each = m / N;
				leftm = m % N;
			} else {
				leftm = m;
			}

			for(int i = 0; i < nop; i++){
				if(strcmp(giver, names[i]) == 0){
					money[i] = m;
					left[i] += leftm;
				}
			}

			while(N --){
				char taker[13];
				scanf("%s", taker);
				for(int i = 0; i < nop; i++){
					if(strcmp(taker, names[i]) == 0){
						left[i] += each;
					}
				}
			}
		}
		for (int i = 0; i < nop; i++){
				printf("%s %d\n", names[i], (left[i] - money[i]));
		}		
	}

	return 0;
}