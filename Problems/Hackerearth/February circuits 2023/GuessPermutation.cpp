#include <bits/stdc++.h>
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long 
using namespace std;

signed main(){__
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        int mn = 1e9,mx = -1e9,s = 0;
        for(auto &c:nums){
            cin>>c;
            s+=c;
            mn = min(mn,s);
            mx = max(mx,s);
        }

        if(mn == 0){
            cout<<-1<<endl;
            continue;
        }
        int start;
        if(mn == 1)start = 1;
        else if(mn>1){
            cout<<-1<<endl;
            continue;
        }
        else start = abs(mn)+1;

        if(start<0|| start >n+1){
            cout<<-1<<endl;
            continue;
        }

        vector<int> ans;
        ans.push_back(start);

        vector<bool> used(n+7);

        used[start] = true;
        bool flag = true;

        for(int i = 0;i<n;i++){
            int nxt = ans.back()+nums[i];
            if(nxt>n+1){
                flag = false;
                break;
            }
            if(used[nxt])flag = false;
            used[nxt] = true;
            ans.push_back(nxt);
        }
        if(!flag)cout<<-1<<endl;
        else {
            for(auto c:ans)cout<<c<<" ";
            cout<<endl;
        }
        
    }
    
    return 0;
}
