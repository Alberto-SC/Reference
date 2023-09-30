#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int get(int a,int b){
    int x = (a*(a+1))/2;
    int y = (b*(b-1))/2;
    return x-y;
}
const int maxn = 200007;
vector<int> mp(maxn);
set<int> v;
int getRange(int s,int e,int n){
    int y  = ((s+1)*(n-e));
    int l=(s-e)+1;
    int x = 0;
    if(l>1){
        x = get(n,n-(l-2));
    }
    return x+y;
}

signed main(){__
    int T = 1,n,q,id,x;
    while(T--){
        cin>>n>>q;
        vector<int> nums(n);
        nums.resize(n);
        for(auto &c:nums)cin>>c;
        for(int i = 0;i<n;){
            int j = i;
            while(j<n &&nums[i]==nums[j])j++;
            v.insert({i});
            mp[i] = j-1;
            i = j;
        }
        nums.push_back(-1);

        int ans = 0;
        for(auto c:v){
            ans+=getRange(c,mp[c],n);
        }
        cout<<ans<<endl;
        int N = v.size();
        while(q--){
            cin>>id>>x; 
            id--;
            auto X = v.lower_bound(id);
            if(*X!=id)X--;
            int s = *X;

            if(nums[s]==x)continue;
            nums[id] = x;
            ans-=get(s,mp[s]);

            if(id+1 && nums[id]==nums[id+1]){
                X++;
                int nxt = *X;
                mp[s] = mp[nxt];
                ans+=get(s,mp[s]);
                v.erase(nxt);    
            }
            else if(id+1<n && id && nums[id-1]== nums[id] && nums[id] == nums[id+1]){
                X++; 
                int nxt = *X;
                X--,X--;
                int prev = *X;
                ans-=get(nxt,mp[nxt]);
                ans-=get(id,id);                
                v.erase(id);
                v.erase(nxt);
                mp[prev] = mp[nxt];
                ans+=get(prev,mp[prev]);
            }
            else if(id && nums[id-1]==nums[id]){
                X--;
                int prev = *X;
                mp[prev] = id;
                ans-=get(id,id);
                ans+=get(prev,id);
                v.erase(id);
            }
            else if(mp[s]!=s){
                if(id== s){
                    v.insert(id+1);
                    mp[id+1] = mp[s];
                    mp[s] = id;
                    ans+=get(s,mp[s]);
                    ans+=get(id+1,mp[id+1]);
                }
                if(mp[s]==id){
                    v.insert(id);
                    mp[id] = id;
                    mp[s] = id-1;
                    ans+=get(s,mp[s]);
                    ans+=get(id,id);
                }
                else{
                    v.insert(id);
                    v.insert(id+1);
                    mp[id] = id;
                    mp[id+1] = mp[s];
                    mp[s] = id-1;
                    ans+=get(s,mp[s]);
                    ans+=get(id,id);
                    ans+=get(id+1,mp[id+1]);
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}