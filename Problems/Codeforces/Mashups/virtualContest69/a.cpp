#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    while(t--){
        vector<int> nums(6);
        for(auto &c:nums)cin>>c;
        sort(nums.begin(),nums.end());
        int legs =nums[2],cont = 0;
        vector<int> diff;
        for(int i = 0;i<6;i++){
            if(nums[i]==legs)cont++;
            else{
                diff.push_back(nums[i]);
            }
        }
        if(cont<4)
            cout<<"Alien"<<endl;
        else{
            if(diff.size()== 0 || (diff.size() == 2 && diff[0]== diff[1]))cout<<"Elephant"<<endl;
            else cout<<"Bear"<<endl;
        }
    }
    return 0;
}  
