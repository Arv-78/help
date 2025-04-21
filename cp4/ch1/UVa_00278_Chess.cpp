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

    int N;
    scanf("%d", &N);

    char p;
    int m, n;

    while(N--){
        scanf(" %c %d %d", &p, &m, &n);

        //conditions
        if(p == 'r'){ // rook
            printf("%d", min(m, n));
        } else if(p == 'K'){ // king
            printf("%d", (int)(ceil(m / 2.0) * ceil(n / 2.0)));
        } else if(p == 'k'){ // knight
            printf("%d", (int)ceil((m * n)/2.0));
        } else if(p == 'Q'){ // queen
            printf("%d", min(m, n));
        }
        printf("\n");
    }

    return 0;
}