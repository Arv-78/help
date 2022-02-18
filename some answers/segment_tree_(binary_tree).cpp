/*
	author : _arv
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF INFINITY;
#define pi 3.142;

int main() 
{
	/* code */
	
	//1.store values in segment tree array whose size is (2*n - 1)
		//i.if(node*2+2) < (2*n-1){tree[node] = tree[node*2 + 1] + tree[node*2 + 2];}
		// else{tree[node] = array[node];}
	//2.sum of range(a,b)
		//i.if(a%2 == 0){sum += tree[a++];}
		//ii.if(b%2 != 0){sum += tree[b--];}
	
	vector <int> array = {5, 8, 6, 3, 2, 7, 2, 6};
	auto it = array.end()-1;
	int n = array.size();
	
	/*segment tree of that supports sum queries.*/
	int tree[2*n - 1];

	for(int node=(2*n -1)-1; node>=0; node--) //n=8; n*2-1 = 15 - 1;(index starts from 0 and total nodes are 15 so, last node is 14);
	{
		if((node*2 + 2) < (2*n - 1)){

			tree[node] = tree[node*2 + 1] + tree[node*2 + 2];

		}else{
			tree[node] = *it;
			it--;
		}
	}
	//prints all values;
	for(int i = 0; i<2*n-1; i++)
	{
		cout<<tree[i]<<' ';
	}
	
	/**change value in the array**/
	//change(k, z); change k indexed value by z;
	//k = 6 + k; //6 is n-2
	
	int z = 3; int k = 6;
	k += 6;
	tree[k] += z;
	while(k >= 0)
	{
		if(k % 2 == 0){k = (k/2 -1);}
		else if(k % 2 == 1){k = k/2;}
		tree[k] += z;
	}

	//prints all values;
	cout<<'\n';
	for(int i = 0; i<2*n-1; i++)
	{
		cout<<tree[i]<<' ';
	}
	

	/**find sum of range(a,b) ->given(x,y);**/
	//39 22 17 13 9 9 8 5 8 6 3  2  7  2  6 
	//0  1  2  3  4 5 6 7 8 9 10 11 12 13 14
	//given 
	//int x = 4; int y = 6;
	// at each step, the range is moved one level higher in the tree, and before that, the values of the
	//nodes that do not belong to the higher range are added to the sum.
	int x = 3; int y = 8;
	
	int a = x + 6; // 0 to 6 values are higher values in tree
	int b = y + 6;

	int sum = 0;

	while(a <= b){
		if(a % 2 == 0){
			sum += tree[a];
			a++;
		}
		if(b % 2 == 1)
		{
			sum += tree[b];
			b--;	
		}
		a /= 2; 
		b = (b/2 - 1);
	}
	cout<<'\n'<<"sum = "<<sum;
	return 0;
}