#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

bool isComposite(int x){
    for(int i = 2;i*i<=x;i++){
        if(x%i==0)return true;
    }

    return false;
}

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        int s = 0;
        for(auto &c:nums)cin>>c,s+=c;
        if(s%2==0|| isComposite(s)){
            cout<<n<<endl;
            for(int i = 1;i<=n;i++)
                cout<<i<<" ";
            cout<<endl;
        }
        else {
            cout<<n-1<<endl;
            bool odd = false;
            for(int i = 1;i<=n;i++){
                if(nums[i-1]&1 &&odd)cout<<i<<" ";
                else if(nums[i-1]&1 &&!odd)odd = true;
                else cout<<i<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}  
