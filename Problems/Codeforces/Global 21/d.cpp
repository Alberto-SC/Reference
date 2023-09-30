#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<int> nums;
int dis(int i,int j){
    if(i == j)return 0;
    if(i+1== j)return 1;
    // cout<<i<<" "<<j<<endl;
    int mx = -1,idxmn = 0,idxmx,mn = 1e9;
    for(int a = i;a<=j;a++){
        if(nums[a]>mx){
            mx = nums[a];
            idxmx = a;
        }
        if(nums[a]<mn){
            mn = nums[a];
            idxmn = a;
        }
    }
    if((idxmn == i && idxmx == j )||(idxmn == j && idxmn == i))return 1;
    else if(idxmx == j)
        return dis(i,idxmn)+1;
    else if(idxmx == i)
        return dis(idxmn,j)+1;
    else if(idxmn == i)
        return dis(idxmx,j)+1;
    else if(idxmn == j)
        return dis(i,idxmx)+1;
    return 0;
}

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        nums.resize(n);
        for(auto &c:nums)cin>>c,c--;
        vector<int> pos(n+1);
        for(int i = 0;i<n;i++)
            pos[nums[i]] = i;
        cout<<dis(0,pos[n-1])+dis(pos[n-1],n-1)<<endl;
    }
    return 0;
}  
