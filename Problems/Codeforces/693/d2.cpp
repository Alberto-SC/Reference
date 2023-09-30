#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        priority_queue<int> odds;
        priority_queue<int> evens;
        for(int i = 0;i<n;i++){
            if(nums[i]&1)odds.push(nums[i]);
            else evens.push(nums[i]);
        }
        if(odds.size()<evens.size())
            cout<<"Alice"<<endl;
        else if(odds.size()>evens.size()+1)cout<<"Bob"<<endl;
        else cout<<"Tie"<<endl;
    }
    return 0;
}  