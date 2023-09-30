#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,s;
    cin>>T;
    while(T--){
        cin>>n>>s;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int mx = 0;
        vector<int> b(57);
        for(int i = 0;i<n;i++){
            mx = max(mx,nums[i]);
            b[nums[i]]++;
        }
        int sum= 0;
        for(int i= 1;i<=mx;i++){
            if(!b[i])sum+=i;
        }
        if(sum>s){
            cout<<"NO"<<endl;
            continue;
        }
        else if(sum==s){
            cout<<"YES"<<endl;
            continue;
        }
        bool flag = false;
        for(int i = mx+1;i<=200;i++){
            sum+=i;
            if(sum==s){
                cout<<"YES"<<endl;
                break;
            }
            else if(sum>s){
                cout<<"NO"<<endl;
                break;
            }
        }
    }
    return 0;
}