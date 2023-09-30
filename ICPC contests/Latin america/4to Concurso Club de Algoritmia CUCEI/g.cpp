
#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define x first
#define y second
typedef long long int lli;

const lli mod = 1e9+7;
lli bin_pow(lli a,lli b){
    lli x = 1;
    while(b){
        if(b&1) (x*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return x;
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
    string s;
    lli n,pt;
    cin>>n>>pt;
    cin>>s;
    s+='#';
    n = s.size();
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
    for(int i = 0;i<n-1;i++){
        int x = c[i];
        int j = p[x-1];
        while(s[i+k] == s[j+k])k++;
        lcp[x] = k;
        k = max(k-1,0);
    }
    vector<int> zero(n);
    zero[n-1] = n;
    for(int i = n-1;i>=0;i--){
        if(lcp[i] == 0)zero[i] = i;
        else if(lcp[i]!= 0 && i+1<n)zero[i] = zero[i+1];
    }
    for(int i = 0;i<n;i++)cout<<lcp[i]<<" "<<p[i]<<" "<<s.substr(p[i],n-p[i])<<endl;
    cout<<endl;
    // for(auto c:zero)cout<<c<<" ";
    // cout<<endl;
    vector<int> frec(n+1);
    // cout<<n<<endl;
    lcp.push_back(0);
    lcp[0] = -1;
    for(int i = 1;i<n;i++){
        int l = i,r = zero[i+1];
        // cout<<l<<" "<<r<<" "<<p[i]<<endl;
        if(lcp[i+1]>=lcp[i]+1){
            frec[1]+= (n-1-p[i]-(lcp[i+1]));
            frec[r-l]+=(lcp[i+1])-(lcp[i]);
        }
        else 
            frec[1]+= ((n-1)-p[i])-(lcp[i]);
            
        for(auto c:frec)cout<<c<<" ";
        cout<<endl;
    }
    lli ans = 0;
    for(int i = 1;i<=n;i++)
            (ans+=bin_pow(i,pt)*frec[i])%=mod;
    cout<<ans<<endl;
    return 0;
}
