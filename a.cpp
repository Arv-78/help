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
    scanf("%d", &tc);
    while(tc --){
        int n;
        scanf("%d", &n);
        vector < pair<int, int> > v;

        for(int i = 0; i < n; i++){
            int w, h;
            scanf("%d %d", &w, &h);
            v.push_back({w, h});
        }

        sort(v.begin(),v.end(),[](pair<int,int>&a,pair<int,int>&b){
             if(a.first==b.first) return a.second < b.second;
             return a.first > b.first;
             });
        // for(auto i : v){
        //     cout<<i.first<<' '<<i.second<<'\n';
        // }

        //if input - 20 30 20 50 40 50 30 40
        //then after sorting
        //40 50
        //30 40
        //20 30
        //20 50
        //find pos for each v[i].second if not found then add it to array and ans++
        int ans = 0;
        vector <int> remaining_dolls;
        for(int i = 0; i < n; i++){
            int pos = upper_bound(remaining_dolls.begin(), remaining_dolls.end(), v[i].second) - remaining_dolls.begin();
            if(pos == remaining_dolls.size()){
                ans++;
                remaining_dolls.push_back(v[i].second);
            }else{
                remaining_dolls[pos] = v[i].second;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}