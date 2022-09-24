/*
    author: arv
*/
#include <bits/stdc++.h>
using namespace std;


int V = 10, n = 2, coinValue[] = {1, 5};
int memo[10][1000]; //memo[type][value];
int ways(int type, int value){   //O(nV)
    
    if(value == 0) return 1;
    if(value < 0 || type == n) return 0;

    if(memo[type][value] != -1) return memo[type][value];
    //take or ignore
    int ans = 0;
    //for(int i = 0; i < n; i++){
        ans = ways(type + 1, value) + ways(type, value - coinValue[type]);
    //}
    return memo[type][value] = ans;
}


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    //coin change
    memset(memo, -1, sizeof memo);
    cout<<ways(0, V);


    return 0;
}