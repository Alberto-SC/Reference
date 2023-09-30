#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int N = 2500007;
signed main(){__
    int n; 
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    vector<int> f(N);
    for(int i = 0;i<n;i++)
        f[nums[i]]++;
    
    int f4 = 0;
    int f2f = 0,f2s = 0;
    for(int i = 0;i<N;i++){
        if(f[i]>=4){
            f4 = i;
            break;
        }
        if(f[i]>=2){
            if(f2f){ 
                f2s = i;
                break;
            }
            else 
                f2f = i;
            
        }
    }
    if(f4){
        cout<<"YES"<<endl;
        for(int i = 0,cont = 4;i<n&&cont;i++)
            if(nums[i]== f4)cout<<i+1<<" ",cont--;
        return 0;
    }
    if(f2s){
        vector<int> ans;
        for(int i = 0,cont = 2;i<n&&cont;i++)
            if(nums[i]==f2f)ans.push_back(i+1),cont--;
        for(int i = 0,cont = 2;i<n&&cont;i++)
            if(nums[i]==f2s)ans.push_back(i+1),cont--;
        swap(ans[1],ans[2]);
        cout<<"YES"<<endl;
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
        return 0;
    }
    unordered_map<int,pair<int,int>>mp;
    mp.reserve(32768); 
    mp.max_load_factor(0.25); 
    for(int i = 0;i<n;i++){ 
        for(int j = 0;j<n;j++){ 
            if(i ==j)continue;
            int u = nums[i]+nums[j];
            if(!mp.count(u))mp[u]={i,j};
            else{
                if(i== mp[u].first or i == mp[u].second)continue;
                if(j== mp[u].first or j == mp[u].second)continue;
                cout<<"YES"<<endl;
                cout<<mp[u].first+1<<" "<<mp[u].second+1<<" "<<i+1<<" "<<j+1<<endl;
                return 0;
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}