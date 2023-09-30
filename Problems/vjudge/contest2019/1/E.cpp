#include <bits/stdc++.h>
using namespace std;
vector <int> num;
int ans  = 0;
void solve(int i,int s,int n){
	if(i>=n){
		if(s%360==0||s==0)ans=1;
		return;
	}
	solve(i+1,s+num[i],n);
	solve(i+1,s-num[i],n);
}
int main(){
    int n,a;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>a;
        num.push_back(a);
    }
    solve(0,0,n);
    if(ans)cout<<"YES";
    else cout<<"NO";
}