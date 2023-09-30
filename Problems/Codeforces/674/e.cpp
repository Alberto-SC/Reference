#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t = 1,n;
    while(t--){
        cin>>n;
        vector<int> a(3);
        vector<int> b(3);
        for(auto &c:a)cin>>c;
        for(auto &c:b)cin>>c;
        int winsa = 0;
        int winsb = 0;
        winsa = min(a[0],b[1])+min(a[1],b[2])+min(a[2],b[0]);
        int x = 0;
        if(b[0]>=a[0]+a[1])x+=b[0]-(a[0]+a[1]);
        if(b[1]>=a[1]+a[2])x+=b[1]-(a[1]+a[2]);
        if(b[2]>=a[2]+a[0])x+=b[2]-(a[2]+a[0]);
        cout<<x<<" "<<winsa<<endl;
    }
    return 0;
}

