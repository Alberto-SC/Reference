#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<lli> k(n);
        for(auto &c:k)cin>>c;
        vector<lli> c(m);
        for(auto &d:c)cin>>d;
        vector<lli> ans(n,-1);
        sort(k.begin(),k.end());
        int l = 0,r = n-1;
        for(int i = 0;i<m;i++){
            while(k[l]-1  == i && ans[i]== -1){
                ans[l] = c[i];
                l++;
            }
            if(k[r]-1>=i && ans[r] == -1){
                ans[r] = c[i];
                r--;
            }
        }
        for(int i = 0;i<n;i++)
            if(ans[i]== -1)ans[i] = c[k[i]-1];
        lli sum = accumulate(ans.begin(),ans.end(),0ll);
        cout<<sum<<endl;
    }
    return 0;
}  

