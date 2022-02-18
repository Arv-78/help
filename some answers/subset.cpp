/*
	author : arv
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF INFINITY;
#define pi 3.142;

int n = 10;
vector <char> c{'A','B','C','D','E','F','G','H','I','J'};

int main() 
{
	/* code */

	for(int i=0; i<(1<<10); i++){
        for(int j=0; j<10; j++){
            if(i & (1<<j)){
                cout<<c[j]<<' ';
            }
        }
        cout<<'\n';
    }

	return 0; 
}