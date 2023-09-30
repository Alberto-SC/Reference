#include <bits/stdc++.h>
using namespace std;
int main(){
    long long k,n,ans = -10000000000,f,t;
    cin>>n>>k;
    vector<pair<int,int>> aa;
    for(int i = 0;i<n;i++){
        cin>>f>>t;
        aa.push_back({f,t});
    }
    for(int i = 0;i<n;i++){
        ans = max(ans, (aa[i].first)- (  (aa[i].second-k)  * ((aa[i].second-k)>=0)   ) ) ;
    }
    cout<<ans;

    return 0;
}