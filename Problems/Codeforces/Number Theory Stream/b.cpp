#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n,k,m;
    while(t--){
        cin>>n>>k>>m;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> mods[m];
        for(int i = 0;i<n;i++){
            mods[nums[i]%m].push_back(i);
        }
        bool flag = false;
        for(int i = 0;i<m;i++){
            if(mods[i].size()>=k){
                cout<<"Yes"<<endl;
                for(int j = 0;j<k;j++)
                    cout<<nums[mods[i][j]]<<" ";
                cout<<endl;
                flag = true;
                break;
            }
        }
        if(!flag)cout<<"No"<<endl;
    }
    return 0;
}  

