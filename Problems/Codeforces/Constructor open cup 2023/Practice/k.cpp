#include <bits/stdc++.h>
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'
#define int long long 
using namespace std;

const int maxn = 200007;

vector<int> p(maxn);
vector<int> sz(maxn,1);

int root(int u){
    return (p[u] == u ? u : p[u] = root(p[u]));
}

void union_by_size(int u,int v){
    u = root(u);
    v = root(v);
    if(u == v)return;
    if(sz[u]<sz[v])swap(u,v);
    sz[u]+=sz[v];
    p[v] = u;
}

signed main(){__
    int T = 1,n;
    while(T--){
        cin>>n;

        iota(p.begin(),p.end(),0);

        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
      
        multiset<pair<int,int>> st;
        
        for(int i = 0;i<n;i++){
            st.insert({nums[i],i});
        }


        map<int,vector<vector<int>>> mp;
        if(nums.size()==1){
            cout<<nums[0]<<endl;
            cout<<1<<" "<<nums[0]<<endl;
            cout<<0<<endl;
            return 0;
        }
        while(st.size()>=2){
            auto mx1 = *st.rbegin();
            st.erase(st.find(mx1));
            auto mx2 = *st.rbegin();
            st.erase(st.find(mx2));
            
            st.insert({mx1.first-mx2.first,-1});
            /* cout<<mx1.first<<" "<<mx2.first<<" "<<mx1.second<<" "<<mx2.second<<endl; */
            if(mx1.second == -1 && mx2.second == -1){
                auto one = mp[mx1.first].back();
                mp[mx1.first].pop_back();
                auto two = mp[mx2.first].back();
                mp[mx2.first].pop_back();
                int u = one[2];
                int v = two[3];

                union_by_size(u,v);
                
                u = one[3];
                v = two[2];
                union_by_size(u,v);

                int nwM1 = one[0]+two[1];
                int nwM2 = one[1]+two[0];
                if(nwM1<nwM2){
                    swap(nwM1,nwM2);
                    swap(one[2],one[3]);
                }
                mp[mx1.first-mx2.first].push_back({nwM1 , nwM2 , one[2] , one[3]});
            
            }
                
            else if(mx1.second == -1){
                auto one = mp[mx1.first].back();

                mp[mx1.first].pop_back();
                
                union_by_size(mx2.second,one[3]);
                
                one[1]+=mx2.first;
                if(one[1]>one[0]){
                    swap(one[0],one[1]);
                    swap(one[2],one[3]);
                }
                mp[mx1.first-mx2.first].push_back(one);

            }
            else if(mx2.second == -1){
                auto one = mp[mx2.first].back();

                mp[mx2.first].pop_back();
                
                union_by_size(mx1.second,one[3]);
                
                one[1]+=mx1.first;
                if(one[1]>one[0]){
                    swap(one[0],one[1]);
                    swap(one[2],one[3]);
                }

                mp[mx1.first-mx2.first].push_back(one);

            }
            else{
                mp[mx1.first-mx2.first].push_back({mx1.first,mx2.first,mx1.second,mx2.second});

            } 
        }

        int ans = st.begin()->first;
        cout<<ans<<endl;
        
        vector<int> a;
        vector<int> b;
        int first = root(mp[ans][0][2]);
        
        int sa = 0,sb = 0;
        for(int i = 0;i<n;i++){
            if(root(i)== first)a.push_back(nums[i]),sa+=nums[i];
            else b.push_back(nums[i]),sb+=nums[i];
        }

        assert(abs(sa-sb)==ans);
        cout<<a.size()<<" ";
        for(auto c:a)cout<<c<<" ";
        cout<<endl;
        cout<<b.size()<<" ";
        for(auto c:b)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}
