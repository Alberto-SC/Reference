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

        vector<int> ids;
        for(int i= 2*n;i>=1;i--){
            int j = a[i];
            if(ids.size()==0)ids.push_back(a[i]);
            else if(j<ids.back())ids.push_back(a[i]);
        }

        int last = 2*n;

        for(int i = 0;i<ids.size();i++){
            int aux = ids[i];
            ids[i] =last-ids[i];
            last = aux;
        }
        sort(ids.begin(),ids.end());
        int m = ids.size();
        vector<int> b(2*n+1);
        vector<int> DP(n+1);
        DP[0] = true;
        for(int k=0;k<m;k++){
            int r = k;
            while(r < m && ids[r] == ids[k]) r++;
            b.assign(n+1,0);
             for(int i = ids[k]; i <= n; i++) {
                if(!DP[i] && DP[i - ids[k]] && b[i - ids[k]] < r - k) {
                    b[i] = b[i - ids[k]] + 1;
                    DP[i] = true;
                }
            }
            k = r - 1;
        }
        cout<<(DP[n]?"YES":"NO")<<endl;
    }

    return 0;
}  
