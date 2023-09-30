#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
lli gauss(lli n){
    return (n*(n+1))/2;
}
int main(){__
    lli t = 1,n;
    cin>>t;
    vector<lli> poss;
    vector<lli> h;
    poss.push_back(1);
    h.push_back(gauss(poss.back()));
    for(lli i = 0;i<30;i++){
        poss.push_back((poss.back()*2)+1);
        h.push_back(gauss(poss.back()));
    }
    vector<lli> ac;
    ac.push_back(h[0]);
    for(lli i = 1;i<30;i++){
        ac.push_back(ac.back()+h[i]);
    }
    while(t--){
        cin>>n;
        auto idx = lower_bound(ac.begin(),ac.end(),n);
        if(idx == ac.end())cout<<30<<endl;
        else if(*idx == n)cout<<(idx-ac.begin())+1<<endl;
        else if(*idx>n)cout<<(idx-ac.begin())<<endl;
    }
    return 0;
}

