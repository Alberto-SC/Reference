#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    string s;
    cin>>s;
    int n = s.size();
    vector<int> nums(9);
    iota(nums.begin(),nums.end(),1);
    int ans = 1e18;
    vector<int> x = {7,9,8,4,3,2,5,1,6};
    do{
        vector<vector<int>> dis(10,vector<int> (10));
        for(int i = 0;i<9;i++){
            for(int j = 0;j<9;j++){
                dis[nums[i]][nums[j]] = abs(j-i);
            }
        }
        int res = 0,idx=0;
        for(int i =0 ;i<9;i++){
            if(nums[i]==(s[0]-'0')){
                idx =i;
                break;
            }
        }
        res = idx+1;
        int last = s[0]-'0';
        for(int i = 1;i<n;i++){
            res+=dis[s[i]-'0'][last]+1;
            last = s[i]-'0';
        }
        ans = min(ans,res);
    }while(next_permutation(nums.begin(),nums.end()));
    sort(nums.begin(),nums.end());
    cout<<ans<<endl;
    do{
        vector<vector<int>> dis(10,vector<int> (10));
        for(int i = 0;i<9;i++){
            for(int j = 0;j<9;j++){
                dis[nums[i]][nums[j]] = abs(j-i);
            }
        }
        int res = 0,idx=0;
        for(int i =0 ;i<9;i++){
            if(nums[i]==(s[0]-'0')){
                idx =i;
                break;
            }
        }
        res = idx+1;
        int last = s[0]-'0';
        for(int i = 1;i<n;i++){
            res+=dis[s[i]-'0'][last]+1;
            last = s[i]-'0';
        }
        if(res ==ans){
            for(auto c:nums)cout<<c<<" ";
            cout<<" -> "<<res<<endl;
            // cout<<endl;
        }
    }while(next_permutation(nums.begin(),nums.end()));
    cout<<ans<<endl;
    return 0;
}  
