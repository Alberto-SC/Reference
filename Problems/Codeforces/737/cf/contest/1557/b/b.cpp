#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int cont = 0;
        map<int,vector<int>> pos;
        vector<int> snums = nums;
        sort(snums.begin(),snums.end());
        for(int i = 0;i<n;i++){
            pos[nums[i]].push_back(i);
        }
        for(auto &c:pos){
            reverse(c.second.begin(),c.second.end());
        }
        int last= pos[snums[0]].back();
        pos[snums[0]].pop_back();
        cont = 1;
        for(int i = 1;i<n;i++){
            if(pos[snums[i]].back()!=last+1)
                cont++;
            last = pos[snums[i]].back();
            pos[snums[i]].pop_back();
        }   
        if(cont<=k)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;

    }
    return 0;
}  
