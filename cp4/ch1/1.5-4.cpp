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
    char *token = strtok(line, " .");
    while (token != NULL){
        tokens.push_back(token);
        token = strtok(NULL, " .");
    }

    // sort
    sort(tokens.begin(), tokens.end());

    printf("%s", tokens[0].c_str());

    return 0;
}