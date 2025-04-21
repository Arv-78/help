/*
    author: arv
*/
#include <bits/stdc++.h>
using namespace std;

int board[10][10], result, tx, ty;
char dir, inst[65]; // E, W, S, N

void getNextCoordinates(int tx, int ty, char inst, int &nx, int &ny){
    if(dir == 'E'){
        switch(inst){
            case 'F':
                nx = tx;
                ny = ty + 1;
                break;
            
            case 'X':
                nx = tx;
                ny = ty + 1;
                break;
            
            case 'R':
                dir = 'S';
                break;
            
            case 'L':
                dir = 'N';
                break;
            default:
                nx = tx;
                ny = ty;
                break;
        }
    } else if(dir == 'W'){
        switch(inst){
            case 'F':
                nx = tx;
                ny = ty - 1;
                break;
            
            case 'X':
                nx = tx;
                ny = ty - 1;
                break;
            
            case 'R':
                dir = 'N';
                break;
            
            case 'L':
                dir = 'S';
                break;
            default:
                nx = tx;
                ny = ty;
                break;
        }

    } else if(dir == 'S'){
        switch(inst){
            case 'F':
                nx = tx + 1;
                ny = ty;
                break;
            
            case 'X':
                nx = tx + 1;
                ny = ty;
                break;
            
            case 'R':
                dir = 'W';
                break;
            
            case 'L':
                dir = 'E';
                break;
            default:
                nx = tx;
                ny = ty;
                break;
        }

    } else if(dir == 'N'){
        switch(inst){
            case 'F':
                nx = tx - 1;
                ny = ty;
                break;
            
            case 'X':
                nx = tx - 1;
                ny = ty;
                break;
            
            case 'R':
                dir = 'E';
                break;
            
            case 'L':
                dir = 'W';
                break;
            default:
                nx = tx;
                ny = ty;
                break;
        }

    }
}


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    memset(board, 0, sizeof board); // 0 -> empty, 1 -> rock(C), 2 -> ice(I), 3 -> diamond(D)
    result = -1;
    dir = 'E';
    tx = 7;
    ty = 0;

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            char temp;
            scanf(" %c", &temp);
            if(temp == 'C'){
                board[i][j] = 1;
            }
            if(temp == 'I'){
                board[i][j] = 2;
            }
            if(temp == 'D'){
                board[i][j] = 3;
            }
        }
    }
    getchar();
    fgets(inst, 65, stdin);

    for(int i = 0; i < strlen(inst); i++){
        if(inst[i] == '\n') break;

        
        int nx, ny;
        getNextCoordinates(tx, ty, inst[i], nx, ny);
        if(inst[i] != 'R' && inst[i] != 'L'){ // on R and L nx, ny don't change, contains garbage values
            if((7 < nx || nx < 0) || (7 < ny || ny < 0) || (inst[i] == 'X' && board[nx][ny] != 2) || (inst[i] != 'X' && board[nx][ny] == 2) || (board[nx][ny] == 1)){
                result = 0;
                break;
            }
            // printf("inst -> %c, tx -> %d, ty -> %d\n", inst[i], nx, ny);
    
            if(inst[i] == 'X' && board[nx][ny] == 2) {
                board[nx][ny] = 0;
            } else {
                tx = nx;
                ty = ny;
            }
        }
    }

    if(board[tx][ty] == 3 && result != 0){ // checking at the end if no bug and the turtle is at diamond
        printf("Diamond!");
    } else {
        printf("Bug!");
    }


    return 0;
}