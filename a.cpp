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

    //1. CM 2. for each block price and size 3. if size same then cheaper one, select

    int tc; int t = 0;
    scanf("%d", &tc);
    int N, M, K;
    int block[105][105];
    while(tc --){
        scanf("%d %d %d", &N, &M, &K);


        //CM
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++){
                scanf("%d", &block[i][j]);
                if(i > 0) block[i][j] += block[i - 1][j];
                if(j > 0) block[i][j] += block[i][j - 1];
                if(i > 0 && j > 0) block[i][j] -= block[i - 1][j - 1];
            }
            
            
        
        int max_size = 0; int max_price = 0; int sum, size;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                for(int k = i; k < N; k++)
                    for(int l = j; l < M; l++){
                        sum = block[k][l];
                        if(i > 0) sum -= block[i - 1][l];
                        if(j > 0) sum -= block[k][j - 1];
                        if(i > 0 && j > 0) sum += block[i - 1][j - 1];
                        
                        if(sum <= K){
                            size = (k - i + 1) * (l - j + 1); //k - (i - 1) -> k - i + 1
                            if(size == max_size && sum < max_price)
                                max_price = sum;

                            if(size > max_size){
                                max_price = sum;
                                max_size = size;
                            }
                        }
                    }
                
                

            printf("Case #%d: %d %d\n", ++t, max_size, max_price);

    }


    return 0;
}