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

    int N;
    char game[3][3];
    scanf("%d", &N);

    int xwin, owin, xs, os, itsgame;

    while(N--){
        itsgame = 1;
        xwin = owin = xs = os = 0;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++){
                scanf(" %c", &game[i][j]);
                if(game[i][j] == 'X') xs++;
                else if(game[i][j] == 'O') os++;
            }

        // X
        if((game[0][0] == 'X' && game[0][1] == 'X' && game[0][2] == 'X') ||
           (game[1][0] == 'X' && game[1][1] == 'X' && game[1][2] == 'X') ||
           (game[2][0] == 'X' && game[2][1] == 'X' && game[2][2] == 'X') ||

           (game[0][0] == 'X' && game[1][0] == 'X' && game[2][0] == 'X') ||
           (game[0][1] == 'X' && game[1][1] == 'X' && game[2][1] == 'X') ||
           (game[0][2] == 'X' && game[1][2] == 'X' && game[2][2] == 'X') ||

           (game[0][0] == 'X' && game[1][1] == 'X' && game[2][2] == 'X') ||
           (game[0][2] == 'X' && game[1][1] == 'X' && game[2][0] == 'X')
        ) {
            xwin = 1;
        }

        // O
        if((game[0][0] == 'O' && game[0][1] == 'O' && game[0][2] == 'O') ||
           (game[1][0] == 'O' && game[1][1] == 'O' && game[1][2] == 'O') ||
           (game[2][0] == 'O' && game[2][1] == 'O' && game[2][2] == 'O') ||

           (game[0][0] == 'O' && game[1][0] == 'O' && game[2][0] == 'O') ||
           (game[0][1] == 'O' && game[1][1] == 'O' && game[2][1] == 'O') ||
           (game[0][2] == 'O' && game[1][2] == 'O' && game[2][2] == 'O') ||

           (game[0][0] == 'O' && game[1][1] == 'O' && game[2][2] == 'O') ||
           (game[0][2] == 'O' && game[1][1] == 'O' && game[2][0] == 'O')
        ) {
            owin = 1;
        }

        if((xwin && owin) || (os > xs) || ((xs - os) > 1) || (xs == os && xwin) || (xs > os && owin)){
            itsgame = 0;
        }
        
        if(itsgame){
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
    
    return 0;
}