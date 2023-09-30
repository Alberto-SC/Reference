#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define x first 
#define y second
int main(){__
    int t = 1,n;
    string s;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<pair<int,int>> pares;
        for(int i = 0;i<n;i++)
            for(int j = i+1;j<n;j++)
                if(nums[i]== nums[j])pares.push_back({i,j});
        int m = pares.size();
        int ans = 0;
        vector<int> ac(n+1);

        for(int i = 0;i<m;i++){
            ac[pares[i].x]++;
            ac[pares[i].y+1]--;
        }
        for(int i = 1;i<n;i++)ac[i] = ac[i-1]+ac[i];
        vector<int> pre(n);
        pre[0] =ac[0];
        for(int i = 1;i<n;i++)pre[i] vfc = pre[i-1]+ac[i];
        for(auto c:ac)cout<<c<<" ";
        cout<<endl;
        for(auto c:pre)cout<<c<<" ";
        cout<<endl;
        for(int i = 0;i<m;i++){
            int inside = pre[pares[i].y-1]-pre[pares[i].x];
            int out = pre[n-1]-pre[pares[i].y];
            cout<<inside<<" "<<out<<endl;
            ans+= (m-1)-(inside+out);
        }
        cout<<ans<<endl;
    }
    return 0;
}

