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
    
    // not considering scenario where there could be a ladder on position 1

    int N;
    // int *p_pos = (int*)malloc(1000005 * sizeof(int));
    int p, p_t, s_n, r, s_n_lookup[105];

    scanf("%d", &N); 

    while(N--){
        // memset(p_pos, 0, 1000005 * sizeof (int));
        memset(s_n_lookup, 0, sizeof s_n_lookup);

        scanf("%d %d %d", &p, &s_n, &r);

        int p_pos[p+5];
        memset(p_pos, 0, sizeof p_pos);

        while(s_n--){
            int start, end;
            scanf("%d %d", &start, &end);
            s_n_lookup[start] = end;
        }

        p_t = 1; // player 1
        bool win = false;
        while(r--){

            if(p_t > p){  //loop through the players
                p_t = 1;
            }

            int r_value;
            scanf("%d", &r_value);

            if(p_pos[p_t] == 0) p_pos[p_t] = 1;

            if (!win){
                p_pos[p_t] += r_value;

                while(s_n_lookup[p_pos[p_t]] != 0){ 
                    p_pos[p_t] = s_n_lookup[p_pos[p_t]];
                }
    
            }

            if(p_pos[p_t] >= 100) {
                win = true;          
            }

            p_t++;
        }

        for(int i = 1; i <= p; i++){
            printf("Position of player %d is %d.\n", i, p_pos[i]); 
        }
    }
    // free(p_pos);

    return 0;
}