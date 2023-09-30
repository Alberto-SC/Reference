
#define _GLIBCXX_DEBUG 1
#define _GLIBCXX_DEBUG_PEDANTIC 1
#define _FORTIFY_SOURCE 2
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
set<lli> ans;
void solve(vector<int> A){
    int n = A.size();
    if(n ==1){
        ans.insert(A[0]);
        return;
    }
    lli sum = 0;
    int mn = 1e9+7,mx = 0;
    for(int i = 0;i<n;i++){
        sum+=A[i];
        mn = min(mn,A[i]);
        mx = max(mx,A[i]);
    }
    int mid = (mn+mx)>>1;
    vector<int>l,r;
    for(int i = 0;i<n;i++){
        if(A[i]<=mid)l.push_back(A[i]);
        else r.push_back(A[i]);
    }
    ans.insert(sum);
    if(mn ==mx)return;
    solve(l);
    solve(r);
}

int main(){__
	int t= 1,n,q;
    lli x;
    cin>>t; 
    while(t--){
        cin>>n>>q;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        ans.clear();
        solve(nums);
        for(int i = 0;i<q;i++){
            cin>>x;
            if(ans.count(x))cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    return 0;
}  

