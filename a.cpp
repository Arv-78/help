/*
	author: arv
	UVa 11683 - Laser Sculpture
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	
	int h, l;
	while(scanf("%d %d", &h, &l), h){
		bool sculpted[h] = {false};
		int prev = -1;
		int count = 0;
		int x;
		while(l --){
			cin>>x;
			if(x < h && x >= prev){
				for(int i = x; i < h; i++){
					if(sculpted[i] != true){
						sculpted[i] = true;
						count++;
					}
				}
			}
			if(x < prev){
				count = count + prev - x;
				for(int i = 0; i < h; i++){
					if(i >= x){
						sculpted[i] = true;
					}else{
						sculpted[i] = false;
					}
				}
			}
			prev = x;
			
		}
		cout<<count<<'\n';
	}
	
	return 0;
}