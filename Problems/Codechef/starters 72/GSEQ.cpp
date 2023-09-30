#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> nw;
        bool flag = false;
        int off = 0;
        for(int i = 0;i<n;i++){
            if(nums[i]==1 && !flag){
                flag = true;
                off = i;
            }
            if(flag)nw.push_back(nums[i]);
        }
        if(!flag){
            cout<<"0"<<endl;
            continue;
        }
        n = nw.size();
        vector<int> ac(n);
        ac[0] = nw[0]==1?1:-1;
        for(int i = 1;i<n;i++){
            ac[i] = ac[i-1]+(nw[i]?1:-1);
        }

        vector<int> ans;
        ans.push_back(0+off);
        int last = 1;
        for(int i = 0;i<n;i++){
            if(ac[i]==last){
                ans.push_back(i+1+off);
                last++;
            }
        }
        cout<<ans.size()<<endl;
        for(auto c:ans)cout<<c+1<<" ";
        cout<<endl;
    }
    return 0;
}