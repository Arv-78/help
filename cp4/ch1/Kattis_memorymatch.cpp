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


    int n, k, score = 0;
    scanf("%d %d", &n, &k);

    int cards[n];
    vector<string> card_strs(n);
    map<string, int> lookup;
    memset(cards, 0, sizeof cards); //at first all cards unknown
    while(k--){
        int c1, c2;
        char p1[25], p2[25];

        scanf("%d %d %s %s", &c1, &c2, p1, p2);

        card_strs[c1 - 1] = p1;
        card_strs[c2 - 1] = p2;

        if(strcmp(p1, p2) == 0){
            cards[c1 - 1] = -1;
            cards[c2 - 1] = -1;
        } else {
           cards[c1 - 1] = 1;
           cards[c2 - 1] = 1;
        }
    }

    for(int i = 0; i < n; i++){ // check for pairs that are known
        if(cards[i] == 1){
            if(lookup.find(card_strs[i]) == lookup.end()){
                lookup[card_strs[i]] = i;
            } else {
                score ++;
                cards[lookup[card_strs[i]]] = -1;
                cards[i] = -1;
            }
        }
    }

    int no_of_unknown = 0;
    int no_of_known = 0;

    for(int i = 0; i < n; i++){
        if(cards[i] == 1){
            no_of_known++;
        }
        if(cards[i] == 0){
            no_of_unknown++;
        }
    }

    if(no_of_known == no_of_unknown){//if no. of unknowns are equal to no. of known then a turned card will match with one of them
        score += no_of_known;
    } else if(no_of_unknown == 2){ //if 2 unknowns are remaining then they must be same
        score ++;
    }

    printf("%d", score);


    return 0;
}