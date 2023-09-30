#include <iostream>
#include <vector>
#include <cmath>
#include<bits/stdc++.h>
using namespace std;
typedef long long lld;
typedef long double ldb;

/*int main(){
	unsigned long long t,n,p,res,cont,sum;
	long  double mid,l,r;
	cin>>t;
	for(int i  = 0;i<t;i++){
		cin>>n>>p;
		sum = (n*(n+1))/2;
		if(sum > p){
			cout<<"0"<<endl;
		}
		cout<<"  S: "<<sum;
		else{	
		long long b = p/sum;
		long long rem = 
		res = -1;
		l = b,r = b+1;
		cont=0;
		while(cont<30){
			cont ++;
			mid = (l+r)/2;
			long long sumr = 0;
			for(int j = 1;j<=n;j++)
				sumr += j*mid;
			//cout<<" "<<sumr<<endl;
			if(sumr > p)
				r = mid;
			else{	
				if(sumr == p)
				res = mid;
				l = mid;
			}
		}
		cout<<res<<endl;
		}
	}

	return 0;

}*/


int main() {
    lld t,n,p;
    cin>>t;
    while(t--) {
        cin>>n>>p;
        lld tmp = (n*(n+1))/2;
        lld ans = p/tmp;
        lld rem = p - tmp * ans;
        //cout<<"rem "<<rem<<endl;
        ldb low = 0, high = 1, mid1, mid2;
        while(high-low>1e-10) {
            mid1 = (low+high)/2;
            lld tot=0;
            for(int i=1;i<=n;i++) tot += (lld)(i*mid1);
            if(tot >= rem) high = mid1;
            else low = mid1;
        }
        low = 0, high = 1;
        while(high-low>1e-10) {
            mid2 = (low+high)/2;
            lld tot=0;
            for(int i=1;i<=n;i++) tot += (lld)(i*mid2);
            if(tot > rem) high = mid2;
            else low = mid2;
        }
        ldb mid = (mid1+mid2)/2, tot = 0;
        for(int i=1;i<=n;i++) tot += (lld)(i*mid);
        cout<<(tot == rem ? ans : -1)<<endl;
    }
}

