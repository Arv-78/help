/*
	author: arv
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	
	int N,c;
	scanf("%d\n%d",&N,&c);
	while(N--){
		int a,b,gap,prev = 0;
		int flag = 0;
		scanf("%d %d", &a, &b);
		gap = a - b;
		c--;
		while(c--){
			prev = gap;
			scanf("%d %d", &a, &b);
			gap = a - b;
			if(prev != gap){
				flag = 1;
				break;
			}
		}
		cout<<(flag == 1? "no\n\n" : "yes\n\n");
	}


	return 0;
}