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
    
    // count points
    //if points < 14 PASS
    //if points >= 14 check for points 1. points >= 16 NO-TRUMP check before adding and suits shuld be stopped
    //                                 2. if no NO-TRUMP then BID SUIT (suit with most cards S H D C)
    //KS QS TH 8H 4H AC QC TC 5C KD QD JD 8D 
    //AC 3C 4C AS 7S 4S AD TD 7D 5D AH 7H 5H 4 4 4 4
    //8D QC 4C QD KS 3C 6H 6D KD 2H AS 4H 2D D(5) C(3) H(3) S(2)
    // conditions for suits stopped Ace or king and 1card or queen and 2cards.
    string crds;
   while(getline(cin, crds)){
    stringstream s;
    s.clear();
    s<<crds;
    //if(!flagg) break;
        string crd;
        int ct = 13;
        int pt = 0;
        int KS, KH, KD, KC, QS, QH, QD, QC, AS, AH, AD, AC, JS, JH, JD, JC;
        KS = KH = KD = KC = QS = QH = QD = QC = AS = AH = AD = AC = JS = JH = JD = JC = 0;
        int S, H, D, C;
        S = H = D = C = 0;
        int stopped[4] = {0};
    
        while(ct--){
            s>>crd;
            //  cout<<crd<<'\n';
            //counting
            if(crd[0] == 'A'){
                pt += 4;
                
                if(crd[1] == 'S') AS = 1;
                if(crd[1] == 'H') AH = 1;
                if(crd[1] == 'D') AD = 1;
                if(crd[1] == 'C') AC = 1;
            } else if(crd[0] == 'K'){
                pt += 3;

                if(crd[1] == 'S') KS = 1;
                if(crd[1] == 'H') KH = 1;
                if(crd[1] == 'D') KD = 1;
                if(crd[1] == 'C') KC = 1;
            } else if(crd[0] == 'Q'){
                pt += 2;

                if(crd[1] == 'S') QS = 1;
                if(crd[1] == 'H') QH = 1;
                if(crd[1] == 'D') QD = 1;
                if(crd[1] == 'C') QC = 1;
            } else if(crd[0] == 'J'){
                pt += 1;

                if(crd[1] == 'S') JS = 1;
                if(crd[1] == 'H') JH = 1;
                if(crd[1] == 'D') JD = 1;
                if(crd[1] == 'C') JC = 1;
            }

            //total cards
            if(crd[1] == 'S') S++;
            if(crd[1] == 'H') H++;
            if(crd[1] == 'D') D++;
            if(crd[1] == 'C') C++;

        }
        //1. K# == 1 and # = 1;

        if(KS == 1 && S == 1)pt--;
        if(KH == 1 && H == 1)pt--;
        if(KD == 1 && D == 1)pt--;
        if(KC == 1 && C == 1)pt--;

        // 2. Q# == 1 && # == 0 || 1

        if(QS == 1 && S <= 2)pt--;
        if(QH == 1 && H <= 2)pt--;
        if(QD == 1 && D <= 2)pt--;
        if(QC == 1 && C <= 2)pt--;

        //3. J# == 1 && # <= 3
        if(JS == 1 && S <= 3)pt--;
        if(JH == 1 && H <= 3)pt--;
        if(JD == 1 && D <= 3)pt--;
        if(JC == 1 && C <= 3)pt--;

        //check for suits stop
        int flag = 1;
        if(AS == 1) stopped[0] = 1;
            else{
                if(KS == 1 && S >= 2) stopped[0] = 1;
                if(QS == 1 && S >= 3) stopped[0] = 1;
            }
            if(AH == 1) stopped[1] = 1;
            else{
                if(KH == 1 && H >= 2) stopped[1] = 1;
                if(QH == 1 && H >= 3) stopped[1] = 1;
            }
            if(AD == 1) stopped[2] = 1;
            else{
                if(KD == 1 && D >= 2) stopped[2] = 1;
                if(QD == 1 && D >= 3) stopped[2] = 1;
            }
            if(AC == 1) stopped[3] = 1;
            else{
                if(KC == 1 && C >= 2) stopped[3] = 1;
                if(QC == 1 && C >= 3) stopped[3] = 1;
            }

            
            for(int i = 0; i < 4; i++){
                if(stopped[i] != 1){flag = 0;break;}
            }
        
        if(pt >= 16 && flag){
            if(flag)cout<<"BID NO-TRUMP\n";
        } else {
            // 4. # == 2
            if(S == 2)pt++;
            if(H == 2)pt++;
            if(D == 2)pt++;
            if(C == 2)pt++;

            // 5. # <= 1
            if(S <= 1)pt += 2;
            if(H <= 1)pt += 2;
            if(D <= 1)pt += 2;
            if(C <= 1)pt += 2;
            
            //check for pass
            if(pt < 14)cout<<"PASS\n";
            if(pt >= 14){
                if(S >= H && S >= D && S >= C)
                cout<<"BID S\n";
                else if(H >= S && H >= D && H >= C)
                cout<<"BID H\n";
                else if(D >= S && D >= H && D >= C)
                cout<<"BID D\n";
                else cout<<"BID C\n";
            }
        }
           
        
    }
    
    return 0;
}