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

        int id = 0;
        vector<int> cont(n+1);
        vector<int> last(n+1); 

        map<int,int> mp;
        int sum = 0;
        for(int i = 0;i<n;i++){
            mp[nums[i]]++;
        }
        bool flag = true;
        for(auto c:mp){
            if(c.second%c.first)flag = false;
        }
        if(!flag){
            cout<<-1<<endl;
            continue;
        }

        for(int i =0 ;i<n;i++){
            if(cont[nums[i]]%nums[i]== 0){
                id++;
                last[nums[i]] = id;
                cout<<id<<" ";
            }
            else  cout<<last[nums[i]]<<" ";
            cont[nums[i]]++;
        }
        cout<<endl;
    }
    return 0;
}