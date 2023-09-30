#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

int N = 400007;
vector<int> bit(N);

void add(int idx,int v){
    for(++idx;idx<N;idx+=idx&-idx)bit[idx]+=v;
}

int sum(int idx){
    int res = 0;
    for(++idx;idx>0;idx-=idx&-idx)res+=bit[idx];
    return res;
}

int sum(int l,int r){
    return sum(r)-sum(l-1);
}

void print(int n){
    for(int i = 0;i<n;i++){
        cout<<sum(i,i)<<" ";
    }
    cout<<endl;
}


signed main(){__
    int t,n,a,b,x;
    cin>>n>>a>>b;
    vector<int> pos(n+1);
    for(int i = 0;i<a;i++){
        cin>>x;
        pos[x] = i;
        add(i,1);
    }
    for(int i = 0;i<b;i++){
        cin>>x;
        pos[x] = n-i;
        add(n-i,1);
    }
    int idx = a-1;
    int ans = 0;
    if(pos[0]== idx || pos[0]== idx+1)ans++;

    for(int i = 1;i<=n;i++){
        add(pos[i],-1);
        idx = pos[i]-1;
        if(pos[0]<=idx && sum(pos[0],idx)==1)ans++;
        else if(pos[0]>idx && sum(idx+1,pos[0])==1)ans++;
    }
    cout<<ans<<endl;
}