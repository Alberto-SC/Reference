#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 100007;
vector<int> bit(maxn);

void add(int idx,int val){
  for(++idx;idx<maxn;idx+=idx&-idx)bit[idx]+=val;
}

int sum(int idx){
  int ans = 0;
  for(++idx;idx>0;idx-=idx&-idx)ans+=bit[idx];
  return ans;
}

int sum(int l,int r){
  return sum(r)-sum(l-1);
}

signed main(){__
    int T = 1,n;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        for(int i =0;i<n;i++)
            add(i,nums[i]);

        multiset<int> st;
        st.insert(nums[0]);
        int last = 1; 
        
        int ans = 0;
        while(st.size()){
            int mx = *st.rbegin();
            st.erase(st.find(mx));

            int nxt = sum(last,last+mx-1);
            if(nxt>mx){
                for(int i = last;i<last+mx;i++)
                    st.insert(nums[i]);
                last = last+mx;
            }
            else
                ans+=mx;
            
        }
        cout<<ans<<endl;
    }
    return 0;
}