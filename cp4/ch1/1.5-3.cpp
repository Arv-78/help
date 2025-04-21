/*
    author: arv
*/
#include <bits/stdc++.h>
using namespace std;

bool isVowel(char &c){
    c = tolower(c);
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
        return true;
    }
    return false;
}


bool isDigit(char &c){
    if(c <= '9' && c >= '0') return true;
    return false;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    char line[256];
    fgets(line, 255, stdin);

    // check for vowel, consonant and digit

    int vowelc, consonantc, digitc;
    vowelc = consonantc = digitc = 0;

    for (int i = 0; i < strlen(line); i++){
        if(isVowel(line[i])) vowelc++;
        else if(isDigit(line[i])) digitc++;
        else consonantc++;

        printf("%c", tolower(line[i]));
    }

    printf("\n vowels: %d\n consonants: %d\n digits: %d\n", vowelc, consonantc, digitc);

    return 0;
}