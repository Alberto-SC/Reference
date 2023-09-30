#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int solve(vector<int> a,vector<int> b){
    int n = a.size(),m = b.size();
    vector<int> good(n);
    int l = m-1;
    for(int i = n;i>=0;i--){
        int idx = lower_bound(b.begin(),b.end(),a[i])-b.begin();
        if(b[idx]==a[i])good[i] = 1;
    }
    for(int i = 0;i<a.size();i++)
        if(i)good[i] = good[i]+good[i-1];

    int ansr = 0;
    for(int j = 0;j<n;j++){
        int g = good[n-1]-good[j];
        int x = j+1;
        int f = lower_bound(b.begin(),b.end(),g+good[j])-b.begin();
        int idx = lower_bound(b.begin(),b.end(),a[j])-b.begin();
        ansr = max(ansr,g+min((m-f)-idx,x)  );
    }   
    return ansr;
}
signed main(){__
	int t= 1,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<int> an,ap;
        vector<int> bn,bp;
        for(int i = 0;i<n;i++){
            int x;
            cin>>x;
            if(x<0)an.push_back(-x);
            else ap.push_back(x);
        }
        for(int i = 0;i<m;i++){
            int x;
            cin>>x;
            if(x<0)bn.push_back(-x);
            else bp.push_back(x);
        }
        int ans = 0;
        ans+=solve(ap,bp);
        ans+=solve(an,bn);
        cout<<ans<<endl;
    }
    return 0;
}  
