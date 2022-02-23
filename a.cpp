/*
	author : arv
*/

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;


int main(){
	int n = 5, L[] = {10, 7, 5, 20, 8}, v = 7;
	sort(L, L + n);

	printf("%d\n", binary_search(L, L + n, v));
	return 0;
}