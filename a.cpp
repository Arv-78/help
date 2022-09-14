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
    
    // int A[4][4] = {{0, -2, -7, 0},
    //                {9, 2, -6, 2},
    //                {-4, 1, -4, 1},
    //                {-1, 8, 0, -2}};

    // int maxSum = -127 * 100 * 100;
    // int n = 4;
    // //first coordinates
    // for(int i = 0; i < 4; i++)
    //     for(int j = 0; j < 4; j++)
    //         //last coordinates
    //         for(int k = i; k < n; k++){
    //             for(int l = j; l < n; l++){
    //                 int sum = 0;
    //                 for(int a = i; a <= k; a++)
    //                     for(int b = j; b < l; b++)
    //                         sum += A[a][b];
    //                 maxSum = max(maxSum, sum);
    //             }
    //         }

    // printf("%d", maxSum);

    int n = 4;
    int A[4][4];

    //cumulative sum array
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &A[i][j]);
            if(i > 0) A[i][j] += A[i - 1][j];
            if(j > 0) A[i][j] += A[i][j - 1];
            if(i > 0 && j > 0) A[i][j] -= A[i - 1][j - 1];
        }
    }

    int maxSum = -127 * 100 * 100;
    // finding largest sum for each (i, j) to (k, l)
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = i; k < n; k++){
                for(int l = j; l < n; l++){
                    int sum = A[k][l];
                    if(i > 0) sum -= A[i - 1][l];
                    if(j > 0) sum -= A[k][j - 1];
                    if(i > 0 && j > 0) sum += A[i - 1][j - 1];

                    maxSum = max(maxSum, sum);
                }
            }
        }
    }

    printf("%d\n", maxSum);

    return 0;
}