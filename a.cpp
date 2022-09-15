/*
    author: arv
*/
#include <bits/stdc++.h>
using namespace std;

int A[] = {-7, 10, 9, 2, 3, 8, 8, 1};
//finding LIS for state LIS(i)
int LIS(int i){

    if(i == 0) return 1;
    int tp = -10000000;
    for(int j = 0; j < i; j++){
        if(A[j] < A[i]){
            tp = max(tp, LIS(j) + 1);
        }
    }
    return tp;
}

int main()
{
    int max = 0; int idx = 0, tp;
    //finding LIS for each i and find max LIS id
    for(int i = 0; i <= 7; i++){
        tp = LIS(i);
        if(tp > max){
            max = tp;
            idx = i;
        }
    }
    //print LIS
    for(int i = 0; i <= idx; i++){
        if(A[i] <= A[idx]) printf("%d ", A[i]);
    }

    return 0;
}