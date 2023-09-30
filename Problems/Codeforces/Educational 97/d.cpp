#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int deepth = 0;
const int maxn = 200007;
vector<int> graph[maxn];

int main(){__
    int t = 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<vector<int>> ac;
        for(int i = 1;i<n;){
            int j = i;
            while(j+1<n && nums[j]<nums[j+1]){
                j++;
            }
             vector<int> z;
            for(int k = i;k<=j;k++){
                z.push_back(nums[k]);
            }
            i = j+1;
            ac.push_back(z);   
        }
        vector<int> parent[n+1];
        int x = 0;
        int h = 0;
        parent[h].push_back(1);
        vector<int> hs(n+1);
        hs[1] = 0;
        vector<int> ans(n+1);
        for(auto c:ac){
            for(auto d:c){
                // cout<<d<<" ";
                ans[d] = parent[h][x]; 
                parent[hs[parent[h][x]]+1].push_back(d);
                hs[d] = hs[parent[h][x]]+1;
            }
            // cout<<endl;
            x++;
            if(x ==parent[h].size()){
                h++;
                x = 0;
            }
        }
        // for(auto c:hs)cout<<c<<" ";
        deepth = 0;
        cout<<*max_element(hs.begin(),hs.end())<<endl;        

    }
    return 0;
}

