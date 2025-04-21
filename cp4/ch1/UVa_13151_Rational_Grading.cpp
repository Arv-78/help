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
    
    // convert i value into decimal 
    char ivalue[10], expression[10];
    int i, T, ExV, score; // ExV - examinee's value

    while(scanf("%s %d", ivalue, &T) == 2, T){
        i = score = 0;
        if(ivalue[0] == '0' && ivalue[1] != 'x'){ // octal
            int exp = 0;
            for(int j = strlen(ivalue) - 1; j > 0; j--){
                i += (ivalue[j] - '0') * int(pow(8, exp));
                exp++;
            }
        } else if(ivalue[0] == '0' && ivalue[1] == 'x'){ // hex
            int exp = 0;
            for(int j = strlen(ivalue) - 1; j > 1; j--){
                if(isdigit(ivalue[j])){
                    i += (ivalue[j] - '0') * int(pow(16, exp));
                } else {
                    i += (10 + ivalue[j] - 'A') * int(pow(16, exp));
                }
                exp++;
            }
        } else {
            int exp = 0;
            for(int j = strlen(ivalue) - 1; j >= 0; j--){
                i += (ivalue[j] - '0') * int(pow(10, exp));
                exp++;
            }
        }

        while(T--){
            scanf("%s %d", expression, &ExV);
            int val;

            if(strlen(expression) == 1){
                val = i;
                i = ExV; // next expression's input is prev erpression's output not the printed value
            } else if(expression[0] == '-'){
                val = i - 1;
                i = ExV;
            } else if(expression[2] == '-'){
                val = i;
                i = ExV - 1;
            } else if(expression[0] == '+'){
                val = i + 1;
                i = ExV;
            } else if(expression[2] == '+'){
                val = i;
                i = ExV + 1;
            }            

            if(val == ExV){
                score++;
            }
        }

        printf("%d\n", score);
        
    }
    
    return 0;
}