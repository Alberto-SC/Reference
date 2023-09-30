
#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define x first
#define y second
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
    cin>>s;
    s+='$';
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
    for(int i = 0;i<n-1;i++){
        int x = c[i];
        int j = p[x-1];
        while(s[i+k] == s[j+k])k++;
        lcp[x] = k;
        k = max(k-1,0);
    }
    for(auto c:p)cout<<c<<" ";
    cout<<endl;
    for(int i = 1;i<n;i++)cout<<lcp[i]<<" ";
    cout<<endl;
    return 0;
}
