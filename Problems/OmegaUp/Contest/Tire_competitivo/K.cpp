#include <iostream>
#include <cmath>
#include <stdlib.h>
using namespace std;
long long p = pow(2,32);
long long DP[2602][2602];

long long s(int x,int  a){
	if(x == 0 || x == 1)return floor((a*a)/2);
	if(a == 0 || a == 1)return floor((2*x)/3);
	if(DP[x][a] != -1) return DP[x][a];
	DP[x][a] = s(x+1,a-2) + s(x-2,a+1);
	return DP[x][a]%p;
} 

int main(){
	int x,a;
	cin>>x>>a;
	for(int i = 0;i<=2*x;i++){
		for(int j = 0;j<=2*a;j++)
			DP[i][j] = -1;
	}
	long long r= s(x,a);
	cout<<r;
}
