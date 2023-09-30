#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        map<int,vector<int>> mp;
        for(int i = 0;i<n;i++)
            mp[nums[i]].push_back(i);
        int ans = 0,a,sl,sr;
        for(auto c:mp){
            int l = 0 ,r = 0; 
            int s = 1,mx = 1,mn = 0,mnPos = 0;
            int last =c.second[0];
            int N = c.second.size();
            for(int i = 1;i<N;i++){
                s-=c.second[i]-(last+1);
                if(s <mn){
                    mn = s;
                    mnPos = i;
                }
                s+=1;
                if(s-mn>mx){
                    mx = s-mn;
                    l = mnPos;
                    r = i;
                }
                last = c.second[i];
                
            }
            if(mx >ans){
                ans = mx;
                sl = c.second[l];
                sr = c.second[r];
                a = c.first;
            }
        }
        cout<<a<<" "<<sl+1<<" "<<sr+1<<endl;
    }
    return 0;
} 