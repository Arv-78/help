#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool cmp1(pair<double, double> d1, pair<double, double> d2){
    return (d1.first < d2.first);
}

int main()
{  
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif


    int n, l, w;
    while (cin >> n >> l >> w)
    {
        vector<pair<double, double>> circles(10);//check
        for (int i = 0; i < n; ++i)
        {
            double pos, radius;
            cin >> pos >> radius;
            // Calculate this circle's effective interval [L, R].
            // Then this problem is identical to 10020 - Minimal coverage.
            double range = sqrt(radius * radius - (w / 2.0) * (w / 2.0));

            circles[i] = make_pair(pos - range, pos + range);
        }

        // Sort the circles by increasing left endpoint. 
        sort(circles.begin(), circles.end());

        for(pair<double, double> d : circles){
            cout<<d.first<<' '<<d.second<<'\n';
        }

        double last = 0.0, far = 0.0, curl, curr;
        int ct = 0;
        if(n)
        for(int i = 0; i <= circles.size(); i++){
            if(l == 0){break;}
            if(far >= l){ ct++; break;}
            if(circles[i].first <= last)far = max(far, circles[i].second);
            if(circles[i].first > last){
                last = far;
                if(circles[i].first > last){ct = -1; break;}
                ct++;
                i--;
            }
        }
        if(far < l && l)cout<<-1<<'\n';
        else cout<<ct<<'\n';
        
    }
    return 0;
}