#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,l,a,t,li;
    cin>>n>>l>>a;
    if(n==0)return cout<<0<<endl,0;
    vector<pair<int,int>>pairs(n);
    for(int i = 0;i<n;i++){
        cin>>t>>li;
        pairs[i]={t,li};
    }
    sort(pairs.begin(),pairs.end());
    int ans =0;
    for(int i = 0;i<n-1;i++){
        ans+= (pairs[i+1].first - (pairs[i].first + pairs[i].second))/a;
    }
    ans+= (l-(pairs[n-1].second+pairs[n-1].second))/a;
    cout<<ans<<endl;
    return 0;
}