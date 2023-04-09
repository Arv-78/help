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
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    char str[500];
    char one[100];
    int j = 0;
    while(cin.getline (one, 99, '\n')){ //size -> 99 + null char -> 100 chars
        int i = 0;
        if(strstr(one, ".......") == NULL){
            while(one[i] != '\0'){
                str[j] = one[i];
                j++; i++;
            }
        }
    }

    printf("%s", str);

    return 0;
}