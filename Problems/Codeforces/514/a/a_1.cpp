#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,l,a,ti,li;
    cin>>n>>l>>a;
    if(n==0)return cout<<l/a<<endl,0;
    vector<int> t(n),la(n);
    for(int i = 0;i<n;i++){
        cin>>ti>>li;
        t[i]=ti;
        la[i]=li;
    }
    int ans =0;
    t.push_back(l);
    la.push_back(0);
    int start = 0;
    for(int i = 0;i<=n;i++){
        ans+= (t[i]-start)/a;
        start = t[i]+la[i];
    }
    cout<<ans<<endl;
    return 0;
}