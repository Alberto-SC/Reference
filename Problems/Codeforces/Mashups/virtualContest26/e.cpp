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
        vector<int> nums(2*n);
        for(auto &c:nums)cin>>c;
        vector<int> a((2*n)+1);
        for(int i = 0;i<2*n;i++)
            a[nums[i]]= i;
        vector<int> pos;
        for(int i= 2*n;i>=1;i--){
            int j = a[i];
            if(pos.size()==0)pos.push_back(a[i]);
            else if(j<pos.back())pos.push_back(a[i]);
        }

        int last = 2*n;
        vector<int> x;
        for(int i = 0;i<pos.size();i++){
            x.push_back(last-pos[i]);
            last =pos[i];
        }
        sort(x.begin(),x.end());
        int m = x.size();
        vector<int> b(2*n+1);
        vector<bool> DP(n+1);
        DP[0] = true;
        for(int k=0;k<m;k++){
            int r = k;
            while(r<m && x[r]==x[k])r++;
            b.assign(n+1,0);
             for(int i = x[k]; i <= n; i++) {
                if(!DP[i] && DP[i-x[k]] && b[i-x[k]]<r-k){
                    b[i] = b[i-x[k]] + 1;
                    DP[i] = true;
                }
            }
            k = r - 1;
        }
        cout<<(DP[n]?"YES":"NO")<<endl;
    }

    return 0;
}  