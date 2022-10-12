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
    
    int tc;
    int num[100005];
    while(scanf("%d", &tc) != EOF){
        memset(num, 0, sizeof num);
        for(int i = 0; i < tc; i++) 
            scanf("%d", &num[i]);

        //lis for each element increasing order

        int lis = 0;
        int L[100005];
        int lis_inc[100005];
        for(int i = 0; i < tc; i++){
            int pos = lower_bound(L, L + lis, num[i]) - L;

            L[pos] = num[i];
            lis_inc[i] = pos + 1;
            if(lis < pos + 1){
                lis = pos + 1;
            }
        }

       //lis for decreasing order for each element
        lis = 0;
        int lis_dec[100005];

        for(int i = tc - 1; i >= 0; i--){
            int pos = lower_bound(L, L + lis, num[i]) - L;
            
            L[pos] = num[i];
            lis_dec[i] = pos + 1;
            if(lis < pos + 1){
                lis = pos + 1;
            }
        }

        //print wavio seq size
        int ans = 0;
        for(int i = 0; i < tc; i++){
            ans = max(ans, min(lis_inc[i], lis_dec[i]) * 2 - 1);
        }

        cout<<ans<<'\n';
    }


    return 0;
}