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
    int n;
    while(scanf("%d", &n), n){
        int N[10000];
        for(int i = 0; i < n; i++)scanf("%d", &N[i]);
        int max_streak = -999999, sum = 0;
        for(int i = 0; i < n; i++){
            sum += N[i];
            if(sum > max_streak)
                max_streak = sum;
            if(sum < 0) sum = 0;
        }
        if(max_streak <= 0)
            printf("Losing streak.\n");
        else
            printf("The maximum winning streak is %d.\n", max_streak);
    }
    
    return 0;
}