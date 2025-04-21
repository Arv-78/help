/*
    author: arv
*/
#include <bits/stdc++.h>
using namespace std;

int check_bingo(int (&card)[5][5], int &bnr, int &bnc, int (&rbn)[78]){
    int flag = 0;

    // column
    for(int r = 0; r <= 4; r++){
        if(!rbn[card[r][bnc]]) {
            flag = 0;
            break;
        } else {
            flag = 1;
        }
    }

    // row
    if(!flag){
        for(int c = 0; c <= 4; c++){
            if(!rbn[card[bnr][c]]){
                flag = 0;
                break;
            } else {
                flag = 1;
            }
        }
    }

    // diagonal left
    if(!flag && bnr == bnc){
        int r = 0, c = 0;
        while(r <= 4 && c <= 4){
            if(!rbn[card[r][c]]){
                flag = 0;
                break;
            } else {
                flag = 1;
            }
            r++; c++;
        }
    }

    // diagonal right
    if(!flag && (bnr + bnc) == 4){
        int r = 0, c = 4;
        while(r <= 4 && c >= 0){
            if(!rbn[card[r][c]]){
                flag = 0;
                break;
            } else {
                flag = 1;
            }
            r++; c--;
        }
        
    }

    if(flag) return 1;
    return 0;
    
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int games;
    int card[5][5];
    int cni[78][2]; // card number indices (r, c)
    int rbn[78]; // revealed bingo numbers
    int bingo;

    scanf("%d", &games);

    while(games--){
        bingo = 0;
        memset(cni, -1, sizeof cni);
        memset(rbn, 0, sizeof rbn);

        // read card
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                if(i == 2 && j == 2){
                    card[i][j] = 76; // free space
                    cni[76][0] = i;
                    cni[76][1] = j;
                } else {
                    scanf("%d", &card[i][j]);

                    cni[card[i][j]][0] = i;
                    cni[card[i][j]][1] = j;
                }
            }
        }

        // free space
        cni[76][0] = 2;
        cni[76][1] = 2;

        rbn[76] = 1; // free space already revealed

        // bingo numbers
        for(int i = 0; i < 75; i++){
            int bingo_num;
            scanf("%d", &bingo_num);

            rbn[bingo_num] = 1;

            if(cni[bingo_num][0] != -1 && bingo == 0){
                int if_bingo;
                if_bingo = check_bingo(card, cni[bingo_num][0], cni[bingo_num][1], rbn);

                if(if_bingo){
                    bingo = i + 1;
                }
            }
        }

        printf("BINGO after %d numbers announced\n", bingo);
    }


    return 0;
}