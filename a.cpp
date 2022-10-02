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
    
    //refer - https://saicheems.wordpress.com/2013/11/08/uva-111-history-grading/


    int N, tmp;
    cin>>N;

    int rank[21];
    int rank_student[21];
    int table[50][50];

    memset(table, 0, sizeof table);
    //reordering events according to rank
    for(int i = 1; i <= N; i++){
        cin >> tmp;
        rank[tmp] = i;
    }

    while(cin >> tmp){
        rank_student[tmp] = 1;

        for(int i = 2; i <= N; i++){
            cin>>tmp;
            rank_student[tmp] = i;
        }
        //longest common subsequence 

        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(rank[i] == rank_student[j]) table[i][j] = table[i - 1][j - 1] + 1;
                else table[i][j] = max(table[i - 1][j], table[i][j - 1]);
            }
        }

        cout<<table[N][N]<<endl;
        
    }



    return 0;
}