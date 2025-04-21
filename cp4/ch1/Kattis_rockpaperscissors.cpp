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
    
    int p, p1, p2, k;
    float points[110][2], t_p = -1;
    char ph1[100], ph2[100];
    map<string, string> lookup = {
        {"rock", "scissors"}, // rock wins over scissors
        {"paper", "rock"},
        {"scissors", "paper"}
    };

    while(scanf("%d", &p) != EOF, p != 0){
        scanf("%d", &k);
        memset(points, 0, sizeof points);
        if(t_p != -1) printf("\n");
        t_p = 0;

        int g = (k * p * (p - 1)) / 2;

        while(g--){
            scanf("%d %s %d %s", &p1, ph1, &p2, ph2);

            if(strcmp(lookup[string(ph1)].c_str(), ph2) == 0){
                points[p1][0] += 1;
                points[p2][1] += 1;
                t_p++;
            } else if(strcmp(lookup[string(ph2)].c_str(), ph1) == 0) {
                points[p2][0] += 1;
                points[p1][1] += 1;
                t_p++;
            }
        }

        for(int i = 1; i <= p; i++){
            if(t_p == 0){
                printf("-\n");
            } else{
                printf("%.3f\n", (1 / (points[i][0] + points[i][1])) * points[i][0]);
            }
        }

    }
    
    return 0;
}