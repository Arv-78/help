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
    //print all numbers from 01234 *(2 to 79) == 98765
    for(int N = 2; N <= 79; N++){
        for(int fghij = 1234; fghij <= 98765 / N; fghij ++){
            int abcde = fghij * N;
            int tmp, used = (fghij < 10000);
            tmp = fghij; while(tmp) {used |= 1 << (tmp % 10); tmp /= 10;}
            tmp = abcde; while(tmp) {used |= 1 << (tmp % 10); tmp /= 10;}
            if(used == (1 << 10) - 1){//check for all numbers are used 
                printf("%0.5d / %0.5d = %d\n", abcde, fghij, N);
            }
        }
    }
    
    return 0;
}