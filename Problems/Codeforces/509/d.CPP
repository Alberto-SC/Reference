#include <bits/stdc++.h>
using namespace std;
#define printp(A)for(auto c:A)cout<<c.first<<" "c.second<<endl;
#define all(A)A.begin(),A.end()
typedef long long int lli;
const int maxn = (1000*1000*1000)+7;
int main(){
    ios_base:sync_with_stdio(0);
    lli n,h,a,b;
    cin>>n>>h;
    vector<pair<lli,lli>> segments(n);
    for(int i = 0;i<n;i++){
        cin>>a>>b;
        segments[i] = {a,b};
    }
    sort(all(segments));   
    segments.push_back({maxn,maxn});
    lli ans = 0; 
    for(int i = 0;i<n;i++){
        lli aux = h;
        lli j = i,how = 0;
        while(aux){
            how+=segments[j].second-segments[j].first;
            aux-=min(aux,segments[j+1].first-segments[j].second);
            how+=min(aux,segments[j+1].first-segments[j].second);
        }
        ans = max(ans,how);
    }
    return 0;
}