#include <iostream>
#include <cmath>
using namespace std;

int main(){

	int k,max=0,k1;
	unsigned long long int r;
	cin>>k;
	for(int i = 0;i<k;i++){
		cin>>k1;
		if(k1>=max) max = k1;
	}
	if(max == 0)cout<<0;
	else{
		r = pow(max,max);
		cout<<r;
	}


}