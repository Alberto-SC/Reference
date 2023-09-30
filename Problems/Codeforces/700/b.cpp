#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	lli t= 1,n,A,B;
    cin>>t;
    while(t--){
        cin>>A>>B>>n;
        vector<lli> a(n);
        vector<lli> h(n);
        for(auto &c:a)cin>>c;
        for(auto &c:h)cin>>c;
        lli total = 0;
        vector<pair<lli,lli>> x(n);
        for(lli i = 0;i<n;i++){
            x[i] = {a[i],h[i]};
        }
        sort(x.begin(),x.end());
        bool flag = true;
        for(lli i = 0;i<n;i++){
            lli need = x[i].second/A;
            if(x[i].second%A)need++;
            if(B<=x[i].first*(need-1)){
                flag = false;
                break;
            }
            B-= x[i].first* need;
            if(B<=0 && i<n-1)flag = false;
 
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
} 