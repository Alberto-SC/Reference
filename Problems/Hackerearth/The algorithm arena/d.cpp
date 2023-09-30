#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

using namespace std;

int josephus(int N,int k){
    int i = 1, ans = 0;
    while (i <= N) { 
        ans = (ans + k) % i;
        i++;
    }
    return ans + 1;
}

signed main(){__
    int T,n,k;
    cin>>n>>k;
    cout<< josephus(n,k)<<endl;
}


