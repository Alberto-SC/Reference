#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    vector<int> evens;
    vector<int> odds;
    for(int i = 0;i<n;i++){
        if(nums[i]&1)odds.push_back(nums[i]);
        else evens.push_back(nums[i]);

    }
    sort(odds.begin(),odds.end());
    sort(evens.begin(),evens.end());
    int ans = 0;
    for(int i = evens.size()-1;i>=0;i--)
        if(ans+evens[i]>=ans)ans+=evens[i];
    ans+=odds[odds.size()-1];
    // cout<<ans<<endl,0;
    for(int i = odds.size()-2 ;i>=0;i-=2){
        if(i-1>=0){
            int aux = ans+odds[i]+odds[i-1];
            if(aux>=ans)ans+=odds[i]+odds[i-1];
            else return cout<<ans<<endl,0;
        }
        else return cout<<ans<<endl,0;
    }
    cout<<ans<<endl;
    return 0;
}