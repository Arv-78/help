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
    
    int prev[128];
    prev['W'] = 'Q';
    prev['E'] = 'W';
    prev['R'] = 'E';
    prev['T'] = 'R';
    prev['Y'] = 'T';
    prev['U'] = 'Y';
    prev['I'] = 'U';
    prev['O'] = 'I';
    prev['P'] = 'O';
    prev['['] = 'P';
    prev[']'] = '[';
    prev['\\'] = ']';
    prev['S'] = 'A';
    prev['D'] = 'S';
    prev['F'] = 'D';
    prev['G'] = 'F';
    prev['H'] = 'G';
    prev['J'] = 'H';
    prev['K'] = 'J';
    prev['L'] = 'K';
    prev[';'] = 'L';
    prev['\''] = ';';
    prev['X'] = 'Z';
    prev['C'] = 'X';
    prev['V'] = 'C';
    prev['B'] = 'V';
    prev['N'] = 'B';
    prev['M'] = 'N';
    prev[','] = 'M';
    prev['.'] = ',';
    prev['/'] = '.';
    prev[' '] = ' ';
    prev['\n'] = '\n';
    prev['1'] = '`';
    prev['2'] = '1';
    prev['3'] = '2';
    prev['4'] = '3';
    prev['5'] = '4';
    prev['6'] = '5';
    prev['7'] = '6';
    prev['8'] = '7';
    prev['9'] = '8';
    prev['0'] = '9';
    prev['-'] = '0';
    prev['='] = '-';

    char ch;
    while(scanf("%c", &ch) != EOF){
        printf("%c", prev[ch]);
    }

    return 0;
}