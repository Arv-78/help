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

    int t, w, h, n;
    int map1[35][35], map2[35][35], ships1, ships2, pturn; // player1 -> 0, player2 -> 1
    int win;                                               // 0 -> player1, 1 -> player2, 2 -> draw

    scanf("%d", &t);
    while (t--)
    {
        // reset
        ships1 = ships2 = 0;
        win = -1;
        pturn = 0;
        memset(map1, 0, sizeof map1);
        memset(map2, 0, sizeof map2);

        scanf("%d %d %d", &w, &h, &n);

        // player 1's map
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                char cv; // cell value
                scanf(" %c", &cv);
                if (cv == '#')
                { // ship -> 1
                    ships1++;
                    map1[i][j] = 1;
                }
            }
        }

        // player 2's map
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                char cv; // cell value
                scanf(" %c", &cv);
                if (cv == '#')
                { // ship -> 1
                    ships2++;
                    map2[i][j] = 1;
                }
            }
        }
        // shots
        while (n--)
        {
            int x, y; // shot co-ordinates
            scanf("%d %d", &x, &y);

            // player1's turn
            if (pturn == 0)
            {
                // printf("player 1 -> %d %d\n", x, y);
                // ship is hit
                if (map2[h - y - 1][x])
                {
                    ships2--;
                    map2[h - y - 1][x] = 0;

                    if (ships2 == 0)
                    { // if no ships left then other player's turn
                        pturn = 1;
                        continue;
                    }
                }
                else
                {
                    pturn = 1;
                    continue;
                }
            }

            // player2's turn
            if (pturn == 1)
            {
                // printf("player 2 -> %d %d\n", x, y);
                // ship is hit
                if (map1[h - y - 1][x])
                {
                    ships1--;
                    map1[h - y - 1][x] = 0;
                    if (ships1 == 0)
                    {
                        pturn = 0;

                        if (win == -1)
                        { // turns are equal so can check
                            if (ships2 > 0)
                            {
                                win = 1; // player2 wins
                            }
                        }
                    }
                }
                else
                {
                    pturn = 0;
                    // now that turns are equal, check for win
                    if (win == -1)
                    {
                        if (ships1 > 0 && ships2 == 0)
                        {
                            win = 0; // player1 wins
                        }
                        else if (ships1 == 0 && ships2 > 0)
                        {
                            win = 1; // player2 wins
                        }
                    }
                }
            }
        }

        // final win or draw
        if (win == -1)
        {
            if (ships1 > 0 && ships2 == 0)
            {
                win = 0; // player1 wins
            }
            else if (ships1 == 0 && ships2 > 0)
            {
                win = 1; // player2 wins
            }
            else if (ships1 > 0 && ships2 > 0)
            {
                win = 2; // draw
            }
            else if (ships1 == 0 && ships2 == 0)
            {
                win = 2; // draw
            }
        }

        if (win == 0)
        {
            printf("player one wins\n");
        }
        else if (win == 1)
        {
            printf("player two wins\n");
        }
        else if (win == 2)
        {
            printf("draw\n");
        }
        else if (win == -1)
        {
            printf("no win\n");
        }
    }

    return 0;
}