/*
	author: arv
	UVA 11559 - Event Planning
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	
	int NoP, bud, h, w;
	while(scanf("%d %d %d %d", &NoP, &bud, &h, &w) != EOF){
		int fbud = 100000000;
		int flag;
		while(h--){
			int hp, ww = w;
			flag = 0;
			scanf("%d", &hp);
			if((hp*NoP) > bud) flag = 1;
			while(ww--){
				int nob;
				scanf("%d", &nob);
				if((nob >= NoP) && flag != 1){
					if(fbud > hp*NoP)fbud = hp * NoP;
				}
			}
		}
		if(fbud == 100000000){
			cout<<"stay home\n";
		} else {
			cout<<fbud<<'\n';
		}
	}
	return 0;
}
