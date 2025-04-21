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
       
       int N;
       scanf("%d", &N);
       char guess[10], secret_code[10], t_guess[10], t_secret_code[10]; // max length 5
       int c, w, secret_codes;
       int lookup[15];
       int tw, tc;
       
       while(N--){
           secret_codes = 0;
           memset(lookup, 0, sizeof lookup); // reset
           scanf("%s %d %d", guess, &c, &w);

           for(int i = 0; i < strlen(guess); i++){ // set lookup
               lookup[guess[i] - '0'] = 1;
           }

           // first two conditions are for optimization that made execution time 60 percent faster from 0.50 to 0.20

           // if correct colors at correct position equals to the length of guess then thats the secret code
           if(c == strlen(guess)){
               secret_codes = 1;
           } else if(c + w == strlen(guess)){
               strcpy(secret_code, guess);
               //count c and w for a secret code that could be
               sort(secret_code, secret_code + strlen(secret_code));
               do {
                   // printf("%s\n", secret_code);
                   tc = 0, tw = 0;
                   for(int i = 0; i < strlen(secret_code); i++){
                       if(secret_code[i] == guess[i]){
                           tc++;
                           if(tc > c) break;
                       } else if(lookup[secret_code[i] - '0'] == 1){
                           tw++;
                           if(tw > w) break;
                       }
                   }

                   if(tc == c && tw == w){
                       printf("%s\n", secret_code);
                       secret_codes++;
                   }
                   
               } while(next_permutation(secret_code, secret_code + strlen(secret_code)));
           } else {
               for(int i = 0; i < 9; i++) secret_code[i] = '1'; // secret_code will be "1111111111"
               secret_code[strlen(guess)] = '\0';

               int start = 0, end = strlen(guess) - 1, a, b;
               int pointer = end;

               while(1){
                   a = 0; b = 0;
                   //copy secret_code into secret_code and guess
                   strcpy(t_secret_code, secret_code);
                   strcpy(t_guess, guess);

                   //check and eliminate right colors at right position
                   for(int i = 0; i <= end; i++){
                       if(t_secret_code[i] == t_guess[i]){
                           a++;
                           t_guess[i] = '0';
                           t_secret_code[i] = '0';
                       }
                   }

                   // fill lookup to check wrong positioned colors
                   memset(lookup, 0, sizeof lookup); //reset
                   for(int i = 0; i < strlen(t_secret_code); i++){
                       if(t_secret_code[i] != '0') lookup[t_secret_code[i] - '0'] += 1;
                   }

                   //check for right colors at wrong position
                   for(int i = 0; i <= end; i++){
                       if(lookup[t_guess[i] - '0'] > 0 && t_guess[i] != '0'){
                           //if not eliminated positions then check if it is wrongly positioned
                           lookup[guess[i] - '0'] -= 1;
                           b++;
                       } 
                   }
                   
                   if(a == c && b == w){
                       secret_codes++;
                   }

                   // go from 111... to 999...

                   secret_code[pointer]++;

                   if(secret_code[pointer] > '9'){
                       while(secret_code[pointer] > '9'){
                           secret_code[pointer] = '1';
                           pointer--;
                           if(pointer < 0){
                               break;
                           }
                           secret_code[pointer]++;
                       }

                       if(pointer < 0){
                           break;
                       }

                       pointer = end;
                   }

               }
           }

           printf("%d\n", secret_codes);
           


       }

       return 0;
   }