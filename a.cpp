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
    
    int M, N;
    int land[105][105];
    while(scanf("%d %d", &M, &N) == 2, M != 0, N != 0){
        for(int i = 0; i < M; i++)
            for(int j = 0; j < N; j++){
                scanf("%d", &land[i][j]);
            }
        
        int lagrest_land = 0;
        for(int i = 0; i < M; i++)
            for(int j = 0; j < N; j++)
                for(int k = i; k < M; k++){
                    int flag = 0;
                    for(int l = j; l < N; l++){
                        int sum = 0; 
                        if(flag)break;
                        for(int a = i; a <= k; a++){
                            if(flag) break;
                            for(int b = j; b <= l; b++){
                                if(land[a][b] == 1) {
                                    sum = 0;
                                    flag = 1;
                                    break;
                                }
                                else sum++;
                            }
                        }
                        lagrest_land = max(sum, lagrest_land);
                    }
                }
        
        printf("%d\n", lagrest_land);
            
    }
    



    return 0;
}