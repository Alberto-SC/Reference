#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int sz = 7;
struct segments{
    int l,r,c;
};

signed main(){
	int t= 1,n,m,k,l,r,c;
    cin>>t;
    while(t--){
        vector<pair<int,bitset<sz>>> all_;
        cin>>n>>m>>k;
        vector<int> g(n);
        for(auto &c:g)cin>>c;
        vector<segments> sm(m);
        for(int i = 0;i<m;i++){
            cin>>l>>r>>c;
            l--,r--;
            sm[i] ={l,r,c};
        }
        int ans = -1e15;
        for(int mask = 0;mask <(1<<n);mask++){
            int s = 0;
            for(int i = 0;i<n;i++)
                if((mask>>i)&1)s+=g[i];
            
            for(int i = 0;i<m;i++){
                int x = 1;
                for(int j = sm[i].l;j<=sm[i].r;j++)
                    x*=((mask>>j)&1);
                if(x)s+=sm[i].c;
            }
            bitset<sz> bs(mask);
            // cout<<bs<<" -> "<<s<<endl;
            all_.push_back({s,bs});
            // ans = max(ans,s);
        }
        sort(all_.begin(),all_.end(),[&](pair<int,bitset<sz>>a ,pair<int,bitset<sz>>b){
            return a.first>b.first;
        });
        // cout<<"Bruta"<<endl;
        for(int i = 0;i<k;i++)
            cout<<all_[i].first<<" ";
        cout<<endl;
         
    }
    return 0;
}  
