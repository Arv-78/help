/*
	author : _arv
*/

#include<bits/stdc++.h>
#define INF INT16_MAX;

using namespace std;

char one[] = {'M','O','V','I','E'};
char two[] = {'L','O','V','E'};

int cost(int x, int y)
	{
		//cout<<one[x-1]<<' '<<two[y-1]<<'\n';
		if(two[x] != one[y])
		{
			return 1;
		}
		else{
			return 0;
		}
	}


int main()
{
	//MOVIE -> 5
	//LOVE	-> 4
	//distance[x][y] = min(distance[x-1][y]+1, distance[x][y-1]+1, distance[x-1][y-1]+cost[x][y]);
	//if one[x] = two[y] then cost[x][y] = 1;
	
	int distance[7][6];
	distance[0][0] = 0;



	for(int x=0; x<=4; x++)
	{
		for(int y=0; y<=5; y++)
		{
			if(y != 0 && (x-1)<0)
			{
				distance[x][y] = y;  //column
			}
			else if(x != 0 && (y-1)<0)
			{
				distance[x][y] = x; //row
			}
			else if(x != 0 && y != 0){  // for first x=0, y=0
			    distance[x][y] = min(distance[x-1][y] + 1, min(distance[x][y-1]+ 1, distance[x-1][y-1]+cost(x-1, y-1)));
			}
			std::cout<<distance[x][y]<<' ';
		}
		std::cout<<'\n';
	}

	std::cout<<distance[4][5]; 

	return 0;	
}