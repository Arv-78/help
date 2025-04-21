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

    int round, chances, w_count, result; // 1 -> win, 0 -> lose, -1 -> chickend out
    char ans, guess;

    int lookup['z' + 10];

    
    while(scanf("%d\n", &round), round != -1){
        memset(lookup, 0, sizeof lookup); //reset
        result = -1;
        chances = 7; w_count = 0;

        while(scanf("%c", &ans), ans != '\n'){
            if(lookup[ans] == 0){
                w_count++; //count unique letters
                lookup[ans] = 1;
            }
        }

        while(scanf("%c", &guess), guess != '\n'){
            if(lookup[guess] == 1){ //guess is in the word
                lookup[guess] = 2;
                w_count--;

                if(w_count == 0 && result == -1){
                    result = 1;
                }

            } else if(lookup[guess] == 0){ //guess is not in the word
                lookup[guess] = -1;
                chances--;

                if(chances == 0 && result == -1){
                    result = 0;
                }
            }
        }
        
        printf("Round %d\n", round);
        if(result == 1){
            printf("You win.");
        } else if(result == 0){
            printf("You lose.");
        } else {
            printf("You chickened out.");
        }
        printf("\n");
    }

    return 0;
}