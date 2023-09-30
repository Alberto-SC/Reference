#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	long long int S,res;
	cin>>t;
	for(int i=0; i<t; i++){
		cin>>S;
		res= (S+1)*(S+1);
		res--;
		cout<<res<<"\n";
	}
	return 0;
}