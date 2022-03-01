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

	map<string, map<string, string>> B;

	B["+x"]["+y"] = "+y";
	B["+x"]["-y"] = "-y";
	B["+x"]["+z"] = "+z";
	B["+x"]["-z"] = "-z";

	B["-x"]["+y"] = "-y";
	B["-x"]["-y"] = "+y";
	B["-x"]["+z"] = "-z";
	B["-x"]["-z"] = "+z";

	B["+y"]["+y"] = "-x";
	B["+y"]["-y"] = "+x";
	B["+y"]["+z"] = "+y";
	B["+y"]["-z"] = "+y";

	B["-y"]["+y"] = "+x";
	B["-y"]["-y"] = "-x";
	B["-y"]["+z"] = "-y";
	B["-y"]["-z"] = "-y";

	B["+z"]["+y"] = "+z";
	B["+z"]["-y"] = "+z";
	B["+z"]["+z"] = "-x";
	B["+z"]["-z"] = "+x";

	B["-z"]["+y"] = "-z";
	B["-z"]["-y"] = "-z";
	B["-z"]["+z"] = "+x";
	B["-z"]["-z"] = "-x";

	string DW, D;
	long L;
	for( ; ; ){
		DW = "+x";
		scanf("%d", &L);
		if (L == 0) break;
		for(long i = 1; i < L; i++){
			cin >> D;
			if(D != "No"){
				DW = B[DW][D];
			}
		}

		cout << DW << '\n';

	}
	
	

	return 0;
}
