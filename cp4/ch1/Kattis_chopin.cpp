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
    
    int cc = 1;
    char alternate[5][2][10] = {
        {"A#", "Bb"},
        {"C#", "Db"},
        {"D#", "Eb"},
        {"F#", "Gb"},
        {"G#", "Ab"}
    };

    char note[4], tone[10];

    while(scanf("%s %s", note, tone) != EOF){
        if(strlen(note) == 1){
            printf("Case %d: UNIQUE\n", cc);
        } else {
            for(int i = 0; i < 5; i++){
                if(strcmp(alternate[i][0], note) == 0){
                    printf("Case %d: %s %s\n", cc, alternate[i][1], tone);
                } else if(strcmp(alternate[i][1], note) == 0){
                    printf("Case %d: %s %s\n", cc, alternate[i][0], tone);
                }
            }
        }
        cc++;
    }

    return 0;
}