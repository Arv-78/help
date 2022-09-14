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
    
    int price[25][25];
    bool reachable[3][210];
    int M, C;
    int TC, score;
    scanf("%d", &TC);
    while(TC --){
        scanf("%d %d", &M, &C);
        for(int i = 0; i < C; i++){
            scanf("%d", &price[i][0]);//k
            for(int j = 1; j <= price[i][0]; j++){
                scanf("%d", &price[i][j]);
            }
        }
    
        memset(reachable, false, sizeof reachable);
        //filling base cases
        for(int i = 1; i <= price[0][0]; i++){
            if(M - price[0][i] >= 0) reachable[0][M - price[0][i]] = true;
        }

        //filling dp table bottom up approch
        int curr = 1, prev = 0;
        for(int g = 1; g < C; g++){
            for(int i = 0; i < 210; i++)reachable[curr][i] = 0;
            for(int money = 0; money < M; money++){
                if(reachable[prev][money]){
                    for(int k = 1; k <= price[g][0]; k++){
                        if(money - price[g][k] >= 0){
                            reachable[curr][money - price[g][k]] = true;
                        }
                    }
                }
            }
            swap(curr, prev);
        }
        int money;
        for(money = 0; money < M && !reachable[prev][money]; money++);

        if(money == M) printf("no solution\n");
        else printf("%d\n", M - money);
        
    }


    return 0;
}