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
        vector<int> b(n+1);
        for(int i = 0;i<n;i++){
            b[nums[i]]++;
        }
        int mx = 0;
        for(int i = 0;i<n;i++)
            mx = max(mx,b[nums[i]]);
        cout<<mx<<endl;
    }
    return 0;
}  

