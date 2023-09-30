#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int maxn = 100007;
int main(){__
    int t = 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<pair<lli,lli>> s(n);
        for(int i = 0;i<n;i++){
            cin>>s[i].first;
        }
        lli s2 = 0;
        for(int i = 0;i<n;i++){
            cin>>s[i].second;
            s2+=s[i].second;
        }
        lli l = 0,r = 1e9+7;
        while(l+1<r){
            int mid = (l+r)>>1;
            lli sum = 0;
            for(int i = 0;i<n;i++){
                if(s[i].first>mid){
                    sum+=s[i].second;
                }
            }
            if(sum<=mid){
                r = mid;
            }
            else 
                l = mid;
        }
        cout<<r<<endl;
    }
    return 0;
}

