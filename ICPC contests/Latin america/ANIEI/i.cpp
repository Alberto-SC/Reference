#include <bits/stdc++.h>
using namespace std;
#define x first 
#define y second
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
void radix_sort(vector<int> &P,vector<int> &c){
    int n = P.size();
    vector<int> cont(n);
    for(auto d:c){
        cont[d]++;
    }
    vector<int> pos(n);
    vector<int> nP(n);
    pos[0] = 0;
    for(int i = 1;i<n;i++)
        pos[i] = pos[i-1]+cont[i-1];
    for(auto d:P){
        int x = c[d];
        nP[pos[x]] = d;
        pos[x]++; 
    }
    P=nP;
}
int main(){__
    int n,x;
    string s,t;
    while(cin>>s>>t>>x){
        int sz1 = s.size(),sz2 = t.size();
        s+="$"+t+"#";
        n = s.size();
        vector<int> c(n);
        vector<int> p(n);
        vector<pair<char,int>> a(n);
        for(int i = 0;i<n;i++)
            a[i] = {s[i],i};
        sort(a.begin(),a.end());
        for(int i = 0;i<n;i++)p[i] =a[i].y;
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
                p[i]= ((p[i] - (1<<k))+n)%n;
            radix_sort(p,c);    
            vector<int> nC(n);
            nC[p[0]]=  0;
            for(int i = 1;i<n;i++){
                pair<int,int> prev = {c[p[i-1]], c[(p[i-1]+ (1<<k))%n]};
                pair<int,int> now = {c[p[i]], c[(p[i]+ (1<<k))%n]};
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
        for(int i= 0;i<n-1;i++){
            int x = c[i];
            int j = p[x-1];
            while(s[i+k] == s[j+k])k++;
            lcp[x] = k;
            k = max(k-1,0); 
        }
        
        // for(int i = 0;i<n;i++)cout<<lcp[i]<<" "<<p[i]<<" "<<s.substr(p[i],n-p[i])<<endl;
        int ans = -1;
        int idx = -1;
        for(int i = 2;i<n;i++){
            if((p[i]<sz1 && p[i-1]>=sz1+1) || (p[i]>= sz1+1 && p[i-1]<sz1)){
                if(lcp[i]>ans){
                    ans= lcp[i];
                    idx = p[i];
                }
            }
        }
        if(ans>=x)cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}