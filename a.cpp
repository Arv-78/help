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
    
    int n, l, w;
    while(scanf("%d %d %d", &n, &l, &w) == 3){
        vector <pair<double, double>> v(10000);

        for(int i = 0; i < n; i++){
            double pos, r;
            scanf("%lf %lf", &pos, &r);
            double range = sqrt(r*r - w/2.0 * w/2.0);
            v[i] = make_pair((double)pos - range, double(pos) + range);
        }

        sort(v.begin(), v.end());

        


        double last = 0.0, far = 0.0;
        int ct = 0;
        for(int i = 0; i <= v.size(); i++){
            if(l == 0){ct = -1; break;}
            if(far >= l){ct++; break;}
            if(v[i].first <= last)far = max(far, v[i].second);
            if(v[i].first > last){
                last = far;
                if(v[i].first > last){ct = -1; break;}
                ct++;
                i--;
            }
        }
        if(far < l)cout<<"-1\n"; 
        else cout<<ct<<'\n';
    }


    return 0;
}