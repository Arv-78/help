#include <iostream>
#include <conio.h>

using namespace std;
class A{
	public:
	void fun (int a){
		cout<<"time"<<a;
	}
};

int main(){
	
	A a, *d;
	d = &a;
	d->fun(5);
	
	return 0;
}