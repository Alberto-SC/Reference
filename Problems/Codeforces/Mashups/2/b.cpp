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
        for(auto &c:nums)cin>>c;
        bool flag = false;
        for(int i= 1;i<n;i++)
            if(nums[i]==nums[i-1])flag = true;
        if(*min_element(nums.begin(),nums.end())== *max_element(nums.begin(),nums.end())){
            cout<<1<<endl;
            for(int i = 0;i<n;i++)
                cout<<1<<" ";
            cout<<endl;
        }
        else if(nums[0]==nums[n-1] || n%2==0){
            cout<<2<<endl;
            for(int i = 0;i<n;i++){
                if(i&1)cout<<1<<" ";
                else cout<<2<<" ";
            }
            cout<<endl;
        }
        else if(!flag && nums[n-1]!= nums[n-2] &&nums[n-2]!= nums[n-3]){
            cout<<3<<endl;
            for(int i = 0;i<n-3;i++){
                if(i&1)
                    cout<<2<<" ";
                else
                    cout<<1<<" ";
            }          
            cout<<"1 2 3"<<endl;
        }
        else {
            int x = 0;
            cout<<2<<endl;
            for(int i = 0;i<n;i++){
                if(i &&nums[i]==nums[i-1])x=1;
                if(i&1)
                    cout<<(x?2:1)<<" ";
                else
                    cout<<(x?1:2)<<" ";
            }   
            cout<<endl;
         
        }
    }
    return 0;
}  
