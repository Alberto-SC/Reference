#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    vector<int> t1(5);
    vector<int> t2(5);
    for(auto &c:t1)cin>>c;
    for(auto &c:t2)cin>>c;
    
    int a  =0,b = 0;
    a+=t1[0]*6;
    a+=t1[1]*3;
    a+=t1[2]*2;
    a+=t1[3]*1;
    a+=t1[4]*2;

    b+=t2[0]*6;
    b+=t2[1]*3;
    b+=t2[2]*2;
    b+=t2[3]*1;
    b+=t2[4]*2;
    cout<<a<<" "<<b<<endl;
    return 0;
}