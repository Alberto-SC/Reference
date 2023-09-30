#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	lli t= 1,n,a,b,k;
    cin>>t;
    while(t--){
        cin>>a>>b>>k;
        map<lli,lli> qa;
        map<lli,lli> qb;
        vector<lli> as(k);
        vector<lli> bs(k);
        for(lli i = 0;i<k;i++){
            cin>>as[i];
            qa[as[i]]++;
        }
        for(lli i = 0;i<k;i++){
            cin>>bs[i];
            qb[bs[i]]++;
        }
        lli total = (k*(k-1))/2;
        for(auto c:qa){
            total-= (c.second*(c.second-1))/2;
        }
        for(auto c:qb){
            total-= (c.second*(c.second-1))/2;
        }
        cout<<total<<endl;
    }
    return 0;
}  

