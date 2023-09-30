#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long 
#define endl '\n'

int getSum(int n){
    int ans = 0;
    while(n){
        ans+=n%10;
        n/=10;
    }
    return ans;
}

signed main(){
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n;
        int sum = getSum(n);
        while(1){
            n++;
            int x = getSum(n);
            if((x&1) != (sum&1))break;
        }
        cout<<n<<endl;
    }
    return 0;
}
