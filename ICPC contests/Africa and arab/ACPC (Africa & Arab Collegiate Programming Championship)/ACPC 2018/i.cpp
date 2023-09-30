#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    freopen("icecream.in", "r", stdin);  
	int t= 1,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<pair<int,int>> nums(n);
        for(int i = 0;i<n;i++)
            cin>>nums[i].first;
        for(int i = 0;i<n;i++)
            cin>>nums[i].second;

        sort(nums.begin(),nums.end(),[&](pair<int,int> a,pair<int,int> b){
            return a.first<b.first;
        });
        int mx = nums[k-1].first;
        vector<pair<int,int>> nw;
        for(int i = 0;i<n;i++){
            if(nums[i].first<=mx)
                nw.push_back(nums[i]);
        }
        sort(nw.begin(),nw.end(),[&](pair<int,int> a,pair<int,int> b){
            return a.second>b.second;
        });
        lli ans = 0;
        for(int i = 0;i<k;i++){
            ans+= nw[i].second;
        }
        cout<<mx<<" "<<ans<<endl;
    }
    return 0;
}  

