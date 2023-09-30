#include <bits/stdc++.h>
using namespace std;
#define print(A)for(auto c:A)cout<<c<<" ";cout<<endl;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> acum[201];
        for(int i = 0;i<=200;i++)acum[i] = vector<int>(n,0);
        for(int i = 0;i<n;i++){
            acum[nums[i]][i] = 1;
        }
        for(int i = 0;i<=200;i++){
            for(int j = 1;j<n;j++){
                acum[i][j] = acum[i][j]+acum[i][j-1];
            }
        }
        int ans  = -1;
        for(int i = 1;i<=200;i++){
            vector<int> pos;
            for(int j = 0;j<n;j++){
                if(nums[j]==i)pos.push_back(j);
            }
            if(pos.size())ans = max(ans,(int)pos.size());
            if(pos.size()){
                // print(pos);
                int anshere = -1;
                for(int k = 1;k<=200;k++){
                    if(k == i)continue;
                    for(int x =0 ;x<pos.size()-1;x++){
                        int xx = min(x+1,(int)pos.size()-(x+1));
                        xx*=2;
                        anshere = max(anshere,  xx+ (acum[k][pos[x+1]]-acum[k][pos[x]]));
                    }
                    if(pos.size()>=2){
                        for(int x =0;x<pos.size()/2;x++){
                           anshere = max(anshere,  ((x+1)*2)+ (acum[k][pos[(pos.size()-1)-x]]-acum[k][pos[x]]));
                        }
                    }
                }
                ans = max(ans,anshere);
            }

        }
        cout<<ans<<endl;

    }
    return 0;
}