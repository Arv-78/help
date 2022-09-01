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
    int n, m;
    while(cin>>n>>m, (n||m)){   
        int p[n];
        for(int i = 0; i < n; i++) p[i] = i;

        vector <tuple<int, int, int>> v;
        for(int i = 0; i < m; i++){
            int a, b, c;
            cin>>a>>b>>c;
            v.push_back(make_tuple(a, b, c));
        }
        int counter = 0;
        do{
            if(m){
                bool pass = true;
                for(int i = 0; i < m; i++){
                    int a, b, c; // store it
                    a = get<0>(v[i]);
                    b = get<1>(v[i]);
                    c = get<2>(v[i]);
                    int pos_a, pos_b;
                    for(int i = 0; i < n; i++){
                        if(p[i] == a) pos_a = i;
                        if(p[i] == b) pos_b = i;
                    }
                    int mx,mn;
                    mx = max(pos_a, pos_b);
                    mn = min(pos_a, pos_b);

                    if(!((c > 0 && mx - mn <= c) || (c < 0 && mx - mn >= c*(-1))))
                        pass = false;
    
                }

                if(pass)counter++;

            }else{
                counter++;
            }
            
        }while(next_permutation(p, p + n));

        std::cout<<counter<<'\n';
    }
    return 0;
}