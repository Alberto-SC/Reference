#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int inf = 1e9+7;
struct ST{
    int n;
    vector<int> st;
    ST(int n):n(n){
        st.resize(2*n,inf);
    }
	inline void update(int x, int val) {
		x += n;
		st[x] = val;
		for (; x /= 2; st[x] = min(st[x<<1], st[x<<1|1]));
	}
	inline int query(int l, int r) {
		int ans = inf;
		for (l += n, r += n; l <= r; l = (l + 1) / 2, r = (r - 1) / 2) {
			if (l & 1) ans = min(ans, st[l]);
			if (~r & 1) ans = min(ans, st[r]);
		}
		return ans;
	}
};
int main(){__
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        ST st(n);
        vector<int> nums(n);
        vector<int> pref(n);
        vector<int> suf(n);
        for(int i = 0;i<n;i++){
            cin>>nums[i];
            st.update(i,nums[i]);
            if(i)
                pref[i] = max(pref[i-1],nums[i]);
            else 
                pref[i] = nums[i];
        }
        for(int i =n-1;i>=0;i--){
            if(i<n-1)
                suf[i] = max(nums[i],suf[i+1]);
            else    
                suf[i] = nums[i];        
        }
        bool flag = false;
        int x,y,z;
        for(int i = 0;i<n-2;i++){
            int l = i,r = n;
            while(l+1<r){
                int m = (l+r)>>1;
                if(st.query(i+1,m)<pref[i])
                    r = m;
                else
                    l = m;
            }
            int l2 = i,r2 = n;
            while(l2+1<r2){
                int m = (l2+r2)>>1;
                if(st.query(i+1,m)<=pref[i])
                    r2 = m;
                else
                    l2 = m;
            }
            int bl = r2+1,br = r;
            int f = -1;
            while(bl<=br){
                int m = (bl+br)>>1;
                if(suf[m]== pref[i]){f = m;break;}
                if(suf[m]<pref[i])
                    br = m-1;
                else
                    bl = m+1;
            }
            // cout<<i<<" "<<l<<" "<<r<<" "<<l2<<" "<<r2<<" "<<f<<" "<<query(i+1,f-1)<<" "<<pref[i]<<" "<<suf[f]<<endl;
            if(st.query(i+1,f-1)== pref[i] && suf[f] == pref[i]){
                flag = true;
                x = i+1;
                y = f-(i+1);
                z = n-f;
                break;
            }
        }
        if(flag){
            cout<<"YES"<<endl;
            cout<<x<<" "<<y<<" "<<z<<endl; 
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}
