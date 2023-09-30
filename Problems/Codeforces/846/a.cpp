#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        int odd = 0,even = 0;
        for(auto &c:nums){
            cin>>c;
            if(c&1)odd++;
            else even++;
        }

        if(odd>=3){
            cout<<"YES"<<endl;
            int cont = 3;
            for(int i = 0;i<n;i++){
                if(nums[i]&1){
                    cout<<i+1<<" ";
                    cont--;
                }
                if(cont ==0)break;
                
            }
            cout<<endl;
        }
        else if(odd>=1 && even>=2){
            int cont = 2;
            cout<<"YES"<<endl;
            for(int i = 0;i<n;i++){
                if(nums[i]&1){
                    cout<<i+1<<" ";
                    break;
                }
            }
            for(int i = 0;i<n;i++){
                if(nums[i]%2 ==0){
                    cout<<i+1<<" ";
                    cont--;
                }
                if(cont == 0)break;
            }
            cout<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}