#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	lli t= 1,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<lli> a(m);
        vector<lli> b(m);
        for(lli i = 0;i<m;i++){
            cin>>a[i]>>b[i];
        }
        set<pair<lli,lli>> st;
        for(int i = 0;i<m;i++){
            st.insert({-a[i],i});
        }
        lli sum = 0;
        while(1){
            auto mx = *st.begin();
            cout<<mx.first<<endl;
            if(mx.second==-1){
                sum+= n*-mx.first;
                break;
            }
            else{
                n--;
                sum+=-mx.first;
                st.insert({b[mx.second],-1});
                st.erase(st.begin());
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}  

