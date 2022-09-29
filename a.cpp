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
        int tmp, length, width;
        for(int i = 0; i < M; i++){
            int sum[100];
            memset(sum, 0, sizeof sum);
            for(int j = i; j < M; j++){
                for(int k = 0; k < N; k++){
                    sum[k] += !land[j][k];
                    if(k == 0 || tmp != length * width){
                        length = 0; tmp = 0;
                    }
                    length++; width = j - i + 1;
                    tmp += sum[k];

                    if(tmp == length * width){
                        lagrest_land = max(lagrest_land, tmp);
                    }
                }
            }
        }
        
        printf("%d\n", lagrest_land);
            
    }
    



    return 0;
}