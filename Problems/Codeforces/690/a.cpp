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
        int l = 0,r = n-1;
        int turn =1;
        while(l<=r){
            if(turn&1)cout<<nums[l++]<<" ";
            else cout<<nums[r--]<<" ";
            turn++;
        }
        cout<<endl;
    }
    return 0;
}  

