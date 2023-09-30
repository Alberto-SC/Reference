#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

struct S{
    int i,j,x;
};

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        int s = 0;
        for(auto &c:nums)cin>>c,s+=c;
        if(s%n){
            cout<<-1<<endl;
            continue;
        }
        int target = s/n;
        vector<S> moves;
        for(int i = 1;i<n;i++){
            if(nums[i]>target){
                moves.push_back({i+1,1,nums[i]/(i+1)});
                if(moves.back().x==0)moves.back().x = 1;
                nums[0] +=(i+1)*moves.back().x;
                nums[i] -=(i+1)*moves.back().x;
            }
        }
        for(int i = 1;i<n;i++){
            if(nums[i]<target){
                moves.push_back({1,i+1,target-nums[i]});
                nums[0]-=target-nums[i];
                nums[i]+=target-nums[i];
            }
        }
        cout<<moves.size()<<endl;
        for(auto c:moves)cout<<c.i<<" "<<c.j<<" "<<c.x<<endl;
    }
    return 0;
}  
