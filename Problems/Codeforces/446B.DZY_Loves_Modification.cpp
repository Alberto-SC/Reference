#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define x first
#define y second
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
const lli inf = -1e15;

int main(){__
    lli n,m,k,p;
    cin>>n>>m>>k>>p;
    lli grid[n][m];
    for(lli i = 0;i<n;i++)
        for(lli j = 0;j<m;j++)
            cin>>grid[i][j];

    priority_queue<lli> qr;
    priority_queue<lli> qc;
    vector<lli> sums(n+m);
    for(lli i = 0;i<n;i++){
        lli sum = 0;
        for(lli j = 0;j<m;j++)
            sum+=grid[i][j];
        qr.push(sum);
    }

    for(lli i = 0;i<m;i++){
        lli sum = 0;
        for(lli j = 0;j<n;j++)
            sum+=grid[j][i];
        qc.push(sum);
    }

    vector<lli> a(k+1);
    vector<lli> b(k+1);
    lli ac = 0;
    for(lli i = 1;i<=k;i++){
        lli x = qr.top();
        qr.pop();
        ac+=x;
        qr.push(x-(p*m));
        a[i] =ac; 
    }
    ac = 0;
    for(lli i = 1;i<=k;i++){
        lli x = qc.top();
        qc.pop();
        ac+=x;
        qc.push(x-(p*n));
        b[i] =ac; 
    }
    lli ans = b[k];
    for(int i = 1;i<=k;i++){
        lli x = (a[i] + b[k-i])-((i*p)*(k-i));
        ans = max(ans,x);
    }
    cout<<ans<<endl;
    return 0;
}