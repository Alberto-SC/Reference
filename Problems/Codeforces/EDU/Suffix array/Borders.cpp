#include <bits/stdc++.h>
using namespace std;
#define y second
#define x first
typedef long long int lli;
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


int main(){
    int n;
    string s;
    cin>>s;
    s+="#";
    n = s.size();
    vector<int> p(n),c(n);
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
      
    vector<int> lcp(n);
    k = 0;
    for(int i = 0;i<n-1;i++){
        int x = c[i];
        int j = p[x-1];
        while(s[i+k] == s[j+k])k++;
        lcp[x] = k;
        k = max(k-1,0);
    }
    // for(int i = 0;i<n;i++)cout<<lcp[i]<<" "<<p[i]<<" "<<s.substr(p[i])<<endl;
    vector<int> last(n,-1);
    stack<pair<int,int>> st;
    for(int i = 1;i<n;i++){
        while(!st.empty() && st.top().x> lcp[i]){
            auto x = st.top();
            st.pop();
            last[x.y] = i;
        }
        st.push({lcp[i],i});
    }
    // for(auto c:last)cout<<c<<" ";
    lli ans = (((lli)n-1ll)*(lli)n)/2ll;
    // cout<<ans<<endl;
    for(int i = 0;i<n-1;i++){
        int x = i+1;
        while(last[x] != -1){ 
            ans+= (lli)lcp[x]*(lli)(last[x]-x);
            x = last[x];
        }
        ans+=(lli)lcp[x]*(lli)(n-x);
        // cout<<lcp[x]<<" "<<ans<<endl;


    }
    cout<<ans<<endl;
    return 0;
}