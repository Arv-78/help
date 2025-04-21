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

    int m, n;

    while(scanf("%d %d", &m, &n), m || n){
        int t_k;
        if(m == 1 || n == 1){
            t_k = m * n;
        } else if((m == 2 || n == 2)){ // 2x2 -> 4, 2x5 -> 6
            int t = ceil(((m * n) / 4) / 2.0) * 4; // group of 4 divide it by 2
            t += ((m * n) / 4) % 2 == 0 ? ((m * n) % 4) : 0;
            t_k = t;
        } else {
            t_k = ceil(m*n / 2.0);
        }

        printf("%d knights may be placed on a %d row %d column board.\n", t_k, m, n);
    }

    return 0;
}