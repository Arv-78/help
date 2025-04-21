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

    int deck_size, t_shuffle = 0, half, start;
    char op[4];
    scanf("%d %s", &deck_size, op);
    
    char deck[deck_size + 10] = {0};
    char shuffle_deck[deck_size + 10] = {0};
    char shuffle_deck_2[deck_size + 10] = {0};

    //fill the dec with chars
    for(int i = 0; i < deck_size; i++){
        deck[i] = 'A' + i;
    }

    strcpy(shuffle_deck_2, deck); //O(n)

    int toggle = 0;

    if (strcmp(op, "out") == 0) {       
        while(1){
            start = 0;
            half = ceil((float)deck_size / 2);

            t_shuffle++;

            int half_i = half;
            int i = 0;

            if(toggle == 0){
                while (start != half){
                    shuffle_deck[i] = shuffle_deck_2[start];
                    if(half_i < deck_size) shuffle_deck[++i] = shuffle_deck_2[half_i];
                    start++;
                    half_i++;
                    i++;
                }
                if(strcmp(deck, shuffle_deck) == 0) break;
            }

            if(toggle == 1){
                while (start != half){
                    shuffle_deck_2[i] = shuffle_deck[start];
                    if(half_i < deck_size) shuffle_deck_2[++i] = shuffle_deck[half_i];
                    start++;
                    half_i++;
                    i++;
                }

                if(strcmp(deck, shuffle_deck_2) == 0) break;
            }

            toggle = !toggle;
        }
    } else if(strcmp(op, "in") == 0) { //ABCDEFG
        while(1){
            start = 0;
            half = floor((float)deck_size / 2);

            t_shuffle++;

            int half_i = half;
            int i = 0;

            if(toggle == 0){
                while (half_i < deck_size){
                    shuffle_deck[i] = shuffle_deck_2[half_i];
                    if(start < half) shuffle_deck[++i] = shuffle_deck_2[start];
                    start++;
                    half_i++;
                    i++;
                }

                if(strcmp(deck, shuffle_deck) == 0) break;
            }

            if(toggle == 1){
                while (half_i < deck_size){
                    shuffle_deck_2[i] = shuffle_deck[half_i];
                    if(start < half) shuffle_deck_2[++i] = shuffle_deck[start];
                    start++;
                    half_i++;
                    i++;
                }

                if(strcmp(deck, shuffle_deck_2) == 0) break;
            }

            toggle = !toggle;
        }
    }

    printf("%d", t_shuffle);

    return 0;
}