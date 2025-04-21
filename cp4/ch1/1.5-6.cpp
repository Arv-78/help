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

    int count = 0, ch;

    while((ch = getc(stdin)) != '\n'){
        count++;
        printf("%c", ch);
    }

    printf("\ncount: %d", count);

    return 0;
}