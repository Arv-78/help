/*
    author: arv
*/
#include <bits/stdc++.h>
using namespace std;

int sc;
int killed[1025][1025];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    scanf("%d", &sc);
    while(sc--){
        int d, n;
        int x, y, sz;
        scanf("%d %d", &d, &n);
        memset(killed, 0, sizeof(killed));
        while(n--){
            scanf("%d %d %d", &x, &y, &sz);
            int xl = max(0, x - d); int xr = min(1024, x + d);
            int yb = max(0, y - d); int yu = min(1024, y + d);
            for(int i = xl; i <= xr; i++){
                for(int j = yb; j <= yu; j++){
                    killed[i][j] += sz;
                }
            }
        }

        int kill = -1;
        int chosen_x = 0;
        int chosen_y = 0;
        for(int j = 0; j < 1025; j++){
            for(int i = 0; i < 1025; i++){
                if(killed[j][i] > kill){
                    kill = killed[j][i];
                    chosen_x = j;
                    chosen_y = i;
                }
            }
        }
        printf("%d %d %d\n", chosen_x, chosen_y, kill);
    }
    return 0;
}