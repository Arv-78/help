/*
    author: arv
*/
#include <bits/stdc++.h>
using namespace std;

char board[15][15];
int ans, n;
bitset <30> rw, rd, ld;
void backtrack(int c){
    if(c == n) {ans++;}

    for(int r = 0; r < n; r++){
        if(board[r][c] != '*' && !rw[r] && !rd[r + c] && !ld[r - c + n - 1]){
            rw[r] = rd[r + c] = ld[r - c + n - 1] = true;
            backtrack(c + 1);
            rw[r] = rd[r + c] = ld[r - c + n - 1] = false;
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int tcn = 0;
    while(scanf("%d", &n), n){
        for(int r = 0; r < n; r++)
            for(int c = 0; c < n; c++){
                char ch; cin>>ch; board[r][c] = ch;
            }

        ans = 0;
        backtrack(0);
        printf("Case %d: %d\n", ++tcn, ans);                
    }
    return 0;
}