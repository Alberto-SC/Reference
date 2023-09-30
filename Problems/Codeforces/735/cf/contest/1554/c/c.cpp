#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,m;
    while(t--){
        cin>>n>>m;
        if(m<n){
            cout<<0<<endl;
            continue;
        }
        vector<int> v(m+1);
        for(int i = 0;i<=m;i++)
            v[i] = n^i;
        int x = n^m;
        sort(v.begin(),v.end());
        int ans = m+1;
        for(int i = 0;i<=m;i++){
            if(v[i]!=i){
                ans = i;
                break;
            }
        }
        bitset<32> a(n);
        bitset<32> b(m);
        int ans2 = 0,x = 0,z = 0;
        for(int i = 31;>=0;i--){
            int y = 1<<i;
            y--;
            if((n>>i)&1){
                x|=(1<<i);
                z|=(1<<i);
            }
            else{

            }
            else 
                x|=(1<<i)
        }
        bitset<32> c(x);
        bitset<32> d(ans);
        bitset<32> e(n-(n&m));
        bitset<32> f(n^ans);
        cout<<a<<endl<<b<<endl<<c<<endl<<d<<endl<<e<<endl<<f<<endl;
        cout<<ans<<" "<<x<<endl;
    }
    return 0;
}  
