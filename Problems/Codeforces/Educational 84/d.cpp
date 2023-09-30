#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t = 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        vector<int> c(n);
        for(auto &c:nums)cin>>c;
        for(auto &x:c)cin>>x;
        set<vector<int>> st;
        int cont = 0;
        while(1){
            vector<int> nw(n);
            for(int i = 0;i<n;i++){
                nw[i] = nums[nums[i]-1];
            }
            // for(auto c:nw)cout<<c<<" ";
            // cout<<endl;
            if(st.count(nw))break;
            else st.insert(nw);
            nums = nw;
            cont++;
        }
        cout<<cont<<endl;

    }
    return 0;
}

