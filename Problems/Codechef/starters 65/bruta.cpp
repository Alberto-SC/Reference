#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,k;
    cin>>T;
    while(T--){
        cin>>n>>k;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int ans = 0,ans2 = 0,ans3 = 0;
        bitset<13> A;
        A[1] = 1;
        A[3] = 1;
        A[4] = 1;
        A[7] = 1;
        A[8] = 1;
        A[10] = 1;
        A[11] = 1;
        cout<<A<<endl;
        set<int> st;
        for(int mask = 0;mask<(1<<n);mask++){
            bool flag = true;
            int N = 0;
            vector<int> v;
            for(int i = 0;i<n;i++){
                if((mask>>i)&1){
                    N++;
                    v.push_back(nums[i]);
                }
            }
            for(int i = 0;i<N;i++){
                for(int j = i+1;j<N;j++){
                    if(((v[i]+v[j])%k)==0)flag = false;
                }
            }
            ans2++;
            if(flag){
                ans++;
                bitset<13> bs(mask);
                int num = (int)((bs&A).to_ulong());
                st.insert(num);
            }
            else {
                ans3++;
            }
        }
        map<int,int> mp;
        for(auto c:st){
            bitset<13> bs(c);
            cout<<bs<<endl;
            mp[bs.count()]++;
        }
        for(auto c:mp)cout<<c.first<<" "<<c.second<<endl;
        cout<<ans<<" "<<ans2<<" "<<ans3<<" "<<" "<<st.size()<<endl;
    }
    return 0;
}