#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> b(200);
        for(int i = 0;i<n;i++)
            b[nums[i]]++;
        for(int i = 0;i<=100;i++){
            if(!b[i])break;
            else {
                b[i]--;
                cout<<i<<" ";
            }
        }         
        for(int i = 0;i<=100;i++){
            for(int j = 0;j<b[i];j++)
                cout<<i<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}  
