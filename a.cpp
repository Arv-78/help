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
   //1.scan 2.check values for each combination 3.get greatest value
   int a, b, c, d, e;
   int val[6];
   bool crds[52];
   while(scanf("%d %d %d %d %d", &a, &b, &c, &d, &e), (a || b || c || d || e)){
    //combinitions ab-de ba-de bc-de cb-de ac-de ca-de
    memset(val, 0, sizeof(val));
    memset(crds, false, sizeof(crds));
    crds[a - 1] = crds[b - 1] = crds[c - 1] = crds[d - 1] = crds[e - 1] = true;
    
    if(a > d && b > e)val[0] = -1;
    else if((a > d && b < e) || (a < d && b > e)) val[0] = c + 1;
    else if(a < d && b < e)val[0] = 1;

    if(b > d && a > e)val[1] = -1;
    else if((b > d && a < e) || (b < d && a > e)) val[1] = c + 1;
    else if(b < d && a < e)val[1] = 1;

    if(b > d && c > e)val[2] = -1;
    else if((b > d && c < e) || (b < d && c > e)) val[2] = a + 1;
    else if(b < d && c < e)val[2] = 1;

    if(c > d && b > e)val[3] = -1;
    else if((c > d && b < e) || (c < d && b > e)) val[3] = a + 1;
    else if(c < d && b < e)val[3] = 1;

    if(a > d && c > e)val[4] = -1;
    else if((a > d && c < e) || (a < d && c > e)) val[4] = b + 1;
    else if(a < d && c < e)val[4] = 1;

    if(c > d && a > e)val[5] = -1;
    else if((c > d && a < e) || (c < d && a > e)) val[5] = b + 1;
    else if(c < d && a < e)val[5] = 1;

    sort(val, val+6);
    if(val[0] == -1){
        cout<<-1<<'\n';
    }else{
        if(!crds[val[5] - 1]){
            cout<<val[5]<<'\n';
        }else{
            int t = val[5] - 1;
            while(crds[t]){
                t++;
            }
            if(t + 1 <= 52)
            cout<<t+1<<'\n';
            else 
            cout<<-1<<'\n';
        }
    }


   }

    
    return 0;
}