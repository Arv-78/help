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
	int a;
	while(scanf("%d", &a), (a != 0)){
		string s;
		cin>>s;
		int dis = a;
		int dd = -a, rd = -a;
		for(int i = 1; i <= a; i++){
			if(s[i - 1] == 'Z'){
				dis = 0;
				break;
			}
			if(s[i - 1] == 'D'){
				dis = min(dis, i - rd);
				dd = i;
			}
			if(s[i - 1] == 'R'){
				dis = min(dis, i - dd);
				rd = i;
			}
			// if(dd && rd){
			// 	if(dd > rd){
			// 		dis = min(dis, dd - rd);
			// 	} else {
			// 		dis = min(dis, rd - dd);
			// 	}
			// }

		}
		cout<<dis<<'\n';


		//gets wrong answer
		// char c;
		// int flag = 0;
		// int i = 0, dis = 20000000;
		// for(i = 0; i < a; i++){
		// 	if(s[i] != '.'){ 
		// 		c = s[i];
		// 		if(c == 'Z')flag = 1;
		// 		i++;
		// 		break;
		// 	}
		// }
		// while(i < a){ 
		// 	int count = 0;
		// 	if(c == 'Z'){
		// 		flag = 1;
		// 		break;
		// 	}
		// 	while(s[i] == '.' && i < a){
		// 		count++;
		// 		i++;
		// 	}
		// 	count++;
		// 	if(s[i] != c && i < a){
		// 		dis = min(dis, count);
		// 		c = s[i];
		// 	}
		// 	i++;
		// }

		// cout<<(flag == 1 ? 0 : dis)<<'\n';

	}
	
	return 0;
}