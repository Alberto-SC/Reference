#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,m,k;
    cin>>t;
    while(t--){
        cin>>k>>n>>m;
        vector<int> a(n);
        for(auto &c:a)cin>>c;
        vector<int> b(m);
        for(auto &c:b)cin>>c;
        int l= 0,r= 0;
        bool flag = true;
        vector<int> ans;
        while(l<n || r<m){
            if(l<n && a[l]== 0)ans.push_back(a[l++]),k++;
            else if(r<m && b[r]== 0)ans.push_back(b[r++]),k++;
            else if(l<n && a[l]<=k)ans.push_back(a[l++]);
            else if(r<m && b[r]<=k)ans.push_back(b[r++]);
            else {
                flag = false;
                break;
            }
        }
        if(flag){
            for(auto c:ans)cout<<c<<" ";
            cout<<endl;
        }
        else cout<<-1<<endl;
    }
    return 0;
}  
