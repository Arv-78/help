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
    
    /*
        cs - count start; the signal with min time will show orange first;
        agt - all green time; time after all turns green

        if time = 70 and signal_time = 25 then first 25 green; second 25 red; third 20 green; but 5 sec are orange so 71 second is not green 
        
        25 * 1 = 25; 25 * 2 = 50; 25 * 3 = 75; 51th sec would be green after first orange that is the reason of checking (time / signal_time) % 2 == 0
        but 70 % 25 = 20 and 71 will be orange (as last 5 sec of cycle is orange(25 - 20 should be greater than 5[ornage secs])) so check (signals[j] - (time % signals[j]) <= 5) to make sure it is not in orange
    */ 
    
    int signals[105], cs = 100, agt;
    int i = 0;
    while(scanf(" %d", &signals[i]) != EOF && (signals[0] != 0 || signals[1] != 0 || signals[2] != 0)){
        if(cs > signals[i] && signals[i] != 0) cs = signals[i]; // find min signal time

        if(signals[i] == 0 && i >= 2){
            agt = -1;
            // smallest time signal turn green after green - red - green
            cs = cs * 2;

            for(int time = cs; time <= 5 * 3600; time++){
                int allGreen = 1;
                for(int j = 0; j <= i - 1; j++){
                    if((time / signals[j]) % 2 != 0 || (signals[j] - (time % signals[j]) <= 5)){ // Note: Imp (green and orange check)
                        allGreen = 0;
                        break;
                    }
                }
                if(allGreen){
                    agt = time;
                    break;
                }
            }

            if(agt == - 1){
                printf("Signals fail to synchronise in 5 hours\n");
            } else {
                int hrs = (agt / 60) / 60;
                int minutes = (agt / 60) % 60;
                int seconds = agt % 60;

                printf("%02d:%02d:%02d\n", hrs, minutes, seconds);
            }
            i = 0;
        } else {
            i++;
        }

    }


    return 0;
}