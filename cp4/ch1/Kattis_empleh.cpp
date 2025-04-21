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
    
    int board[65][3];

    memset(board, -1, sizeof board);

    char line[200];

    int t = 2;
    int player = 1;// white

    while(t--)
    {
        fgets(line, sizeof(line), stdin);
    
        int piece = -1, c = -1, r = -1, p = 7, pos;
    
        while(1){
            if(line[p] != ',' && line[p] != '\0' && line[p] != '\n'){
                if(piece == -1) piece = line[p];
                else if(c == -1) c = line[p];
                else r = line[p];
            } else {
                if(r == -1){ // it is pawn
                    r = c;
                    c = piece;
                    piece = 'P';
                }
                
                if(!player) piece = tolower(piece);
                
                for(pos = 0; pos < 64; pos++){ // find pos
                    if(board[pos][0] == -1){
                        break;
                    } else if(board[pos][2] < r){
                        break;
                    } else if(board[pos][2] == r){
                        if(board[pos][1] > c){
                            break;
                        }
                    }
                }
    
                int tp, tc, tr;
    
                while(board[pos][0] != -1){
                    tp = board[pos][0];
                    tc = board[pos][1];
                    tr = board[pos][2];
                    board[pos][0] = piece;
                    board[pos][1] = c;
                    board[pos][2] = r;
    
                    piece = tp;
                    c = tc;
                    r = tr;
                    pos++;
                }
    
                board[pos][0] = piece;
                board[pos][1] = c;
                board[pos][2] = r;

                if(line[p] == '\0' || line[p] == '\n'){
                    break;
                }

                piece = -1, c = -1, r = -1; //reset pieces data
            }
            p++;
        }
    
        player = (player + 1) % 2;
    }

    int toggle = 1;
    int pos = 0;

    for(int r = '8'; r > '0'; r--){
        for(int i = 0; i < 8; i++){
            printf("+---");
        }
        printf("+\n");

        for(int c = 'a'; c < 'i'; c++){
            printf("|");
            if(toggle){
                if(board[pos][1] == c && board[pos][2] == r){
                    printf(".%c.", board[pos][0]);
                    pos++;
                } else {
                    printf("...");
                }
            } else {
                if(board[pos][1] == c && board[pos][2] == r){
                    printf(":%c:", board[pos][0]);
                    pos++;
                } else {
                    printf(":::");
                }
            }

            toggle = !toggle;
        }
        toggle = !toggle;
        printf("|\n");
    }

    for(int i = 0; i < 8; i++){
        printf("+---");
    }
    printf("+\n");
    
    return 0;
}