/*
    author: arv
*/
#include <bits/stdc++.h>
#define EPS 1e-9

using namespace std;

char evs[50];
int flc[50];
int dis[50];

bool can(double cp){
    //simulate if cp satisfies the conditions

    int cur, prev, leak = 0, fc = flc[0];
    int ct = 0;
    double tank = 0.0, fl = 0.0;
    prev = 0; 
    while(evs[ct + 1]){
        ct++;
        cur = dis[ct];
        fl += (fc/100.0) * (cur - prev);
        fl += leak * (cur - prev);
        prev = cur;
        tank = max(tank, fl);
        if(evs[ct] == 'f') fc = flc[ct];
        else if(evs[ct] == 'l') leak++;
        else if(evs[ct] == 'g') fl = 0.0;
        else if(evs[ct] == 'm') leak = 0;

    }

    if(tank <= cp) return true;
    return false;
}


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    
    int d, fc;
    int ct; 
    // string s;
    char s[50];//check
    while(scanf("%d Fuel consumption %d", &d, &fc), (d || fc)){
        ct = 0;
        memset(flc, 0, sizeof(flc));//check
        memset(dis, 0, sizeof(dis));
        dis[ct] = d; flc[ct] = fc; evs[0] = 'f';
        while(1){
            ++ct;
            scanf("%d", &d); 
            scanf("%s", s);
            dis[ct] = d;
            if(s[0] == 'G' && s[1] == 'o'){evs[ct] = 'o'; break;}
            else if(s[0] == 'L')evs[ct] = 'l';
            else if(s[1] == 'a'){scanf("%s", s); evs[ct] = 'g';}
            else if(s[0] == 'F'){scanf("%s", s); scanf("%d", &fc); flc[ct] = fc; evs[ct] = 'f';}
            else evs[ct] = 'm';
        }

    double hi = 10000.0, lo = 0.0;
    double mid = 0.0, ans;
    ans = 0.0;
    
    //binary search ans and simulate

    while(fabs(hi - lo) > EPS){
        mid = (hi + lo) / 2.0;
        if(can(mid)){hi = mid; ans = mid;}
        else lo = mid;
    }

    printf("%.3lf\n", ans);

    // for(int a:)
   

    }




    
    
    //while fuel consumption
    //current fuel count untill gas station make fuel = 0 and tank = max tank , fuel
    //if goal break

   
    // int dis, fc = 0;
    // char s[50];
    
    // while(scanf("%d Fuel consumption %d", &dis, &fc), (dis || fc)){
         
    //     double fuel = 0.0, tank = 0.0;
    //     int leak, cur;
    //     cur = 0;
    //     leak = 0;
    //     while(1){
    //         scanf("%d", &cur);
    //         fuel += (fc/100.0) * (cur - dis); 
    //         fuel += leak * (cur - dis);
    //         dis = cur;
    //         tank = max(tank, fuel); 
    //         scanf("%s", s);
    //         if(s[0] == 'L') leak++;
    //         else if (s[0] == 'F'){scanf("%s", s); scanf("%d", &fc);}
    //         else if(s[0] == 'G' && s[1] == 'a'){scanf("%s", s); fuel = 0.0;}
    //         else if(s[1] == 'o') break;
    //         else leak = 0;
    //     }
    //     printf("%.03lf\n", tank);

    // }


    return 0;
}