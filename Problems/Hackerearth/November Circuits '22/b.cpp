#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,l,r;
    vector<int> pre(1000007);
    int N = 1000000;
    for(int i = 1;i<=N;i++){
        for(int j = i;j<=N;j+=i){
            pre[j]++;
        }
    }

    for(int i = 1;i<=N;i++){
        pre[i] = pre[i]==4;

        pre[i]+=pre[i-1];
    }
    cin>>T;
    while(T--){
        cin>>l>>r;
        cout<<pre[r]-pre[l-1]<<endl;
    }
    return 0;
}