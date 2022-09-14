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
    int TC; scanf("%d", &TC);
    int ct = 0;
    while(TC --){
        int r;
        scanf("%d", &r);
        int s[r];
        for(int i = 1; i < r; i++) scanf("%d", &s[i]);

        int sum = 0, ans = 0, maxi = 0, maxj = 0, curi = 1;//3 -4 
        for(int k = 1; k < r; k++){
            sum += s[k];
            if(sum > ans){
                maxi = curi;
                maxj = k + 1;

                ans = sum;
            }
            if(sum == ans && (k + 1 - curi) > (maxj - maxi)){
                maxi = curi;
                maxj = k + 1;
            }
            if(sum < 0){
                curi = k + 1;
                sum = 0;
            }
        }
        
        if(ans > 0)printf("The nicest part of route %d is between stops %d and %d\n", ++ct, maxi, maxj);
        else printf("Route %d has no nice parts\n", ++ct);
    }
    return 0;
}