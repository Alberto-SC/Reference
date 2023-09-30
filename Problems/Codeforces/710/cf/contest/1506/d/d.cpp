#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        int s = 0;
        for(auto &c:nums)cin>>c;
        sort(nums.begin(),nums.end());
        vector<int> sz;
        for(int i = 0;i<n;i++){
            int l = i;
            while(l<n && nums[l]==nums[i]){
                l++;
            }
            sz.push_back(l-i);
            s+=(l-i);
            i= l-1;
        }
        sort(sz.begin(),sz.end());
        if(sz.size()>=3){
            if(sz.back()>s-sz.back()){
                s-=sz.back();
                cout<<sz.back()-s<<endl;
            }
            else {
                if(n%2==0)cout<<0<<endl;
                else cout<<1<<endl;
            }
        }
        else if(sz.size()==2){
            cout<<sz[1]-sz[0]<<endl;
        }
        else if(sz.size()==1){
            cout<<sz[0]<<endl;
        }
    }
    return 0;
}  
