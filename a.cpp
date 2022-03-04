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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int N;
	scanf("%d\n", &N);
	
	while(N--){
		string TN;
		int n = 0;
		map <string, int> m;
		while(getline(cin, TN)){
			if(TN.compare("") == 0)
				break;
			m[TN]++;
			n++;
		}
		
		for(map < string, int> :: iterator i = m.begin(); i != m.end(); i++){
			// cout<<i->first<<' '<<((int)(i->second * 10000))/10000.0 <<'\n';
			printf("%s %.4f\n", (i->first).c_str(), (i->second*100.0)/n);
			cout << i->first << " " << fixed << setprecision(4) << i->second*100.0/n << endl;
		}
		if(N)
		printf("\n");
	}
	return 0;
}
// #include <iostream>
// #include <cstdio>
// #include <cstring>
// #include <iomanip>
// #include <map>
// using namespace std;
// int main() {
// 	#ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// 	#endif
// 	int t;
// 	scanf("%d", &t);
// 	getchar();
// 	getchar();
// 	while(t--) {
// 		map<string, int> record;
// 		string tree;
// 		int n = 0;
// 		while(getline(cin, tree)) {
// 			if(tree.compare("") == 0)
// 				break;
// 			record[tree]++;
// 			n++;
// 		}
// 		for(map<string, int>::iterator i = record.begin(); i != record.end(); i++)
// 			cout << i->first << " " << fixed << setprecision(4) << i->second*100.0/n << endl;
// 		if(t)
// 			puts("");
// 	}
//     return 0;
// }