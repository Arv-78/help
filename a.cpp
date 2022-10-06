/*
    author: arv
*/
#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100000

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int v[MAX_N];
    
    int t; int n = -1;
    while(scanf("%d", &v[++n]) == 1){}

    int L[MAX_N], L_id[MAX_N], P[MAX_N];

    int lis = 0, lis_end = 0;
    for(int i = 0; i < n; i++){
        //get position for v[i] for current lis
        //if(L[k] >= v[i]) pos = k
        int pos = lower_bound(L, L + lis, v[i]) - L;
        //for pos update L and index in L_id

        L[pos] = v[i]; 
        L_id[pos] = i;
        //take previous i from L_id for pos
        P[i] = pos? L_id[pos - 1] : -1;
        //update lis and lis_end
        if(pos + 1 > lis){
            lis = pos + 1;
            lis_end = i;
        }
    }
    
    cout<<lis<<'\n'<<'-'<<'\n';

    int x = lis_end;
    stack <int> s;
    while(x != -1){
        s.push(v[x]);
        x = P[x];
    }

    while(!s.empty()){
        cout<<s.top()<<'\n';
        s.pop();
    }
    return 0;
}