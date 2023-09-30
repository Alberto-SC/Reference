#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> copy = nums;
        sort(copy.begin(),copy.end());
        int l = -1,r =-1;
        for(int i = 0;i<n;i++){
            if(nums[i]!= copy[i]){l = i;break;}

        }
        for(int i = n-1;i>=0;i--){
            if(nums[i]!= copy[i]){r = i;break;}
        }
        if(l==-1){
            cout<<"yes"<<endl;
            cout<<"1 1"<<endl;
        }
        else{
            reverse(nums.begin()+l,nums.begin()+r+1);
            if(nums ==copy){
                cout<<"yes"<<endl;
                cout<<l+1<<" "<<r+1<<endl;
            }
            else{
                cout<<"no"<<endl;
            }
        }
    }
    return 0;
}  
