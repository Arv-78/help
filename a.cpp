/*
    author: arv
*/
#include <bits/stdc++.h>
using namespace std;

int v[] = {100, 70, 50, 10};
int w[] = {10, 4, 6, 12};
int n = 4;
int val(int id, int remW){

    if(id == n) return 0;

    if(remW == 0) return 0;

    if(w[id] > remW) //if weight is more than remW ignore 
        return val(id + 1, remW);

    //take or ignore value
    //val(id, remW) = max(val(id + 1, remW), v[id] + val(id + 1, remW - w[id]))

    return max(val(id + 1, remW), v[id] + val(id + 1, remW - w[id]));
    // (2, 12, ()),100
}

int main()
{
    //v[100, 70, 50, 10] w[10, 4, 6, 12] s = 12


    cout<<val(0, 12);




    return 0;
}