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
    cin>>tc;
    string s;
    getline(cin, s); //for line next to int i.e 2[this line space]
    getline(cin, s); //for gap in between tc and next int
    
    int n;
    while(tc --){
        vector <int> heights;
        //push back until s is ""
        while(getline(cin, s) && s != ""){ heights.push_back(atoi(s.c_str())); }
        n = heights.size();
    
        //finding lis
        vector <int> lis(n + 10, 1);
        int mx_lis = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(heights[i] > heights[j]){
                    lis[i] = max(lis[i], lis[j] + 1);
                }
            }

            mx_lis = max(mx_lis, lis[i]);
        }

        cout<<"Max hits: "<<mx_lis<<'\n';


        //print lis values from heights
        //1. find lis from bottom and this is idx
        //2. if mx_lis - 1 == lis[i] and heights of current idx is greater then heights[i]
        //3. push to stack and update mx_lis and idx
        stack <int> s;
        int i; for(i = n - 1; i >= 0; i--) if(mx_lis == lis[i]) {s.push(heights[i]); break;}
        int idx = i;
        for(i; i >= 0; i--){
            if(mx_lis - 1 == lis[i] && heights[idx] > heights[i]){
                s.push(heights[i]);
                mx_lis = lis[i];
                idx = i;
            }
        }
        while(!s.empty()){
            cout<<s.top()<<'\n';
            s.pop();
        }

        if(tc) cout<<'\n';
    }


    return 0;
}