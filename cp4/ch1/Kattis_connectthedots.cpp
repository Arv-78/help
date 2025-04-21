/*
    author: arv
*/
#include <bits/stdc++.h>
using namespace std;

int input[105][105];
int seq_p[65][2];
char line[105];
int r = 0;

void format_input(){
    for(int f = 0; f <= 65; f++){
        int t = f + 1;
        // keep array size greater than 62 (0-61) to work this condition 
        if((seq_p[t][0]== -1) && (seq_p[t][1] == -1)) break;

        // right direction
        if(seq_p[t][1] > seq_p[f][1]){
            for(int i = seq_p[f][1] + 1; i < seq_p[t][1]; i++){
                if(input[seq_p[t][0]][i] == '|')  input[seq_p[t][0]][i] = '+';
                else if(input[seq_p[t][0]][i] == '.') input[seq_p[t][0]][i] = '-';
            }
        }

        // left direction
        if(seq_p[t][1] < seq_p[f][1]){
            for(int i = seq_p[t][1] + 1; i < seq_p[f][1]; i++){
                if(input[seq_p[t][0]][i] == '|')  input[seq_p[t][0]][i] = '+';
                else if(input[seq_p[t][0]][i] == '.') input[seq_p[t][0]][i] = '-';
            }
        }

        // top direction
        if(seq_p[t][0] < seq_p[f][0]){
            for(int i = seq_p[t][0] + 1; i < seq_p[f][0]; i++){
                if(input[i][seq_p[t][1]] == '-') input[i][seq_p[t][1]] = '+';
                else if(input[i][seq_p[t][1]] == '.') input[i][seq_p[t][1]] = '|';
            }
        }

        // down direction 
        if(seq_p[t][0] > seq_p[f][0]){
            for(int i = seq_p[f][0] + 1; i < seq_p[t][0]; i++){
                if(input[i][seq_p[t][1]] == '-') input[i][seq_p[t][1]] = '+';
                else if(input[i][seq_p[t][1]] == '.') input[i][seq_p[t][1]] = '|';
            }
        }
    }

    //print formated input
    for(int i = 0; i <= 100; i++){
        if(input[i][0] == -1) break;
        for(int j = 0; j <= 100; j++){
            if(input[i][j] == -1) break;
            printf("%c", input[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    memset(input, -1, sizeof input);
    memset(seq_p, -1, sizeof seq_p);

    while(fgets(line, sizeof line, stdin)){
        if(strcmp(line, "\n") == 0){
            format_input();
            printf("\n");
            r = 0;
            memset(input, -1, sizeof input);
            memset(seq_p, -1, sizeof seq_p);
        } else {
            for(int i = 0; i < 105; i++){
                if(line[i] == '\n' || line[i] == '\0') break;

                input[r][i] = line[i];

                if(isdigit(line[i])){
                    seq_p[line[i] - '0'][0] = r;
                    seq_p[line[i] - '0'][1] = i;
                } else if(isalpha(line[i])){
                    if(isupper(line[i])){
                        seq_p[line[i] - 'A' + 36][0] = r;
                        seq_p[line[i] - 'A' + 36][1] = i;
                    } else {
                        seq_p[line[i] - 'a' + 10][0] = r;
                        seq_p[line[i] - 'a' + 10][1] = i;
                    }
                }
            }
            r++;
        }
    }

    format_input();

    return 0;
}