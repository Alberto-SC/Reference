#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ld long double

const ld PI = acos(-1);


signed main(){__
	int t= 1,n;
    ld x =0;
    for(int i = 1;i<100000;i++){
        x+=1.0/(i*i*i);
    }
    cout<<x<<endl;
    for(int i = 6;i<=90;i++){
        cout<<" "<<i<<" "<<(PI*PI*PI)/i<<" "<<x<<endl;
    }
    // cout<<x/PI<<endl;
    return 0;
}  
