/*
    author: arv
*/
#include <bits/stdc++.h>
using namespace std;

int n = 4;        //A  B   C   D
int dist[4][4] = {{0, 20, 42, 35}, //A
                  {20, 0, 30, 34},  //B
                  {42, 30, 0, 12},  //C
                  {35, 34, 12, 0}}; //D
//state pos -> currently visited city
//      mask -> subset of visited cities if 0 - not if 1 - visited
int tsp(int pos, int mask){ //O(n*n*2^n) pos from 0 to n - 1 and mask 0 to 2^n - 1 states 
//for each state loop from 0 to n

    //if all cities are visited
    //mask = (1 << n) - 1
    if(mask == (1 << n) - 1){
        return dist[pos][0];
    }

    //for all cities from 0 to n - 1
    int ans = 1000000;
    for(int nxt = 0; nxt < n; nxt++){  //O(n)
        if(!(mask & (1 << nxt)) && pos != nxt)//if city not visited
        ans = min(ans, dist[pos][nxt] + tsp(nxt, mask | (1 << nxt)));//add city to subset
    }

    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // TSP traveling salesman problem
    printf("%d", tsp(0, 1)); // first city is being visited
    return 0;
}