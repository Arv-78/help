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

    char line[105];
    fgets(line, 100, stdin);

    vector<string> tokens;
    map<string, int> counts; // to count frequency
    char *token = strtok(line, " .");
    while (token != NULL){
        tokens.push_back(token);
        token = strtok(NULL, " .");
    }

    for(vector<string>::iterator it = tokens.begin(); it != tokens.end(); it++){
        counts[it->c_str()]++;
    }

    // work with max frequency, as map sorts its elements using the values 
    // last element is of max frequency
    printf("%s", counts.rbegin()->first.c_str());

    // for(auto &pair : counts){
    //     printf("%s -> %d\n", pair.first.c_str(), pair.second);
    // }


    return 0;
}