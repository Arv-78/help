#include<bits/stdc++.h>

using namespace std;

int matrix[1005][1005];

int main(){

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif


    //take the input
    int N, M;
    int line = 0;
    while(scanf("%d %d", &N, &M) == 2){
        if(line) printf("\n");
        line++;
        //fill the matrix with preprocessing cumulative sum matrix
        for(int i = 0; i < N; i++) 
            for(int j = 0; j < N; j++){
                scanf("%d", &matrix[i][j]);
                if(i > 0) matrix[i][j] += matrix[i - 1][j];
                if(j > 0) matrix[i][j] += matrix[i][j - 1];
                if(i > 0 && j > 0) matrix[i][j] -= matrix[i - 1][j - 1];
            }

        //print [N-M+1][N-M+1] submatrix
        int whole_sum = 0;
        for(int i = 0; i < N; i++) //starting indices O(N^2)
            for(int j = 0; j < N; j++){
                int k = i + M - 1;//end indices
                int l = j + M - 1;
                if(k < N && l < N){
                    //sum of submatrix
                    int sum = 0;

                    //cal sum using O(1)
                    sum = matrix[k][l];
                    if(i > 0)
                    sum -= matrix[i - 1][l];
                    if(j > 0)
                    sum -= matrix[k][j - 1];

                    if(i > 0 && j > 0) sum += matrix[i - 1][j - 1];

                    // for(int a = i; a <= k; a++) 
                    //     for(int b = j; b <= l; b++){
                    //         sum += matrix[a][b];
                    //     }
                    printf("%d\n", sum);
                    whole_sum += sum;
                }
            }
        printf("%d\n", whole_sum);

    }



    return 0;
}