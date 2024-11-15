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

    int cs, turns, len_jane_cards, len_john_cards, j, k;

    char jane_cards[105]; 
    char john_cards[105]; 
    char jane_fu_cards[105]; 
    char john_fu_cards[105]; 

    scanf("%d", &cs);

    while(cs--) {
        scanf("%s", jane_cards);
        scanf("%s", john_cards);

        memset(jane_fu_cards, '\0', sizeof(jane_fu_cards));
        memset(john_fu_cards, '\0', sizeof(john_fu_cards));

        turns = 1001;
        len_jane_cards = strlen(jane_cards);
        len_john_cards = strlen(john_cards);

        j = 0, k = 0;
        while(--turns){
            //one turn
            jane_fu_cards[strlen(jane_fu_cards)] = jane_cards[j];
            john_fu_cards[strlen(john_fu_cards)] = john_cards[k];

            //if cards are same
            if(jane_cards[j] == john_cards[k]){
                int snap = rand() / 141 % 2;

                if(snap == 0){ //Jane calls first
                    strcat(jane_fu_cards, john_fu_cards);
                    memset(john_fu_cards, '\0', sizeof(john_fu_cards));

                    printf("Snap! for Jane: ");

                    for(int l = strlen(jane_fu_cards) - 1; l >= 0; l--)
                        printf("%c", jane_fu_cards[l]);

                    printf("\n");

                    //check for win
                    //if dec is empty and face up pile is empty
                    if(k == (len_john_cards - 1) && strlen(john_fu_cards) == 0){
                        printf("%s\n", "Jane wins.");
                        break;
                    }

                } else { //John calls first
                    strcat(john_fu_cards, jane_fu_cards);
                    memset(jane_fu_cards, '\0', sizeof(jane_fu_cards));


                    printf("Snap! for John: ");

                    for(int l = strlen(john_fu_cards) - 1; l >= 0; l--)
                        printf("%c", john_fu_cards[l]);

                    printf("\n");

                    //check for win
                    //if dec is empty and face up pile is empty
                    if(j == (len_jane_cards - 1) && strlen(jane_fu_cards) == 0){
                        printf("%s\n", "John wins.");
                        break;
                    }
                }

            }

            //if dec is empty and face up pile is not empty
            if(j == (len_jane_cards - 1) && strlen(jane_fu_cards) > 0) {
                strcpy(jane_cards, jane_fu_cards);
                len_jane_cards = strlen(jane_cards);
                memset(jane_fu_cards, '\0', sizeof(jane_fu_cards));
                j = -1;
            }

            if(k == (len_john_cards - 1) && strlen(john_fu_cards) > 0){
                strcpy(john_cards, john_fu_cards);
                len_john_cards = strlen(john_cards);
                memset(john_fu_cards, '\0', sizeof(john_fu_cards));
                k = -1;
            }

            j++; k++;
        }


        if(turns == 0){
            printf("%s\n", "Keeps going and going ...");
        }

        if(cs) printf("\n");
    }


    return 0;
}