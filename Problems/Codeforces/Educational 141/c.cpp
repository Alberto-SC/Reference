#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
struct FT {
	vector<int> s;
	FT(int n) : s(n) {}
	void update(int pos, int dif) { // a[pos] += dif
		for (; pos < s.size(); pos |= pos + 1) s[pos] += dif;
	}
	int query(int pos) { // sum of values in [0, pos)
		int res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
	int lower_bound(int sum) {// min pos st sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is.
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			if (pos + pw <= s.size() && s[pos + pw-1] < sum)
				pos += pw, sum -= s[pos-1];
		}
		return pos;
	}
};


signed main(){__
    int T = 1,n,m;
    cin>>T;
    while(T--){
        cin>>n>>m;
        vector<int> nums(n);
        FT ft1(1007);
        FT ft2(1007);
        for(auto &c:nums)cin>>c;
        
        for(int i = 0;i<n;i++){
            ft1.update(nums[i],nums[i]);
            ft2.update(nums[i],1);
        }
        int ans = n+1;
        for(int i = n-1;i>=0;i--){
            int x1 = nums[i];
            ft1.update(nums[i],-nums[i]);
            ft2.update(nums[i],-1);
            // cout<<"I: "<<i<<endl;
            int pos = ft2.lower_bound(i-1);
            if(pos !=1007){
                if(i){
                    x1 += ft1.query(pos+1);
                    int c = ft2.query(pos+1);
                    int diff = c-(i-1);
                    x1-=pos*diff;
                }
                // cout<<"WIN: "<<x1<<endl;

                if(x1<=m){
                    ans = n-i;
                    break;
                }
            }

            pos = ft2.lower_bound(i+1);
            if(pos!=1007){
                x1 = ft1.query(pos+1);
                int c = ft2.query(pos+1);
                int diff = c-(i+1);
                x1-=pos*diff;
                // cout<<"LOSE: "<<x1<<endl;
                if(x1<=m){
                    ans = n-i;
                    break;
                }
            }

            ft1.update(nums[i],nums[i]);
            ft2.update(nums[i],1);
        }
        cout<<ans<<endl;
    }
    return 0;
}