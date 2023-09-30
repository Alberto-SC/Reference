#include <bits/stdc++.h>
using namespace std;
#define int long long
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

const int N = 1000000;
vector<int> sum(N+1);
void criba(){
    for(int i = 1;i<=N;i++){
        for(int j = 2;j*i<=N;j++){
            sum[i*j]+=i;
        }
    }
}

signed main(){__
    int t,n;
    cin>>t;
    criba();
    while(t--){
        cin>>n;
        bool flag = false;
        for(int i = 1;i<n;i++){
            if(sum[i]>i && sum[n-i]>n-i){
                flag = true;
                break;
            }
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}

