#include <iostream>
#include <conio.h>

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	string s;
	getline(cin, s);
	cout<<s;
	
	return 0;
}