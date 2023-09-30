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
        sort(nums.begin(),nums.end());
        stack<int> s;
        for(int i = 0;i<n;i++){
            if(!s.empty()){
                int last = nums[i];
                bool used = false;
                while(!s.empty() && s.top()==last){
                    used = true,
                    s.pop();
                    last++;
                }
                s.push(last);
            }
            else 
                s.push(nums[i]);
        }
        if(s.size()==2)cout<<"Y"<<endl;
        else if(s.size()==1 && n>1)cout<<"Y"<<endl;
        else cout<<"N"<<endl;
    }
    return 0;
}  
