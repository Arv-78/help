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
    
    char line[35];
    int r = 8;
    int c;

    int white_pieces[65][3];
    int black_pieces[65][3];
    // 0 1 2 3 4 5 6 7 8-15
    // r n b k q b n r p

    memset(white_pieces, -1, sizeof(white_pieces));
    memset(black_pieces, -1, sizeof(black_pieces));

    //mappings
    int map['Z'];
    map['K'] = 8;
    map['Q'] = 7;
    map['R'] = 6;
    map['B'] = 5;
    map['N'] = 4;
    map['P'] = 3;

    while(fgets(line, sizeof(line), stdin) != NULL){
        if(line[0] == '\n') break;
        if(line[0] != '+'){
            int i = 2;
            c = 'a';
            for(; i <= 30; i+=4){ // iterating over each row
                if(line[i] != '.' && line[i] != ':'){

                    int player = isupper(line[i]); //cap | returns > 0 | white

                    char p = toupper(line[i]);

                    int pos = 0;

                    for(; pos < 65; pos++){
                        if(player){ // white player
                            if(white_pieces[pos][0] == -1){
                                break;
                            } else if(map[p] > map[white_pieces[pos][0]]){
                                break;
                            } else if(map[p] == map[white_pieces[pos][0]]){
                                if(white_pieces[pos][1] > r){
                                    break;
                                } else if(white_pieces[pos][1] == r){
                                    if(white_pieces[pos][2] > c){
                                        break;
                                    }
                                }
                            }
                        } else { // black player
                            if(black_pieces[pos][0] == -1){
                                break;
                            } else if(map[p] > map[black_pieces[pos][0]]){
                                break;
                            } else if(map[p] == map[black_pieces[pos][0]]){
                                if(black_pieces[pos][1] < r){
                                    break;
                                } else if(black_pieces[pos][1] == r){
                                    if(black_pieces[pos][2] > c){
                                        break;
                                    }
                                }
                            }
                        }
                    }


                    int t_r = r, t_c = c;
                    int i_c, i_r, i_p;
                    if(player){
                        while (white_pieces[pos][0] != -1){
                            i_p = white_pieces[pos][0];
                            i_r = white_pieces[pos][1];
                            i_c = white_pieces[pos][2];

                            white_pieces[pos][0] = p;
                            white_pieces[pos][1] = t_r;
                            white_pieces[pos][2] = t_c;

                            p = i_p;
                            t_r = i_r;
                            t_c = i_c;

                            pos++;
                        }

                        white_pieces[pos][0] = p;
                        white_pieces[pos][1] = t_r;
                        white_pieces[pos][2] = t_c;
                    } else {
                        while (black_pieces[pos][0] != -1){
                            i_p = black_pieces[pos][0];
                            i_r = black_pieces[pos][1];
                            i_c = black_pieces[pos][2];

                            black_pieces[pos][0] = p;
                            black_pieces[pos][1] = t_r;
                            black_pieces[pos][2] = t_c;

                            p = i_p;
                            t_r = i_r;
                            t_c = i_c;

                            pos++;
                        }

                        black_pieces[pos][0] = p;
                        black_pieces[pos][1] = t_r;
                        black_pieces[pos][2] = t_c;

                        
                    }        

                }
                c++;
            }
            r--;
        }
    }

    int i = 0;

    printf("White: ");

    while(white_pieces[i][0] != -1){
        if(white_pieces[i][0] == 'P'){
            printf("%c%d", white_pieces[i][2], white_pieces[i][1]);
        } else {
            printf("%c%c%d", white_pieces[i][0], white_pieces[i][2], white_pieces[i][1]);
        }
        if(white_pieces[i + 1][0] != -1) printf(",");
        i++;
    }

    printf("\nBlack: ");

    i = 0;

    while(black_pieces[i][0] != -1){
        if(black_pieces[i][0] == 'P'){
            printf("%c%d", black_pieces[i][2], black_pieces[i][1]);
        } else {
            printf("%c%c%d", black_pieces[i][0], black_pieces[i][2], black_pieces[i][1]);
        }
        if(black_pieces[i + 1][0] != -1) printf(",");
        i++;
    }
    
    return 0;
}