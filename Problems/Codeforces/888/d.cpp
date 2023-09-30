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
        vector<int> nums(n-1);
        set<int> st;
        for(int i = 1;i<=n;i++)st.insert(i);
        for(auto &c:nums)cin>>c;

        int last = 0;
        int bad = 0;
        for(int i = 0;i<n-1;i++){
            int x = nums[i]-last;
            if(st.count(x) == 0)bad = x;
            else st.erase(x);
            last = nums[i];
        }

        if(st.size()==1){
            cout<<"YES"<<endl;
            continue;
        }
        if(st.size()!=2){
            cout<<"YES"<<endl;
            continue;
        }
        int a1 = *st.begin();
        st.erase(st.begin());
        int a2 = *st.begin();

        // cout<<bad<<" "<<a1<<" "<<a2<<endl;
        if(a1+a2 == bad)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}