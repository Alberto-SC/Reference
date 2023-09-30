#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long

signed main(){__
    int n;
    while(1){
        cin>>n;
        if(n== 0)break;
        vector<int> w(n),l(n),h(n);
        vector<int> in_degree(n);
        for(int i = 0;i<n;i++)
            cin>>w[i]>>l[i]>>h[i];
        
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(w[i]> w[j] && l[i]> l[j] && h[i]>h[j])
                    in_degree[j]++;
                if(w[i]<w[j] && l[i]<l[j] && h[i]<h[j])
                    in_degree[i]++;
            }   
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            cout<<in_degree[i]<<" ";
            ans+= in_degree[i]==0;
        }
        cout<<endl;
        cout<<ans<<endl;
    }
    return 0;
}