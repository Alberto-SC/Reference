#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int inf = 1e16;
const int mod = 1e9+7;

struct STMinMax{
    int n;
    vector<pair<int,int>> st;
    STMinMax(int n):n(n){
        st.resize(2*n,make_pair(inf,-inf));
    }
	inline void update(int x, int val) {
		x += n;
		st[x] = {val,val};
        while(x>>=1){
            st[x].first = min(st[x<<1].first, st[x<<1|1].first);
            st[x].second = max(st[x<<1].second, st[x<<1|1].second);
        }
	}

	inline pair<int,int> query(int l, int r) {
		pair<int,int> ans = {inf,-inf};
        if(r<l)return {0,0};
		for (l += n, r += n; l <= r; l = (l + 1) / 2, r = (r - 1) / 2) {
			if (l & 1){
                ans.first = min(ans.first, st[l].first);
                ans.second = max(ans.second, st[l].second);
            } 
			if (~r & 1){
                ans.first = min(ans.first, st[r].first);
                ans.second = max(ans.second, st[r].second);
            } 
		}
		return ans;
	}
};



signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;


        vector<int> L(n,-1),R(n,n);
        stack<int> st;
        
        for(int i = 0;i<n;i++){
            while(st.size() && nums[st.top()]>nums[i]){
                R[st.top()] = i;
                st.pop();
            }
            if(st.size())
                L[i] = st.top();
            st.push(i);
        } 


        STMinMax STL(n);
        int sum = 0;
        vector<int> pref(n);
        for(int i = 0;i<n;i++){
            sum+=nums[i]; 
            pref[i] = sum;  
            STL.update(i,sum);
        }

        STMinMax STR(n);
        sum = 0;
        vector<int> suff(n);
        for(int i = n-1;i>=0;i--){
            sum+=nums[i]; 
            suff[i] = sum;  
            STR.update(i,sum);
        }


        int ans = 0;
        for(int d = 0;d<n;d++){
            int l = L[d],r = R[d];
            if(nums[d] <0){
                int mnR = STL.query(d+1,r-1).first;
                if(d+1<=r-1)
                    mnR-=pref[d];
                if(mnR>0)mnR = 0;

                int mnL = STR.query(l+1,d-1).first;
                if(l+1<=d-1)
                    mnL-=suff[d];
                if(mnL>0)mnL = 0;

                int res = mnR+mnL+nums[d];

                res*=nums[d];
                ans = max(ans,nums[d]*(mnR+mnL+nums[d]));
            }
            else{
                int mxR = STL.query(d+1,r-1).second;
                if(d+1<=r-1)
                    mxR-=pref[d];
                if(mxR<0)mxR = 0;

                int mxL = STR.query(l+1,d-1).second;
                if(l+1<=d-1)
                    mxL-=suff[d];
                if(mxL<0)mxL = 0;

                int res = mxR+mxL+nums[d];
                
                res*=nums[d];
                ans = max(ans,nums[d]*(mxR+mxL+nums[d])); 
            }
        }
        cout<<ans%mod<<endl;
    }
    return 0;
}