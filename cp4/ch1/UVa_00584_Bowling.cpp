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
    
    char game[350];
    int score, frames;

    while(fgets(game, sizeof game, stdin), strcmp(game, "Game Over\n") != 0){
        score = 0;
        frames = 0;
        int count = 0;
        for(int i = 0; i < strlen(game) - 1; i+=2){
            if(game[i] == '/'){ //spare
                score += 10 - (game[i - 2] - '0');
                //bonus
                if(game[i + 2] == 'X'){ // strike
                    score += 10;
                } else {
                    score += (game[i + 2] - '0');
                }

                if(count == 1){
                    frames++;
                    count = 0;
                }

                if(frames == 10) break;

            } else if(game[i] == 'X'){ // strike
                score += 10;

                // bonus
                // i + 2
                if(game[i + 2] == 'X'){
                    score += 10;
                } else {
                    score += (game[i + 2] - '0');
                }

                // i + 4
                if(game[i + 4] == 'X'){
                    score += 10;
                } else if(game[i + 4] == '/'){
                    score += 10 - (game[i + 2] - '0');
                } else {
                    score += (game[i + 4] - '0');
                }

                frames++;

                if(frames == 10) break;

            } else {
                score += (game[i] - '0');
                count++;
                if(count == 2) {
                    frames++;
                    count = 0;
                }
            }
        }

        printf("%d\n", score);
    }

    return 0;
}