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
        vector<int> nums[n];
        vector<int> ans(n);
        int need = n-1;

        for(int i = 0;i<n;i++){
            nums[i].resize(n-1);
            for(int j = 0;j<n-1;j++){
                cin>>nums[i][j];
            }
        }

        map<int,int> last;
        for(int i = 0;i<n-1;i++){
            map<int,int> mp;
            for(int j = 0;j<n;j++){
                mp[nums[j][i]]++;
            }   
            for(auto c:mp){
                if(i == n-2 && c.second == n-need){
                    ans.back() = c.first;
                }
                if(c.second == need){
                    if(ans[i]!=0 && last.count(c.first)){
                        ans[i] = c.first;
                    }
                    else if(ans[i]== 0)
                        ans[i] = c.first;
                }
            }
            last = mp;
            need--;
        }
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}