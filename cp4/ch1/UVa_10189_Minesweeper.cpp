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
    int count = 1;

    while(scanf("%d %d", &m, &n) != EOF && m && n){
        int field[m][n];

        memset(field, 0, sizeof field);

        char cell;

        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                scanf(" %c", &cell);
                
                if(cell == '*'){
                    field[r][c] = -10;

                    if(r - 1 >= 0){
                        field[r - 1][c]++;
                    }
                    if(r - 1 >= 0 && c - 1 >= 0){
                        field[r - 1][c - 1]++;
                    }
                    if(c - 1 >= 0){
                        field[r][c - 1]++;
                    }
                    if(r + 1 < m && c - 1 >= 0){
                        field[r + 1][c - 1]++;
                    }
                    if(r + 1 < m){
                        field[r + 1][c]++;
                    }
                    if(r + 1 < m && c + 1 < n){
                        field[r + 1][c + 1]++;
                    }
                    if(c + 1 < n){
                        field[r][c + 1]++;
                    }
                    if(r - 1 >= 0 && c + 1 < n){
                        field[r - 1][c + 1]++;
                    }
                }
            }
        }
        
        if(count != 1){
            printf("\n");
        }

        printf("Field #%d:\n", count++);

        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                if(field[r][c] < 0){
                    printf("*");
                } else {
                    printf("%d", field[r][c]);
                }
            }
            printf("\n");
        }
    }

    return 0;
}