
#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define x first
#define y second
typedef long long int lli;
vector<int> st;
int N;
void update(int pos,int val,int v = 1,int l = 0,int r = N-1){
    if(l==r)st[v] = val;
    else {
        int m = (l+r)>>1;
        if(pos<=m)
            update(pos,val,v<<1,l,m);
        else
            update(pos,val,v<<1|1,m+1,r);
        st[v] = min(st[v<<1],st[v<<1|1]);
    }
}

int query(int l,int r,int v = 1,int sl = 0,int sr = N-1){
    if(sl>r || sr<l ||sl>sr)return 1e9;
    if(sl>=l &&sr <=r)return st[v];
    int m = (sl+sr)>>1;
    return min(query(l,r,v<<1,sl,m),query(l,r,v<<1|1,m+1,sr));
}


void radix_sort(vector<int> &P,vector<int> &c){
    int n = P.size();
    vector<int> cnt(n);
    for(auto d:c)
        cnt[d]++;
    vector<int> pos(n);
    vector<int> nP(n);
    pos[0]= 0;
    for(int i = 1;i<n;i++)
        pos[i] = pos[i-1]+cnt[i-1];
    for(auto d:P){
        int i = c[d];
        nP[pos[i]] = d;
        pos[i]++;
    }
    P = nP;

}

int main(){__
    string s,t;
    cin>>s>>t;
    int szS = s.size();
    int szT = t.size();
    s+='$'+t+'#';
    int n = s.size();
    vector<int>c(n);
    vector<int>p(n);
    vector<pair<char,int>> a(n);
    for(int i = 0;i<n;i++)a[i] = {s[i],i};
    sort(a.begin(),a.end());
    for(int i = 0;i<n;i++)
        p[i] = a[i].second;
    c[p[0]] = 0;
    for(int i = 1;i<n;i++){
        if(a[i].first == a[i-1].first)
            c[p[i]] = c[p[i-1]];
        else c[p[i]] = c[p[i-1]]+1;
    }

    int k = 0;
    while((1<<k)<n){
        for(int i = 0 ;i<n;i++)
            p[i] = ((p[i]-(1<<k))+n)%n;
        radix_sort(p,c);
        vector<int> nC(n);
        nC[p[0]] = 0;
        for(int i = 1;i<n;i++){
            pair<int,int> prev = {c[p[i-1]],c[(p[i-1]+ (1<<k))%n]};
            pair<int,int> now = {c[p[i]],c[(p[i]+ (1<<k))%n]};
            if(prev == now)
                nC[p[i]] = nC[p[i-1]];
            else nC[p[i]] = nC[p[i-1]]+1;
        }
        c = nC;
        k++;
    }

    // LCP O(n)
    k = 0;
    vector<int> lcp(n);
    N  = n+1;
    st.resize(4*N);
    for(int i = 0;i<n-1;i++){
        int x = c[i];
        int j = p[x-1];
        while(s[i+k] == s[j+k])k++;
        lcp[x] = k;
        k = max(k-1,0);
    }
    for(int i = 0;i<n;i++)
        update(i,lcp[i]);
    update(n,0);
    // for(int i = 0;i<n;i++)cout<<lcp[i]<<" "<<p[i]<<" "<<s.substr(p[i],n-p[i])<<endl;
    // cout<<endl;
    vector<int> prevT(n+1);
    vector<int> nextT(n+1);
    vector<int> prevS(n+1);
    vector<int> nextS(n+1);
    nextS[n] = n;
    nextT[n] = n;
    for(int i = 2;i<n;i++){
        if(p[i]<szS)
            prevS[i] = i,prevT[i] = prevT[i-1];
        else if(p[i]>szS)
            prevT[i] = i,prevS[i] = prevS[i-1];
    }
    for(int i = n-1;i>=0;i--){
        if(p[i]<szS)
            nextS[i] = i,nextT[i] = nextT[i+1];
        else if(p[i]>szS)
            nextT[i] = i,nextS[i] = nextS[i+1];

    }
    lli ans = 0;
    int sz;
    for(int i = 2;i<n;i++){
        if(p[i]<szS){
            sz = szS-p[i];
            int mx = max({query(prevT[i]+1,i),query(i+1,nextT[i]),i+1<n?lcp[i+1]:0});
            ans+= sz-mx;
            // cout<<ans<<endl;
        }
        else if(p[i]>szS){
            sz = szS+szT+1-p[i];
            int mx = max({query(prevS[i]+1,i),query(i+1,nextS[i]),i+1<n?lcp[i+1]:0});
            ans+=sz-mx;
            // cout<<ans<<endl;
        }
    }
    cout<<ans<<endl;
    return 0;
}
