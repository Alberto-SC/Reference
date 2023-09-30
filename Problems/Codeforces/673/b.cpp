#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t = 1,n,T;
    cin>>t;
    while(t--){
        cin>>n>>T;
        vector<int> nums(n);
        map<int,vector<int>> mp;
        for(int i = 0;i<n;i++){
            cin>>nums[i];
            mp[nums[i]].push_back(i);
        }  
        vector<int> ans(n,0);
        for(int i = 0;i<n;i++){
            if(mp.count(T-nums[i])){
                if(T-nums[i]== nums[i]){
                    for(int k = 0;k<mp[nums[i]].size()/2;k++)
                        ans[mp[nums[i]][k]] = 0;
                    for(int k = mp[nums[i]].size()/2; k< mp[nums[i]].size();k++)
                        ans[mp[nums[i]][k]] = 1;
                }
                else{
                    for(int k = 0;k<mp[nums[i]].size();k++)
                        ans[mp[nums[i]][k]] = 0;
                    for(int k = 0;k<mp[T-nums[i]].size();k++)
                        ans[mp[T-nums[i]][k]] = 1;
                    mp.erase(T-nums[i]);
                }
            }
            else if(mp.count(nums[i])){
                for(int k = 0;k<mp[nums[i]].size();k++)
                    ans[mp[nums[i]][k]] = 0;
            }
            mp.erase(nums[i]);
        }
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }

    return 0;
}

