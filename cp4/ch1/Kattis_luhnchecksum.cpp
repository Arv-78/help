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
   
   int T; 
   char num[55];

   scanf("%d", &T);

   while(T--){
    scanf("%s", num);
    int sz = strlen(num);

    // transform
    for(int i = sz - 2; i >= 0; i-=2){
        int n = num[i] - '0';
        if(n * 2 > 9){
            num[i] = (((n * 2) % 10) + ((n * 2) / 10)) + '0';
        } else {
            num[i] = n * 2 + '0';
        }
    }

    //sum
    int sum = 0;
    for(int i = sz - 1; i >= 0; i--){
        sum += num[i] - '0';
    }

    if(sum % 10 == 0){
        printf("PASS\n");
    } else {
        printf("FAIL\n");
    }

   }
    
    return 0;
}