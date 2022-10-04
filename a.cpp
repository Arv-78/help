/*
    author: arv
*/
#include <bits/stdc++.h>
using namespace std;

bool compare(vector <int> a, vector <int> b){
    if(a[0] != b[0]){
        return a[0] > b[0];
    } 

    return a[1] > b[1];
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    /*
    1. make permutations of x, y, z
    2. sort in decending order
    3. DP[sizeofno of permutations] = heights
    4. for each i from permuations check if j (from i + 1 to v.size())
     i's x, y are > j's x, y then if DP[j] < DP[i] + v[j][2] then update DP[j]
    5. get the large value of height from DP
    */



    int N; int Case = 0;
    int ar[3], tmp[3];

    vector <vector <int> > v;
    while(scanf("%d", &N) == 1, N){
        v.clear();
        while(N--){
            for(int i = 0; i < 3; i++){
                scanf("%d", &ar[i]);
            }
            if(ar[0] < ar[1]){
                swap(ar[0], ar[1]);
            }
            tmp[0] = ar[0];tmp[1] = ar[1];tmp[2] = ar[2];
            v.push_back({ar[0], ar[1], ar[2]});
            ar[0] = tmp[0]; ar[1] = tmp[1]; ar[2] = tmp[2];
            swap(ar[0], ar[2]);
            if(ar[0] < ar[1]){
                swap(ar[0], ar[1]);
            }
            v.push_back({ar[0], ar[1], ar[2]});
            ar[0] = tmp[0]; ar[1] = tmp[1]; ar[2] = tmp[2];
            swap(ar[1], ar[2]);
            if(ar[0] < ar[1]){
                swap(ar[0], ar[1]);
            }
            v.push_back({ar[0], ar[1], ar[2]});
        }
        sort(v.begin(), v.end(), compare);
    

        //find lis
        int DP[v.size()] = {};
        for(int i = 0; i < v.size(); i++){
            DP[i] = v[i][2];
        }

        for(int i = 0; i < v.size(); i++){
            for(int j = i + 1; j < v.size(); j++){
                if((v[i][0] > v[j][0] && v[i][1] > v[j][1]) || (v[i][0] > v[j][1] && v[i][1] > v[j][0])){
                    if(DP[j] < DP[i] + v[j][2]){
                        DP[j] = DP[i] + v[j][2];
                    }
                }
            }
        }

        int ans = 0;
        for(int i : DP){
            if(i > ans) ans = i;
        }
        printf("Case %d: maximum height = %d\n", ++Case, ans);
    }
    return 0;
}