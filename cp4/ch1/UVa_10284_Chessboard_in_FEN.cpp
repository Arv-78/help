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

    // number of squares empty that are not under attack.
    // given desc may not be legal.

    // store in 2d 8x8 array of chars
    // using e for empty

    char board[10][10];

    char line[80];

    while(scanf("%s", line) != EOF){
        int row = 0;
        int col = 0;
        int not_under_attack_cells = 0;

        for(int i = 0; i <= strlen(line) - 1; i++){ // board fill
            if(line[i] == '/'){
                board[row][col] = '\0';
                col = 0;
                row++;
            } else {
                if(isdigit(line[i])){
                    int repeat = line[i] - '0';

                    while(repeat--){
                        board[row][col] = 'e';
                        col++;
                    }
                } else {
                    board[row][col] = line[i];
                    col++;
                }
            }
        }

        for(int r = 0; r <= 7; r++){
            for(int c = 0; c <= 7; c++){
                int p; int rp;
                if(board[r][c] == 'e'){
                    int is_under_attack = 0;
                    int is_adjacent_checked = 0;

                    // check if right dir is clear
                    p = c + 1;
                    while(p <= 7){
                        if(!is_adjacent_checked){
                            // check adjacent cell doesn't have king
                            is_adjacent_checked = 1;
                            if(board[r][p] == 'k' || board[r][p] == 'K'){
                                is_under_attack = 1;
                                break;
                            }
                        }

                        // check if it has rook / queen
                        if(board[r][p] == 'r' || board[r][p] == 'R' || board[r][p] == 'q' || board[r][p] == 'Q'){
                            is_under_attack = 1;
                            break;
                        } else {
                            //below pieces can't jump, check if p has encountered another piece
                            if(board[r][p] != 'e'){
                                break;
                            }
                        }
                        p++;
                    }


                    // check right-bottom diagonal
                    if(!is_under_attack){
                        p = c + 1;
                        rp = r + 1;

                        is_adjacent_checked = 0;
                        while(p <= 7 && r <= 7){
                            if(!is_adjacent_checked){
                                //check adjacent cell doesn't contain king or pawn
                                is_adjacent_checked = 1;
                                if(board[rp][p] == 'K' || board[rp][p] == 'k' || board[rp][p] == 'P'){
                                    is_under_attack = 1;
                                    break;
                                }
                            } 
                            // check if it has queen or bishop
                            if(board[rp][p] == 'b' || board[rp][p] == 'B' || board[rp][p] == 'q' || board[rp][p] == 'Q'){
                                is_under_attack = 1;
                                break;
                            } else {
                                if(board[rp][p] != 'e'){
                                    break;
                                }
                            }

                            p++;
                            rp++;
                        }
                    }

                    // check in bottom direction
                    if(!is_under_attack){
                        rp = r + 1;
                        p = c;

                        is_adjacent_checked = 0;
                        while(rp <= 7){
                            if(!is_adjacent_checked){
                                //check adjacent cell doesn't contain king or pawn
                                is_adjacent_checked = 1;
                                if(board[rp][p] == 'K' || board[rp][p] == 'k'){
                                    is_under_attack = 1;
                                    break;
                                }
                            } 
                        // check if it has rook / queen
                        if(board[rp][p] == 'r' || board[rp][p] == 'R' || board[rp][p] == 'q' || board[rp][p] == 'Q'){
                                is_under_attack = 1;
                                break;
                            } else {
                                if(board[rp][p] != 'e'){
                                    break;
                                }
                            }

                            rp++;
                        }
                    }

                    // check bottom-left diagonal
                    if(!is_under_attack){
                        p = c - 1;
                        rp = r + 1;

                        is_adjacent_checked = 0;
                        while(p >= 0 && rp <= 7){
                            if(!is_adjacent_checked){
                                //check adjacent cell doesn't contain king or pawn
                                is_adjacent_checked = 1;
                                if(board[rp][p] == 'K' || board[rp][p] == 'k' || board[rp][p] == 'P'){
                                    is_under_attack = 1;
                                    break;
                                }
                            } 
                            // check if it has queen or bishop
                            if(board[rp][p] == 'b' || board[rp][p] == 'B' || board[rp][p] == 'q' || board[rp][p] == 'Q'){
                                is_under_attack = 1;
                                break;
                            } else {
                                if(board[rp][p] != 'e'){
                                    break;
                                }
                            }

                            p--;
                            rp++;
                        }
                    }

                    // check in left direction
                    if(!is_under_attack){
                        p = c - 1;
                        rp = r;

                        is_adjacent_checked = 0;
                        while(p >= 0){
                            if(!is_adjacent_checked){
                                //check adjacent cell doesn't contain king or pawn
                                is_adjacent_checked = 1;
                                if(board[rp][p] == 'K' || board[rp][p] == 'k'){
                                    is_under_attack = 1;
                                    break;
                                }
                            } 
                        // check if it has rook / queen
                        if(board[rp][p] == 'r' || board[rp][p] == 'R' || board[rp][p] == 'q' || board[rp][p] == 'Q'){
                                is_under_attack = 1;
                                break;
                            } else {
                                if(board[rp][p] != 'e'){
                                    break;
                                }
                            }

                            p--;
                        }
                    }

                    // check top-left diagonal
                    if(!is_under_attack){
                        p = c - 1;
                        rp = r - 1;

                        is_adjacent_checked = 0;
                        while(p >= 0 && rp >= 0){
                            if(!is_adjacent_checked){
                                //check adjacent cell doesn't contain king or pawn
                                is_adjacent_checked = 1;
                                if(board[rp][p] == 'K' || board[rp][p] == 'k' || board[rp][p] == 'p'){
                                    is_under_attack = 1;
                                    break;
                                }
                            } 
                            // check if it has queen or bishop
                            if(board[rp][p] == 'b' || board[rp][p] == 'B' || board[rp][p] == 'q' || board[rp][p] == 'Q'){
                                is_under_attack = 1;
                                break;
                            } else {
                                if(board[rp][p] != 'e'){
                                    break;
                                }
                            }

                            p--;
                            rp--;
                        }
                    }

                    // check in top direction
                    if(!is_under_attack){
                        rp = r - 1;
                        p = c;

                        is_adjacent_checked = 0;
                        while(rp >= 0){
                            if(!is_adjacent_checked){
                                //check adjacent cell doesn't contain king or pawn
                                is_adjacent_checked = 1;
                                if(board[rp][p] == 'K' || board[rp][p] == 'k'){
                                    is_under_attack = 1;
                                    break;
                                }
                            } 
                        // check if it has rook / queen
                        if(board[rp][p] == 'r' || board[rp][p] == 'R' || board[rp][p] == 'q' || board[rp][p] == 'Q'){
                                is_under_attack = 1;
                                break;
                            } else {
                                if(board[rp][p] != 'e'){
                                    break;
                                }
                            }

                            rp--;
                        }
                    }

                    // check top-right diagonal
                    if(!is_under_attack){
                        p = c + 1;
                        rp = r - 1;

                        is_adjacent_checked = 0;
                        while(p <= 7 && rp >= 0){
                            if(!is_adjacent_checked){
                                //check adjacent cell doesn't contain king or pawn
                                is_adjacent_checked = 1;
                                if(board[rp][p] == 'K' || board[rp][p] == 'k' || board[rp][p] == 'p'){
                                    is_under_attack = 1;
                                    break;
                                }
                            } 
                            // check if it has queen or bishop
                            if(board[rp][p] == 'b' || board[rp][p] == 'B' || board[rp][p] == 'q' || board[rp][p] == 'Q'){
                                is_under_attack = 1;
                                break;
                            } else {
                                if(board[rp][p] != 'e'){
                                    break;
                                }
                            }

                            p++;
                            rp--;
                        }
                    }


                    // knight check 
                    if(!is_under_attack){
                        if(board[r + 1][c + 2] == 'n' || board[r - 1][c + 2] == 'n' || board[r + 1][c - 2] == 'n' || board[r - 1][c - 2] == 'n' ||
                            board[r + 1][c + 2] == 'N' || board[r - 1][c + 2] == 'N' || board[r + 1][c - 2] == 'N' || board[r - 1][c - 2] == 'N' ||
                            board[r + 2][c + 1] == 'n' || board[r + 2][c - 1] == 'n' || board[r - 2][c + 1] == 'n' || board[r - 2][c - 1] == 'n' ||
                            board[r + 2][c + 1] == 'N' || board[r + 2][c - 1] == 'N' || board[r - 2][c + 1] == 'N' || board[r - 2][c - 1] == 'N'
                            ){
                                is_under_attack = 1;
                            }
                    }

                    if(!is_under_attack){
                        not_under_attack_cells ++;
                    }
                }
            }
        }

        printf("%d\n", not_under_attack_cells);
    }

    return 0;
}