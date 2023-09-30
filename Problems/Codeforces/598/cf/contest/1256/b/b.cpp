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
        int  last = 0;
        vector<int> pos(n);
        for(int i = 0;i<n;i++){
            pos[nums[i]-1] = i;
        }
        for(int i = 0;i<n;i++){
            cout<<last<<endl;
            if(pos[i]>last){
                cout<<"HI"<<endl;
                for(int j = pos[i];j>last;j--){
                    swap(nums[j],nums[j-1]);
                }
                last = pos[i];
            }
            else last =max(last,pos[i]+1);
        }
        for(auto c:nums)cout<<c<<" ";
        cout<<endl;
    } 
    return 0;
}  
