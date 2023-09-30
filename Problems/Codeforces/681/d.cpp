#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){__
    int t = 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int a = nums[0], b = 0;
        bool flag = true;
        for (int i =1;i<n;i++) {
            a = min(a,nums[i]-b);
            if(a<0)
                flag = false;
            b = nums[i]-a;
        }
        cout<<"NO\0YES\0"+3*flag<<endl;
    }
    return 0;
}

