/*
    author: arv
*/
#include <bits/stdc++.h>
using namespace std;


int V = 10, n = 2, coinValue[] = {1, 5};

int change(int value){   //O(nV)
    if(value == 0) {return 0;}
    if(value < 0) return 1000000;
    
    int ans = 1000000;
    for(int i = 0; i < n; i++){
        ans = min(ans, 1 + change(value - coinValue[i]));
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

    cout<<change(10);


    return 0;
}