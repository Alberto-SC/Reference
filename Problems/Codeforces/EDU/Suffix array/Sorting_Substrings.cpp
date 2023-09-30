#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
#define x first
#define y second
vector<int> st;
const int inf = 10000000;
int N;
void update(int pos ,int val,int v = 1,int sl = 0,int sr = N-1){
    if(sl == sr)st[v] = val;
    else {
        int mid = (sl+sr)>>1;
        if(pos<=mid)
            update(pos,val,v<<1,sl,mid);
        else   
            update(pos,val,v<<1|1,mid+1,sr);
        st[v] = min(st[v<<1],st[v<<1|1]);
    }
}
vector<int>p,c;
int query(int l ,int r,int v = 1,int sl = 0,int sr = N-1){
    if(l>sr || r<sl || sl>sr)return inf;
    if(sl>=l && sr<=r){
        return st[v];
    }
    int mid = (sl+sr)>>1;
    return min(query(l,r,v<<1,sl,mid),query(l,r,v<<1|1,mid+1,sr));
}

bool comp(pair<int,int> a,pair<int,int> b){
    int lcp;
    if(a.x== b.x) 
        lcp = N-p[c[a.x]];
    else 
        lcp = query(min(c[a.x],c[b.x])+1,max(c[a.x],c[b.x]));
    int szA = (a.y-a.x)+1;
    int szB = (b.y-b.x)+1;
    if(szA>lcp && szB> lcp)
        return c[a.x]<c[b.x];    
    else {
        if(szA == szB) return a<b;
        return szA<szB;
    }

}

void radix_sort(vector<int> &P ,vector<int> &c){
    int n = P.size();
    vector<int> cont(n);
    for(auto x:c)
        cont[x]++;
    vector<int> pos(n);
    vector<int> nP(n);
    pos[0]= 0;
    for(int i = 1;i<n;i++)
        pos[i] = pos[i-1]+cont[i-1];
    for(auto x:P){
        int idx = c[x];
        nP[pos[idx]] = x;
        pos[idx]++;
    }
    P = nP;
}

int main(){__
    int q,l,r;
    string s;
    cin>>s;
    cin>>q;
    s+=" ";
    int n = s.size();
    c.resize(n);
    p.resize(n);
    vector<pair<char,int>> a(n);
    for(int i = 0;i<n;i++)a[i] = {s[i],i};
    sort(a.begin(),a.end());
    for(int i = 0;i<n;i++)p[i] = a[i].y;
    c[p[0]] = 0;
    for(int i = 1;i<n;i++){
        if(a[i].x == a[i-1].x)
            c[p[i]] = c[p[i-1]];
        else 
            c[p[i]] = c[p[i-1]]+1;
    }   
    int k = 0;
    while((1<<k)<n){
        for(int i = 0;i<n;i++)
            p[i] = ((p[i]-(1<<k))+n)%n;

        radix_sort(p,c);
        vector<int> nC(n);
        nC[p[0]] = 0;
        for(int i = 1;i<n;i++){
            pair<int,int> prev = {c[p[i-1]],c[(p[i-1]+(1<<k))%n]};
            pair<int,int> now = {c[p[i]],c[(p[i]+(1<<k))%n]};
            if(prev == now)
                nC[p[i]] = nC[p[i-1]];
            else 
                nC[p[i]] = nC[p[i-1]]+1;
        }
        c = nC;
        k++;
    }
    k = 0;
    vector<int> lcp(n);
    for(int i = 0;i<n-1;i++){
        int x = c[i];
        int j = p[x-1];
        while(s[i+k] == s[j+k])k++;
        lcp[x] = k;
        k = max(k-1,0);
    }
    // for(int i = 0;i<n;i++)cout<<p[i]<<" "<<lcp[i]<<" "<<s.substr(p[i],n-p[i])<<endl;
    // cout<<endl;
    N = n;
    st.resize(4*n);
    for(int i = 0;i<n;i++)
        update(i,lcp[i]);
    vector<pair<int,int>> Q;
    for(int i = 0;i<q;i++){
        cin>>l>>r;
        l--,r--;
        Q.push_back({l,r});
    }
    sort(Q.begin(),Q.end(),comp);
    for(auto c:Q)cout<<c.x+1<<" "<<c.y+1<<endl;
    return 0;
}