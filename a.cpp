/*
    author: arv
*/
#include <bits/stdc++.h>
using namespace std;


int V = 10, n = 2, coinValue[] = {1, 5};

int ways(int type, int value){   //O(nV)
    
    if(value == 0) return 1;
    if(value < 0 || type == n) return 0;
    //take or ignore
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = ways(type + 1, value) + ways(type, value - coinValue[i]);
    }
    return ans;
}


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    //coin change

    cout<<ways(0, V);


    return 0;
}