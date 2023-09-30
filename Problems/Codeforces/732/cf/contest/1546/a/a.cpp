#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> a(n);
        vector<int> b(n);
        for(auto &c:a)cin>>c;
        for(auto &c:b)cin>>c;
        vector<pair<int,int>> neg;
        vector<pair<int,int>> pos;
        for(int i = 0;i<n;i++){
            if(a[i]!=b[i]){
                if(a[i]-b[i]>0)pos.push_back({a[i]-b[i],i});
                else neg.push_back({a[i]-b[i],i});
            }
                
        }
        sort(neg.begin(),neg.end());
        sort(pos.rbegin(),pos.rend());
        int l= 0,r = 0;
        vector<pair<int,int>> ans;
        while(l<neg.size() && r<pos.size()){
            ans.push_back({pos[r].second,neg[l].second});
            neg[l].first++;
            pos[r].first--;
            if(!neg[l].first)l++;
            if(!pos[r].first)r++;
        }    
        if(l == neg.size() && r == pos.size()  && ans.size()<=100){
            cout<<ans.size()<<endl;
            for(auto c:ans)cout<<c.first+1<<" "<<c.second+1<<endl;
        }
        else cout<<-1<<endl;
        
    }
    return 0;
}  
