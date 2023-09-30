#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,a,b;
    cin>>t;
    while(t--){
        cin>>a>>b;  
        n = a+b;
        int x = (a+b)/2,y = n-x;
        int mn =n-(min(a,x)+min(b,y));
        int mx = min(a,y)+min(b,x);
        set<int> ans;
        for(int i = mn;i<=mx;i+=2)
            ans.insert(i);
        swap(x,y);
        mn = n-(min(a,x)+min(b,y));
        mx = min(a,y)+min(b,x);
        for(int i = mn;i<=mx;i+=2)
            ans.insert(i);
        cout<<ans.size()<<endl;
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
} 



