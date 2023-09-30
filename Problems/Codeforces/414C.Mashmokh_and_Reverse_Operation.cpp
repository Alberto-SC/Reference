#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
vector<lli> hs[2];
vector<lli> a;
vector<lli> aux;
lli n;
void solve(lli l,lli r,vector<lli> &v,lli d = 0 ){
    if(l ==r)return ;
    vector<lli> x;
    lli m = (l+r)>>1;
    vector<lli> left;
    vector<lli> rigth;
    for(int i = l;i<=m;i++)
        left.push_back(aux[i]);
    for(int i = m+1;i<=r;i++)
        rigth.push_back(aux[i]);
    solve(l,m,left,d+1); 
    solve(m+1,r,rigth,d+1);
    int li = rigth.size()-1,ri= rigth.size()-1;
    lli normal = 0,reverse = 0;
    int idx = 0;
    while(li>=0 && ri>=0){
        if(left[li]>= rigth[ri])
            li--;
        else {
            ri--;
            reverse+=li+1;
        }
    }
    li = 0,ri = 0;
    while(li<left.size() && ri<rigth.size()){
        if(left[li]<=rigth[ri]){
            v[idx++] = left[li++];
        }
        else{
            v[idx++] = rigth[ri++];
            normal+=rigth.size()-li;
        }
    }

    while(li<left.size()){
        v[idx++]=left[li++];
    }
    while(ri<rigth.size()){
        v[idx++]=rigth[ri++];
    }
    hs[0][n-d] += normal;
    hs[1][n-d] += reverse;
}

int main(){__
    lli q,s,h;
    cin>>n;
    hs[0].resize(n+1);
    hs[1].resize(n+1);
    a.resize(1<<n);
    vector<bool> who(n+1);
    for(lli i = 0;i<1<<n;i++)
        cin>>a[i];
    aux = a;
    solve(0,(1<<n)-1,a);
    // for(lli i = 0;i<=n;i++){cout<<hs[0][i]<<" "<<hs[1][i]<<endl;}
    cin>>q;
    for(lli i = 0;i<q;i++){
        cin>>h;
        for(lli k = 0;k<=h;k++){
            who[k] = !who[k];
        }

        lli ans = 0;
        for(lli k = 0;k<=n;k++){
            if(who[k])  
                ans+=hs[1][k];
            else 
                ans+=hs[0][k];        
        }
        cout<<ans<<endl;
    }

    return 0;
}