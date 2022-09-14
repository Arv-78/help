/*
    author: arv
*/
#include <bits/stdc++.h>
using namespace std;

// int M, C, price[25][25];
// int memo[210][25];

// int shop(int money, int g){
//     if(money < 0)return -10000000;
//     if(g == C) return M - money;
//     int &ans = memo[money][g];
//     if(ans != -1)return ans;

//     for(int model = 1; model <= price[g][0]; model++){
//         ans = max(ans, shop(money - price[g][model], g + 1));
//     }

//     return ans;
// }

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int price[25][25];
    bool reachable[25][210];

    int TC, score, M, C;
    scanf("%d", &TC);
    while(TC --){
        scanf("%d %d", &M, &C);
        for(int i = 0; i < C; i++){
            scanf("%d", &price[i][0]);
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

        for(int g = 1; g < C; g++){
            for(int money = 0; money < M; money++){
                if(reachable[g - 1][money]){
                    for(int k = 1; k <= price[g][0]; k++){
                        if(money - price[g][k] >= 0){
                            reachable[g][money - price[g][k]] = true;
                        }
                    }
                }
            }
        }
        int money;
        for(money = 0; money < M && !reachable[C - 1][money]; money++);

        if(money == M) printf("no solution\n");
        else printf("%d\n", M - money);
        
    }


    return 0;
}