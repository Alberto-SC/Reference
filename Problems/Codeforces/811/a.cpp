#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,H,M,h,m;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>H>>M;
        pair<int,int> ans = {24,60};
        for(int i = 0;i<n;i++){
            cin>>h>>m;
            int a = 0,b = 0;
            if(m<M){
                H++;
                a = ((h-H)+24)%24;
                b = ((m-M)+60)%60;
                H--;
            }
            else {
                a = ((h-H)+24)%24;
                b = ((m-M)+60)%60;
            }
            if(make_pair(a,b)<ans){
                ans = {a,b};
            }
        }
        cout<<ans.first<<" "<<ans.second<<endl;
    }
    return 0;
}  
