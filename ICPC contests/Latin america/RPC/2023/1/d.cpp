#include <bits/stdc++.h>

#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n';

using namespace std;

signed main(){__
    int T,n,m;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> divs;
        for(int i = 1;i*i<=n;i++){
            if(n%i == 0){
                divs.push_back(i);
                if(n/i != i)divs.push_back(n/i);
            }
        }
        sort(divs.begin(),divs.end());
        int mn = 1;

        for (int i=0;i<divs.size() && divs[i]<=mn;i++)
            mn = mn + divs[i];
            
        if(mn>=n){cout<<"Yes"<<endl;}
        else cout<<"No"<<endl;
    }
    return 0;
}
 

  
