/*
    author: arv
*/
#include <bits/stdc++.h>
using namespace std;

vector <int> heights_incoming;
int dp[1000001];
int LIS(int i){
    
    if(i == 0) return 1;

    if(dp[i] != -1) return dp[i];
    int ans = 1; //for each number, itself is a subsequence
    for(int j = 0; j < i; j++){
        if(heights_incoming[i] <= heights_incoming[j]){
            ans = max(ans, LIS(j) + 1);
        }
    }
   return dp[i] = ans;
}



int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int h, ct = 0;
    while(scanf("%d", &h) != EOF){
        if(h == -1 && heights_incoming.size() > 0) {
            memset(dp, -1, sizeof dp);
            int max_sub = 0;

            for(int i = 0; i < heights_incoming.size(); i++){
                max_sub = max(max_sub, LIS(i));
            }
            cout<<(ct > 0 ? "\n": "")<<"Test #"<< ++ct <<":\n";
            cout<<"  maximum possible interceptions: ";
            cout<<max_sub<<'\n';
            heights_incoming.clear();
        } else {
            heights_incoming.push_back(h);
        }
    }


    return 0;
}