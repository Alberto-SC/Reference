#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;   
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t = 1,n,q;
    cin>>t;
    while(t--){
        cin>>n>>q;
        vector<lli> nums(n);
        for(auto &c:nums)cin>>c;
        priority_queue<lli> qmx;
        priority_queue<lli,vector<lli>,greater<lli>> qmn;
        qmx.push(nums[n-1]);
        qmn.push(nums[n-1]);
        for(int i = n-2;i>=0;i--){
            // cout<<qmx.top()<<" "<<qmn.top()<<endl;
            qmx.push(max(nums[i],nums[i]-qmn.top()));
            qmn.push(min(nums[i],nums[i]-qmx.top()));
        }
        cout<<qmx.top()<<endl;
    }
    return 0;
}

