#include <bits/stdc++.h>
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long 

using namespace std;
signed main(){__
    int T,n,k;
    cin>>T;
    while(T--){
        cin>>n>>k;
        vector<int>ac(100);
        for(int i = 0;i<n;i++){
            int l,r;
            cin>>l>>r;
            if(k>=l && k<=r){
                ac[l]++;
                ac[r+1]--;
            }
        }
        for(int i = 1;i<80;i++){
            ac[i]+=ac[i-1];
        }
        int mx = ac[k];
        bool flag = true;
        for(int i = 0;i<=50;i++){
            if(i == k)continue;
            if(ac[i]>=mx)flag = false;
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
