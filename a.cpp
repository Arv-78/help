/*
    author: arv
*/
#include <bits/stdc++.h>
using namespace std;


//sort array in decreasing order of IQs
bool compare(pair < int, int > a, pair < int, int > b){
    return (a.second >= b.second);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    vector <pair <int, int>> ele;
    int wt, iq;
    while(scanf("%d %d", &wt, &iq) != EOF){
        ele.push_back({wt, iq});
    }
    vector <pair <int, int>> ele_sorted(ele);
    
    sort(ele_sorted.begin(), ele_sorted.end(), compare);


    //finding lis of wts using O(nlogk)
    int L[10001], L_id[10001], id[10001];
    int lis = 0, lis_end = 0;

    for(int i = 0; i < ele.size(); i++){
        int pos = lower_bound(L, L + lis, ele_sorted[i].first) - L;
        L[pos] = ele_sorted[i].first;
        L_id[pos] = i;
        id[i] = pos ? L_id[pos - 1] : -1;

        if(pos + 1 > lis){
            lis = pos + 1;
            lis_end = i;
        }
    }
    

    cout<<lis<<'\n';
    stack <int> idx;
    //getting indexes of original array
    int i = lis_end;
    for(; i != -1; i = id[i]){
        for(int j = 0; j < ele.size(); j++){
            if(ele_sorted[i] == ele[j]){
                idx.push(j + 1);
                break;
            }
        }
    }
    while(!idx.empty()){
        cout<<idx.top()<<'\n';
        idx.pop();
    }
    return 0;
}