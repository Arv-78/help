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

    int N,M;//5 4
    scanf("%d %d", &N, &M);
    int ar[N][M];
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            scanf("%d", &ar[i][j]);
    int left = 0, right = M - 1, top = 0, bottom = N - 1;

    while(left <= right && top <= bottom){
        for(int i = left; i <= right; i++){
            cout<<ar[top][i]<<' ';
        }
        top++;
        for(int i = top; i <= bottom; i++){
            cout<<ar[i][right]<<' ';
        }
        right--;
        for(int i = right; i >= left; i--){
            cout<<ar[bottom][i]<<' ';
        }
        bottom--;
        for(int i = bottom; i >= top; i--){
            cout<<ar[i][left]<<' ';
        }
        left++;
    }

    return 0;
}