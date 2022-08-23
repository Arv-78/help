//uva 10114 loansome car buyer
#include <bits/stdc++.h>
using namespace std;

int main(){

	int months, nrec;
	float dPay, loan, drate[101];

	while(1){
		scanf("%d %f %f %d", &months, &dPay, &loan, &nrec);
		if(months < 0){
			break;
		}
		int n;
		float rate;
		while(nrec--){
			scanf("%d %f", &n, &rate);
			for(int i = n; i<101; i++){
				drate[i] = rate;
			}
		}
		int now = 0;
		float deploan = (loan + dPay) * (1 - drate[0]);
		float payment = loan;
		while(deploan < payment){
			now++;
			deploan = deploan * (1 - drate[now]);
			payment -= loan/months;
		}

		cout<<now<<(now != 1 ? " months\n" : " month\n");
		

	}

}