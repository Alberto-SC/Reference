#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000000;
#define x first
#define y second
vector<int> pa(MAXN,0);
vector<int> pb(MAXN,0);
int find_set(int u ){return pa[u] == u?u:pa[u] = find_set(pa[u]);}
int find_set2(int u ){return pb[u] == u?u:pb[u] = find_set2(pb[u]);}
int main(){
    int n,as,ae,bs,be;
    cin>>n;
    vector<pair<int,int>> a(n);
    vector<pair<int,int>> b(n);
    for(int i = 0;i<=n;i++)pa[i] = i;
    for(int i = 0;i<=n;i++)pb[i] = i;
    for(int i = 0;i<n;i++){
        cin>>as>>ae>>bs>>be;
        a[i] = {as,ae};
        b[i] = {bs,be};
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(int i = 1;i<n;i++){
        if(max(a[i].x,a[i-1].x)<= min(a[i].y,a[i-1].y)){
            int u = find_set(i);
            int v = find_set(i-1);
            pa[u] = v;
        }
        if(max(b[i].x,b[i-1].x)<= min(b[i].y,b[i-1].y)){
            int u = find_set2(i);
            int v = find_set2(i-1);
            pb[u] = v;
        }
    }
    if(pa == pb)return cout<<"YES"<<endl,0;
    return cout<<"NO"<<endl,0;
    
}