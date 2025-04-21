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

    int c, stations, left, enter, wait, is_possible, onboard;
    scanf("%d %d", &c, &stations);

    is_possible = 1;  onboard = 0;

    while(stations--){
        scanf("%d %d %d", &left, &enter, &wait);
        onboard -= left;

        if(onboard < 0) is_possible = 0;

        onboard += enter;

        if(onboard > c || ((c - onboard) > 0 && wait > 0)) is_possible = 0;
    }

    if(onboard > 0 || wait > 0 || enter > 0) { // last station - no onboards and no waiting
        is_possible = 0;
    }

    if(is_possible){
        printf("possible");
    } else {
        printf("impossible");
    }

    return 0;
}