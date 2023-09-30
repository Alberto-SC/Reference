#include <iostream>
#include <math.h>
using namespace std;

int main(){
	int n,lk = 0,rk,lx,rx,midk,midx;
	bool y = false;
	long long res;
	cin>>n;
	n = 2*n;
	for(int i = 1;i<sqrt(n);i++){
		lx = 1;
		rx = sqrt(n);
		while(lx<=rx){
			midx = (lx+rx)/2;
			res  = (i*i)+i+(midx*midx)+midx;
			//cout<<i<<" "<<res<<" "<<midx<<endl;
			if(res < n)
				lx = midx+1;
			else if(res> n)
				rx = midx-1;
			else if(res ==n){
				y = true;
				break;
			}
		}
		if(y)break;
	}
	if(y) cout<<"YES";
	else cout<<"NO";

}