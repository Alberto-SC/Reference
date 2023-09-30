#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 200007;
vector<int> nums(maxn);

int t= 1,n,k;
bool check(int x){
    int s = 0;
    int inf = 1e9;
    vector<int> pref(n,inf);
    for(int i = 0;i<n;i++){
        s+= nums[i]<x?-1:1;
        pref[i] = min(s,i-1>=0?pref[i-1]:inf);
        if(i>= k-1 && s>0)
            return true;
        if(i-k<0)continue;
        if(s-pref[i-k]>0)
            return true;
    }
    if(s>0)return true;

    return false;
}
signed main(){__
    while(t--){
        cin>>n>>k;
        for(int i = 0;i<n;i++)
            cin>>nums[i];
        
        int l = 1,r = n+1;
        while(l+1<r){
            int m = (l+r)>>1;
            if(check(m))
                l = m;
            else 
                r = m;
        }
        cout<<l<<endl;
    }
    return 0;
}  