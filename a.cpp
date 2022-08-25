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
	
	int t;
	while(scanf("%d", &t), t){
		int dir = 0;
		t--;
		while(t--){
			string s;
			cin>>s;
			//x+ 0 x- 1 y+ 2 y- 3 z+ 4 z- 5
			if(s == "No")continue;
			if(s == "+y"){
				if(dir == 0) dir = 2;
				else if(dir == 1) dir = 3;
				else if(dir == 2) dir = 1;
				else if(dir == 3) dir = 0;
			}
			if(s == "-y"){
				if(dir == 0) dir = 3;
				else if(dir == 1) dir = 2;
				else if(dir == 2) dir = 0;
				else if(dir == 3) dir = 1;
			}
			if(s == "+z"){
				if(dir == 0) dir = 4;
				else if(dir == 1) dir = 5;
				else if(dir == 4) dir = 1;
				else if(dir == 5) dir = 0;
			}
			if(s == "-z"){
				if(dir == 0) dir = 5;
				else if(dir == 1) dir = 4;
				else if(dir == 4) dir = 0;
				else if(dir == 5) dir = 1;
			}
		}
		if(dir == 0) cout<<"+x\n";
		if(dir == 1) cout<<"-x\n";
		if(dir == 2) cout<<"+y\n";
		if(dir == 3) cout<<"-y\n";
		if(dir == 4) cout<<"+z\n";
		if(dir == 5) cout<<"-z\n";
	}
	
	return 0;
}