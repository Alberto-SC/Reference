#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int n,m,d;
    cin>>n>>d>>m;
    vector<int> a(n);
    for(auto &c:a)cin>>c;
    sort(a.rbegin(),b.rend());
    int cont = 0;
    for(int i = 0;i<n;i++){
        if(a[i]<m)break;
        ans+=a[i];
        n-=d;
        cont++;
    }
    int mm = 0;
    for(int i = n-(cont*d);i++){
        if(a[i]<m && mm ==0)
            ans+=a[i];
        else {
            m = d;
        }
    }
    cout<<ans<<endl;
    return 0;
}

