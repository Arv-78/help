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
    
    // board to check both are white or black
    int board[8][8];
    int toggle = 1; //1-> white; 0-> black;

    for(int i = 0; i < 8; i++){ 
        for(int j = 0; j < 8; j++){
            board[i][j] = toggle;
            toggle = (toggle + 1) % 2;
        }
        toggle = (toggle + 1) % 2;
    }

    int N;
    char from_c, to_c; int from_r, to_r;

    scanf("%d", &N);

    while(N--){
        scanf(" %c %d %c %d", &from_c, &from_r, &to_c, &to_r);

        int c_f = from_c - 'A'; int r_f = from_r - 1; 
        int c_t = to_c - 'A'; int r_t = to_r - 1;
        
        if(board[r_f][c_f] != board[r_t][c_t]){
            printf("Impossible\n");
        } else {
            int i_c, i_r;
            int moves = 0;
            int is_i_found = 0;

            if((r_f == r_t) && (c_f == c_t)){ // same cell
                is_i_found = 1;
            } else if(abs(c_f - c_t) == abs(r_f - r_t)){ // both are on same diagonal
                is_i_found = 1;
                moves = 1;
            } else {
                //moves will be 2 as only one intermediate cell
                moves = 2;
            }

            if(!is_i_found)
            //bottom-right
            while(c_f <= 7 && r_f <= 7){
                if(abs(c_f - c_t) == abs(r_f - r_t)){
                    i_c = c_f; i_r = r_f;
                    is_i_found = 1;
                    break;
                }
                c_f++;
                r_f++;
            }

            // reset temporary vars
            c_f = from_c - 'A';
            r_f = from_r - 1;

            //bottom-left
            if(!is_i_found)
            while(c_f >= 0 && r_f <= 7){
                if(abs(c_f - c_t) == abs(r_f - r_t)){
                    i_c = c_f; i_r = r_f;
                    is_i_found = 1;
                    break;
                }
                c_f--;
                r_f++;
            }

            // reset temporary vars
            c_f = from_c - 'A';
            r_f = from_r - 1;

            //top-left
            if(!is_i_found)
            while(c_f >= 0 && r_f >= 0){
                if(abs(c_f - c_t) == abs(r_f - r_t)){
                    i_c = c_f; i_r = r_f;
                    is_i_found = 1;
                    break;
                }
                c_f--;
                r_f--;
            }

            // reset temporary vars
            c_f = from_c - 'A';
            r_f = from_r - 1;

            //top-right
            if(!is_i_found)
            while(c_f <= 7 && r_f >= 0){
                if(abs(c_f - c_t) == abs(r_f - r_t)){
                    i_c = c_f; i_r = r_f;
                    is_i_found = 1;
                    break;
                }
                c_f++;
                r_f--;
            }

            if(!moves){
                printf("0 %c %d", to_c, to_r);
            } else if(moves == 1) {
                printf("%d %c %d %c %d", moves, from_c, from_r, to_c, to_r);
            } else{
                printf("%d %c %d %c %d %c %d", moves, from_c, from_r, 'A' + i_c, i_r + 1, to_c, to_r);
            }
            printf("\n");

        }
    }

    
    return 0;
}