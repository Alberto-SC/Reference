#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	lli t= 1,n,p,k,x,y;
    cin>>t;
    while(t--){
        string s;
        cin>>n>>p>>k;
        cin>>s;
        cin>>x>>y;
        lli ans = (x*n)+(y*n);
        vector<lli> f(n);
        for(int i = 0;i<n;i++)
            if(s[i]== '0')
                f[i] = 1;
        for(int i = n-1;i>=0;i--)
            if(i+k<n)f[i]+=f[i+k];
        for(lli i = p-1;i<n;i++)
            ans = min(ans,((i-(p-1))*y)+(f[i]*x));
        cout<<ans<<endl;
    }
    return 0;
}  

