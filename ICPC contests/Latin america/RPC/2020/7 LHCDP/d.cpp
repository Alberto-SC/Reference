#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){
	ll N, t,s;
	cin>>N;
	for(int i=0; i<N; i++){
		cin>>t>>s;
		ll act,res=0,sig;
		cin>>act;
		for(int j=0; j<s-1; j++){
			cin>>sig;
			ll back= (sig-act)-1;
			if(back<0) back+=t;
			ll front= t-back;
			act=sig;
			res+=min(back,front);
		}
		cout<<res<<"\n";
	}
	return 0;
}