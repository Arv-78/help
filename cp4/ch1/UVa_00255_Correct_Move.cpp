/*
    author: arv
*/
#include <bits/stdc++.h>
using namespace std;

int line_end(int& p){
    int l_end = 7;
    while(l_end < p) {
        l_end += 8;
    }
    return l_end;
}


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int k, q, qn;
    //legal moves -> 1, illegal moves -> -1, not allowed moves -> 0
    map <int, int> km;
    map <int, int> qm;

    while(scanf("%d %d %d", &k, &q, &qn) != EOF){
        km.clear(); //reset
        qm.clear(); //reset

        //calculate moves if the state is legal
        if(k == q){
            printf("Illegal state\n");
            continue;
        }
        //king's
        if(k > (line_end(k) - 7)){ // can move left
            km[k - 1] = 1;
        } 
        if(k < line_end(k)){ // can move right
            km[k + 1] = 1;
        }
        if(k - 8 > -1){ // can move up
            km[k - 8] = 1;
        }
        if(k + 8 < 64){ // can move down
            km[k + 8] = 1;
        }

        //queen's
        int qlend = line_end(q);
        bool is_k_encountered = false;

        for(int i = q - 1; i >= qlend - 7; i--){ // can move left
            if(!is_k_encountered){//legal move
                qm[i] = 1;

                //calculate not allowed move
                if(km.find(i) != km.end()){
                    km[i] = 0;
                    qm[i] = 0;
                }
            } else {
                qm[i] = -1;
            }
            
            //check k is encountered
            if(i == k){
                is_k_encountered = 1;
                qm[i] = -1;
            }
        }

        is_k_encountered = false;

        for(int i = q + 1; i <= qlend; i++){ // can move right
            if(!is_k_encountered){//legal move
                qm[i] = 1;

                // calculate not allowed move
                if(km.find(i) != km.end()){
                    km[i] = 0;
                    qm[i] = 0;
                }
            } else {
                qm[i] = -1;
            }

            //check k is encountered
            if(i == k){
                is_k_encountered = 1;
                qm[i] = -1;
            }
        }

        is_k_encountered = false;

        for(int i = q - 8; i > -1; i -= 8){ // can move up
            if(!is_k_encountered){//legal move
                qm[i] = 1;

                // calculate not allowed move
                if(km.find(i) != km.end()){
                    km[i] = 0;
                    qm[i] = 0;
                }
            } else {
                qm[i] = -1;
            }

            //check k is encountered
            if(i == k){
                is_k_encountered = 1;
                qm[i] = -1;
            }
        }

        is_k_encountered = false;

        for(int i = q + 8; i < 64; i += 8){ // can move down
            if(!is_k_encountered){//legal move
                qm[i] = 1;

                // calculate not allowed move
                if(km.find(i) != km.end()){
                    km[i] = 0;
                    qm[i] = 0;
                }
            } else {
                qm[i] = -1;
            }

            //check k is encountered
            if(i == k){
                is_k_encountered = 1;
                qm[i] = -1;
            }
        }


        // rest of the conditions
        // if qn is illegal
        if(qm.find(qn) != qm.end()){
            if(qm[qn] == 1){
                //legal and allowed
                // check for stop
                if((k == 0 && qn == 9) || 
                    (k == 7 && qn == 14) || 
                    (k == 56 && qn == 49) || 
                    (k == 63 && qn == 54)){
                        printf("Stop");
                    } else {
                        printf("Continue");
                    }
                
            } else if(qm[qn] == 0){
                printf("Move not allowed");
            } else{
                printf("Illegal move");
            }
        } else {
            printf("Illegal move");
        }

        printf("\n");


        // for(pair<const int, int>& p : km){
        //     printf("%d %d\n", p.first, p.second);
        // }

    }

    return 0;
}