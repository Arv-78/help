#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> iii;

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    vector<iii> birthdays;
    birthdays.emplace_back(5, 24, -1980);
    birthdays.emplace_back(5, 24, -1982);
    birthdays.emplace_back(11, 13, -1983); //82 80 83

    sort(birthdays.begin(), birthdays.end());

    for(auto &[mm, dd, yyyy] : birthdays){
        printf("%d %d %d\n", dd, mm, -yyyy);
    }
}