#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
const int inf = 1000000007; 
#define x first
#define y second
int main(){
    lli n,k;
    cin>>n>>k;
    vector<lli> nums(n);
    for(auto &c:nums)cin>>c;
    lli dp[n+1][k];
    map<lli,lli> mp;
    set<pair<lli,lli>> s;
    lli fmax = -inf;
    for(lli i = 0;i<k;i++)dp[n][i] = 0;
    for(lli z = n-1;z>=0;z--){ 
        mp[nums[z]]++;
        lli frec = mp[nums[z]];
        s.erase({frec-1,nums[z]});
        s.insert({frec,nums[z]});
        set<pair<lli,lli>>::iterator it = s.end();
        it--;
        dp[z][0] = it->y - s.begin()->second;
    }
    for(lli i = 1;i<k;i++){
        for(lli j = 0;j<n;j++){
            fmax = -inf;
            s.clear();
            mp.clear();
            for(lli z = j;z<n;z++){
                mp[nums[z]]++;
                lli frec = mp[nums[z]];
                s.erase({frec-1,nums[z]});
                s.insert({frec,nums[z]});
                set<pair<lli,lli>>::iterator it = s.end();
                it--;
                fmax = max((it->y-s.begin()->y)+dp[z+1][i-1],fmax);            
            }
            dp[j][i] = fmax;
        }
    }
    // for(lli i = 0;i<n;i++)
        // for(lli j = 0;j<k;j++)cout<<dp[i][j]<<" \n"[j == k-1];
    lli mx = -inf;
    for(lli i = 0;i<k;i++)mx = max(mx,dp[0][i]);
    cout<<mx<<endl;
    return 0;
}