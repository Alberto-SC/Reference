#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    while(t--){
        string s,t;
        cin>>s>>t;
        vector<set<int>> v(26);
        vector<set<int>> x(26);
        vector<int> nums(n);
        vector<int> pos(t.size());
        for(auto &c:nums)cin>>c,c--;
        int n = s.size();
        int idx = 0;
        for(int i= 0;i<n;i++){
            if(idx<t.size() && s[i]== t[idx]){
                pos[idx] =i;    
                idx++;
            }
        }
        for(int i  =0 ;i<n;i++){
            v[s[i]-'a'].insert(i);
        }
        int cont = 0;
        for(int i = 0;i<n;i++){
            v[s[nums[i]]].erase(nums[i]);
            int idx = lower_bound(pos.begin(),pos.end(),nums[i]);
            if(pos[idx]==nums[i]){
                if(v[s[nums[i]]-'a'].size()==0)
                    break;
                int change = *v[s[nums[i]]-'a'].begin();
                pos[idx] = change;
                idx++;
                int last = change;
                while(idx<t.size()){
                    if(pos[idx]>last)break;
                    else {
                        v[s[]]
                    }
                }   
                pos[i] = change;
            }
            cont++;    
        }
        cout<<cont<<endl;
    }
    return 0;
}  
