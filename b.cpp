#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    int problems[26];
    memset(problems, 0, sizeof problems);
    char dec[6]; int t; char prob;
    int tt = 0, rProblems = 0;
    string line;
    while(getline(cin, line), line != "-1"){
        sscanf(line.c_str(), "%d %c %s", &t, &prob, &dec);
        if(!strcmp(dec, "right") && problems[prob - 'A'] != -1){
            tt += t;
            tt += problems[prob - 'A'];
            problems[prob - 'A'] = -1;
            rProblems ++;
        } else {
            problems[prob - 'A'] += 20;
        }
    }
    printf("%d %d", rProblems, tt);

    return 0;
}
