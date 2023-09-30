#include <iostream>
#include <stdlib.h>
using namespace std;
long long int mod(long long int x, long long int y,long long m){
	long long int ans =1,temp = x;
	while(y){
		if( y & 1 ){
			ans *= temp;
			ans %= m;
		}
		y>>=1;
		temp*= temp;
		temp%= m;
	}
	return ans;
}
int main(){
	int x,y,m;
	while(cin>>x>>y>>m){
		cout<<mod(x,y,m)<<endl;
		getchar();
	}
}