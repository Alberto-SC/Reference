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
        vector<int> b(101);
        for(auto &c:nums)cin>>c,b[c]++;
        int ans = 0;
        int cont = 0;
        int idx;
        bool flag = false;
        for(int i = 0;i<n;i++){
            if(b[i]== 0 ){
                ans+=2*i;
                break;
            }
            else if(b[i]== 1){
                ans+=i;
                idx = i;
                flag = true;
                break;
            }
    
        }
        if(flag){
            int i;
            for(i = idx+1;i<=100;i++){
                if(b[i]== 0)break;
            }
            ans+=i;
        }
        cout<<ans<<endl;
    }
    return 0;
}

