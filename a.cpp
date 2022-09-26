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
    int matrix[30][30];
    int ct = 0;
    while(N--){
        if(ct) printf("\n");
        ct++;
        memset(matrix, -999999, sizeof matrix);
        string s;
        cin>>s;
        int n = s.length();
        
        //read input
        for(int j = 0; j < n; j++){
            for(int i = 0; i < n; i++){
                if((int)s[i] == 49)matrix[j][i] = 1;
            }
            if(j < n - 1) cin>>s;
        }
    
        int max_sum = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int k = i; k < n; k++){
                    for(int l = j; l < n; l++){
                        int ans = 0; int flag = 0;
                        for(int a = i; a <= k; a++) {
                            if(flag) break;
                            for(int b = j; b <= l; b++){
                                if(matrix[a][b] < 0){
                                    flag = 1;
                                    ans = 0;
                                    break;
                                }else{
                                    ans++;
                                }

                            }
                        }
                        max_sum = max(ans, max_sum);
                }
            }
        }
    }

        
    cout<< max_sum<<'\n';
        
    }


    return 0;
}