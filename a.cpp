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

    vector <int> h;
    vector <int> l;
    int tmp, caseI = 0;
    while(scanf("%d", &tmp) != EOF){
        if(tmp == -1 && h.size() > 0){
            //process h
            int max_interception = 0;
            for(int i = 0; i < h.size(); i++){
                for(int j = 0; j < i; j++){
                    if(h[i] <= h[j]){
                        l[i] = max(l[i], l[j] + 1);
                    }
                }
                max_interception = max(max_interception, l[i]);
            }

             if (caseI)
                cout << endl;
                cout << "Test #" << ++caseI << ":" << endl << 
                "  maximum possible interceptions: " << max_interception << endl;

            h.clear(); l.clear();

        } else {
            h.push_back(tmp);
            l.push_back(1);
        }
    }


    return 0;
}