#include <bits/stdc++.h>
using namespace std;

//UVa 11956 - Brainfuck

int main(){

    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

    int t, cs = 0;
    scanf("%d", &t);
    while(t--){
        char str[1000005];
        //getline(cin, str); //scanf not working
        //getchar(); //solution look below line
        scanf(" %s", &str);//their is a leading zero
        int idx = 0;
        //unsigned char mem[100] = {}; //why range 0 to 255
        int mem[100] = {0};
        for(int i = 0; str[i]; i++){
            switch (str[i]){
                case '>': idx++;break;
                case '<': idx--;break;
                case '+': mem[idx]++;if(mem[idx] > 255) mem[idx] = 0; break; 
                case '-': mem[idx]--;if(mem[idx] < 0) mem[idx] = 255; break; 
            }
            if(idx > 99) idx = 0;
            if(idx < 0) idx = 99;
        }

        printf("Case %d:", ++cs);
        for(auto i : mem)
            printf(" %02X", i);
        puts("");
    }
    
    
    return 0;
}