#include <bits/stdc++.h>
using namespace std;
#define print(A) for(auto c:A)cout<<c<<" ";cout<<endl;
typedef long long int lli;
int phi(int a){
	int b = a;
	for(int i = 2; i*i <= a; ++i)
		if(a % i == 0)
		{
			b = b/i*(i-1);
			do a/=i;
			while(a%i==0);
		}
	if(a > 1) b = b/a*(a-1);
	return b;
}

int main(){
    int k;
    cin>>k;
    vector<lli> vphi;
    vphi.push_back(0);
    vphi.push_back(0);
    vphi.push_back(0);
    int i = 3;
    while(vphi[vphi.size()-1]<=k){
        vphi.push_back(vphi[i-1]+phi(i)-1);
        i++;
    }
    
    int index = lower_bound(vphi.begin(),vphi.end(),k)-vphi.begin();
    int last = vphi[index-1],count= 0;
    i = 2;
    for(;i<index;i++){
        if(__gcd(i,index) ==1)count++;
        if(last+count== k)break;
    }
    cout<<i<<" "<<index<<endl;
    return 0;
}