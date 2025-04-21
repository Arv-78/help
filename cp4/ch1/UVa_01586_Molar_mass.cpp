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
    
    int elements[127], T;
    float molar_mass;
    char compound[85];
    scanf("%d", &T);

    while(T--){
        memset(elements, 0, sizeof elements);
        molar_mass = 0;
        scanf("%s", compound);

        // go from right
        for(int i = strlen(compound) - 1; i >= 0; i--){
            if(isdigit(compound[i])){
                // compound[i] is number
                int atoms = 0;
                int multiplier = 1;
                while(isdigit(compound[i])){
                    atoms += (compound[i] - '0') * multiplier;
                    multiplier *= 10;
                    i--;
                }

                elements[compound[i]] += atoms;
                
            } else {
                // compound[i] is char
                elements[compound[i]]++;
            }
        }

        molar_mass = (12.01 * elements['C']) + (1.008 * elements['H']) + (16.00 * elements['O']) + (14.01 * elements['N']);

        printf("%.3f\n", molar_mass);
    }
    
    return 0;
}