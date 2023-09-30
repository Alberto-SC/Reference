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
        int ans = -1;
        for(int s = 2;s<=100;s++){
            vector<bool> used(n,false);
            int cont = 0;
            for(int i = 0;i<n;i++){
                for(int j = i+1;j<n;j++){
                    if(!used[i] && !used[j] && nums[i]+nums[j]== s)
                        cont++,used[i] = true,used[j] = true;

                }
            }
            ans = max(ans,cont);
        }   
        cout<<ans<<endl;
    }
    return 0;
}

