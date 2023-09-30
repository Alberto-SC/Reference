#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    vector<int> next[n+1];
    for(int i = 0;i<n;i++)
        next[nums[i]].push_back(i);
    for(int i = 0;i<=n;i++)
        next[i].push_back(n);
    int ans = 0;
    for(int i = 0;i<=n;i++)
        reverse(next[i].begin(),next[i].end());

    int x = 0,y = 0;
    for(int i = 0;i<n;i++){
        if(nums[i]!= x && nums[i]!= y){
            if(next[x].back()>next[y].back()){
                x = nums[i];
            }
            else {
                y = nums[i];
            }
            ans++;
        }
        next[nums[i]].pop_back();
    }
    cout<<ans<<endl;
    return 0;
}  

