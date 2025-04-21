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
    
    int n1, n2, c, ac;
    scanf("%d %d", &n1, &n2);

    if(n1 > n2){
        c = 360 - n1 + n2;
        ac = -(n1 - n2);
    } else if(n1 < n2){
        c = n2 - n1;
        ac = -(360 - n2 + n1);
    } else {
        c = 0;
        ac = 360;
    }

    if(abs(c) == abs(ac)){
        printf("%d\n", 180);
    } else if(abs(c) > abs(ac)){
        printf("%d\n", ac);
    } else {
        printf("%d\n", c);
    }

    return 0;
}