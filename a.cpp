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

    vector <int> v;
    int t;
    while(scanf("%d", &t) == 1)
        v.push_back(t);

    vector <int> lis(v.size(), 1);
    int mx_lis = 0;
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < i; j++){
            if(v[i] > v[j]){
                if(lis[i] < lis[j] + 1)
                    lis[i] = lis[j] + 1;
            }
        }
        if(lis[i] > mx_lis) mx_lis = lis[i];
    }

    int seq[mx_lis];
    int top = mx_lis - 1;
    int i;
    for(i = v.size() - 1; i >= 0; i--) if(mx_lis == lis[i]) { seq[top] = v[i]; break;}
    
    for(int j = i - 1; j >= 0; j--){
        if(lis[i] - 1 == lis[j] && v[i] > v[j]){
            seq[--top] = v[j];
            i = j;
        }
    }

    cout<<mx_lis<<'\n'<<'-'<<'\n';
    for(int i = 0; i < mx_lis; i++)
        cout<<seq[i]<<'\n';
    return 0;
}