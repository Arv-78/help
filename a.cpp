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
    
    int tc, n, bks;
    int board[105][105];
    scanf("%d", &tc);

    while(tc--){
        memset(board, 0, sizeof board);//not working for 1
        scanf("%d", &n); scanf("%d", &bks);
        // scanf("%d %d", &n, &bks);
        // cout<<n<<' '<<bks<<'\n';
        


        int r1, c1, r2, c2;
        while(bks --){
            scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
            for(int i = r1 - 1; i < r2; i++)
                for(int j = c1 - 1; j < c2; j++)
                    board[i][j] = 1;
        }

        // for(int i = 0; i < n; i++){ for(int j = 0; j < n; j++)
        // cout<<board[i][j]<<' '; cout<<endl;}
        

        int large_area = 0; int tmp, length, width;
        for(int i = 0; i < n; i++){
            int sum[100];
            memset(sum, 0, sizeof sum);
            for(int j = i; j < n; j++){
                for(int k = 0; k < n; k++){
                    sum[k] += !board[j][k];
                    if(k == 0 || tmp != length * width){
                        tmp = 0; length = 0;
                    }
                    length++, width = j - i + 1;
                    tmp += sum[k];
                    if(tmp == length * width){
                        large_area = max(large_area, tmp);
                    }
                }
            }
        }

        printf("%d\n", large_area);

    } 

    return 0;
}