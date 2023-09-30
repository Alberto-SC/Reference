#include <bits/stdc++.h>
using namespace std;
#define int long long
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);


const int N = 1000000;
vector<int> sum(N+1);
void criba(){
    for(int i= 1;i<=N;i++)
        for(int j = 2;j*i<=N;j++)
            sum[i*j]+=i;
        
}

signed main(){__
    int t,n;
    cin>>t;
    criba();
    set<int> amicables;
    for(int i = 1;i<=100000;i++)
        if(sum[sum[i]] == i && i!= sum[i])amicables.insert(i),amicables.insert(sum[i]); 

    while(t--){
        cin>>n;
        int idx = 0,ans = 0;
        for(auto c:amicables){
            if(c>=n)break;
            ans+=c;
        }
        cout<<ans<<endl;
    }
    return 0;
}
