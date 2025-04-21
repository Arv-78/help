/*
    author: arv
*/
#include <bits/stdc++.h>
using namespace std;

map <char, int> lookup = {
    {'A', 1},
    {'K', 13},
    {'Q', 12},
    {'J', 11},
    {'T', 10},
    {'S', 0},
    {'H', 13},
    {'D', 26},
    {'C', 39}
};

map <int, char> lookup1 = {
    {0, 'K'},
    {12, 'Q'},
    {11, 'J'},
    {10, 'T'},
    {1, 'A'}
};

int cardToNum(char card[]){
    // AH 
    int n;
    if(card[0] >= '2' && card[0] <= '9'){
        n = (card[0] - '0') + lookup[card[1]];
    } else {
        n = lookup[card[0]] + lookup[card[1]];
    }

    return n;
}

string numToCard(int n){
    string card(2, ' ');

    if(n / 13.0 <= 1){
        card[1] = 'S';
    } else if(n / 13.0 <= 2){
        card[1] = 'H';
    } else if(n / 13.0 <= 3){
        card[1] = 'D';
    } else if(n / 13.0 <= 4){
        card[1] = 'C';
    }

    int rem = n % 13;

    switch(rem){
        case 0:
            card[0] = lookup1[0];
            break;
        case 12:
            card[0] = lookup1[12];
            break;
        case 11:
            card[0] = lookup1[11];
            break;
        case 10:
            card[0] = lookup1[10];
            break;
        case 1:
            card[0] = lookup1[1];
            break;
        default:
            card[0] = '0' + rem;
            break;
    }

    return card;
}


int best_combination(int cards[]){
    int c[14];
    int temp[14];
    memset(c, 0, sizeof c);

    for(int i = 0; i < 5; i++){
        char value = numToCard(cards[i])[0];
        if(value >= '2' && value <= '9'){
            c[value - '0']++;
        } else {
            c[lookup[value]]++;
        }
    }

    // straight
    for(int i = 1; i <= 13; i++){
        for(int k = 0; k < 14; k++) temp[k] = c[k];
        int p = 5;
        for(int j = i; j <= i + 4; j++){
            if(j > 13){
                j = j % 13;
            }
            if(temp[j]){
                p--;
                temp[j]--;
            } else {
                break;
            }
        }

        if(p == 0){
            return 100;
        }
    }

    // Invite-the-Neighbours
    for(int i = 1; i <= 13; i++){
        for(int k = 0; k < 14; k++) temp[k] = c[k];
        int p = 4;
        for(int j = i; j <= i + 3; j++){
            if(j > 13){
                j = j % 13;
            }
            if(temp[j]){
                p--;
                temp[j]--;
            } else {
                break;
            }
        }

        if(p == 0){
            return 10;
        }
    }

    // Bed-and-Breakfast 
    for(int i = 1; i <= 13; i++){
        for(int k = 0; k < 14; k++) temp[k] = c[k];
        int p = 3;
        for(int j = i; j <= i + 2; j++){
            if(j > 13){
                j = j % 13;
            }
            if(temp[j]){
                p--;
                temp[j]--;
            } else {
                break;
            }
        }
        int temp2[14];
        if(p == 0){
            for(int i = 1; i <= 13; i++){
                for(int k = 0; k < 14; k++) temp2[k] = temp[k];
                int p2 = 2;
                for(int j = i; j <= i + 1; j++){
                    if(j > 13){
                        j = j % 13;
                    }
                    if(temp2[j]){
                        p2--;
                        temp2[j]--;
                    } else {
                        break;
                    }
                }

                if(p2 == 0){
                    return 5;
                }
            }
        }
    }

    // Menage-a-Trois 
    for(int i = 1; i <= 13; i++){
        for(int k = 0; k < 14; k++) temp[k] = c[k];
        int p = 3;
        for(int j = i; j <= i + 2; j++){
            if(j > 13){
                j = j % 13;
            }
            if(temp[j]){
                p--;
                temp[j]--;
            } else {
                break;
            }
        }

        if(p == 0){
            return 3;
        }
    }

    // Double Dutch
    for(int i = 1; i <= 13; i++){
        for(int k = 0; k < 14; k++) temp[k] = c[k];
        int p = 2;
        for(int j = i; j <= i + 1; j++){
            if(j > 13){
                j = j % 13;
            }
            if(temp[j]){
                p--;
                temp[j]--;
            } else {
                break;
            }
        }
        int temp2[14];
        if(p == 0){
            for(int i = 1; i <= 13; i++){
                for(int k = 0; k < 14; k++) temp2[k] = temp[k];
                int p2 = 2;
                for(int j = i; j <= i + 1; j++){
                    if(j > 13){
                        j = j % 13;
                    }
                    if(temp2[j]){
                        p2--;
                        temp2[j]--;
                    } else {
                        break;
                    }
                }

                if(p2 == 0){
                    return 1;
                }
            }
        }
    }

    return 0;

}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int ini_cards[5], exchangeable_card = 0;
    float expected_earning, initial_earning, prev_ex_earning, s_100, s_10, s_5, s_3, s_1;
    char card[3], cards[55];
    int i = 0;
    memset(cards, 0, sizeof cards);
    int newline = 0;
    while(scanf("%s", card) == 1, card[0] != '#') {
        int ctn = cardToNum(card);
        ini_cards[i % 5] = ctn;
        cards[ctn] = 1;
        i++;

        if(i == 5){
            int earning;
            earning = best_combination(ini_cards);
            
            initial_earning = earning - 1; // 1 dollar to dealer
            prev_ex_earning = initial_earning;
            
            // count the scores if a card is getting replaced. Card can be replaced from remaining 47 cards
            int temp[5];
            for(int p = 0; p <= 4; p++){
                for(int l = 0; l <= 4; l++) temp[l] = ini_cards[l];
                s_100 = s_10 = s_5 = s_3 = s_1 = 0;
                for(int c = 1; c <= 52; c++){
                    if(cards[c] == 0){
                        temp[p] = c;
                        earning = best_combination(temp);

                        // if((earning - 1) >= initial_earning){
                            switch (earning)
                            {
                            case 100:
                                s_100++;
                                break;
                            case 10:
                                s_10++;
                                break;
                            case 5:
                                s_5++;
                                break;
                            case 3:
                                s_3++;
                                break;
                            case 1:
                                s_1++;
                                break;
    
                            default:
                                break;
                            }
                        // }
                    }
                }

                // printf("%f %f %f %f %f\n", s_100, s_10, s_5, s_3, s_1);
                // if((s_100 + s_10 + s_5 + s_3 + s_1) == 47){
                    expected_earning = ((s_100/47.0) * 100.0) + ((s_10/47.0) * 10.0) + ((s_5/47.0) * 5.0) + ((s_3/47.0) * 3.0) + ((s_1/47.0) * 1.0) - 2.0;
                    // expected_earning = round(expected_earning * 100) / 100;
                    // printf("%lf\n", initial_earning + 1);
                    if(expected_earning > prev_ex_earning){
                        exchangeable_card = ini_cards[p];
                        // break;
                        prev_ex_earning = expected_earning; // to find out which card's expected value is highest
                    }
                // }
            }


            // Note: if no newline at the end then it fails / wrong answer

            if(exchangeable_card){
                printf("Exchange %s", numToCard(exchangeable_card).c_str());
                exchangeable_card = 0;
            } else {
                printf("Stay");
            }

            printf("\n");

            memset(cards, 0, sizeof cards);
            i = 0;
        }
    }

    // 3H 4C 4H 5H TH
    // 4H 4H 5H 3H 3H
    // 4H 4C 5H 3H 3C
    // 3H 4C TH 3C 4H 

    // 6C 8D TD 6H TH 
    // 6H 5H KS 4D 6D 
    // KS QH AS 7D TD 
    // 2C AC 9H 6D JH 
    // 7H 2H 3H 5S 3D 
    // 4H 3H QS JC 7S 
    // 4C 7D 2C 5H KC 
    // KH 3C 4H 3S QH 
    // QC 9C TH 9S 5S 
    // AH TH 3D 8C QS 


    // TH JH QH KH AH
    // 2H TC 5D 3S 6C
    // 2S 5S 8D JC JH
    // AH 5H 9C 2D 5C
    // AH KH 3H 4H 5C 
    // TH QH AH 3H 5H

    // #

    return 0;
}