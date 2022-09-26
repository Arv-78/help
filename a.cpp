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
    int line = 0;
    while(N--){
        if(line) printf("\n");
        line++;
        int a, b, c;
        scanf("%d", &a);
        scanf("%d %d", &b, &c);

        long long int garbage[30][30][30];

        for(int i = 0; i < a; i ++) for(int j = 0; j < b; j++) for(int k = 0; k < c; k++)
            cin>>garbage[i][j][k];

        long long int opt = (1 << 31); //negative number
        long long int tmp[30][30];
        //third dimension
        for(int i = 0; i < a; i++){//0 
            //for 1 slice, again 1 + 2 slice, again 2nd individual slice
            //reset tmp
            memset(tmp, 0, sizeof tmp);
            for(int j = i; j < a; j++){ //0-> 0 1
                //store values in tmp
                for(int k = 0; k < b; k++)
                    for(int l = 0; l < c; l++)
                        tmp[k][l] += garbage[j][k][l];
                
                //for inner slices
                //2d range sum
                long long int inner_slice[30]; long long int kadane[30];
               
                for(int k = 0; k < b; k++){//0 1
                memset(inner_slice, 0, sizeof inner_slice);
                    for(int l = k; l < b; l++){//0 -> 0 1

                        for(int m = 0; m < c; m++){
                            inner_slice[m] += tmp[l][m];
                        }

                        //1d sum //check
                        long long int sum = 0;
                        for(int d = 0; d < c; d++){
                            sum += inner_slice[d];
                            if(sum > opt) opt = sum;
                            if(sum < 0) sum = 0;
                        }

                    }
                }
            }
        }
        cout<<opt<<'\n';

    }
    
    return 0;
}