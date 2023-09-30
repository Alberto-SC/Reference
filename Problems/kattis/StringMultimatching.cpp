#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define x first
#define y second
void radix_sort(vector<pair<pair<int,int>,int>> &A){
    int n = A.size();
    vector<int> cont(n);
    for(auto c:A){
        cont[c.x.y]++;
    }
    vector<pair<pair<int,int>,int>> B(n);
    vector<int> pos(n);
    pos[0] = 0;
    for(int i = 1;i<n;i++)
        pos[i] = pos[i-1]+cont[i-1];
    for(auto c:A){ 
        cont[c.x.y]--;
        B[pos[c.x.y]] = c;
        pos[c.x.y]++;
    }
    A = B;
    for(auto c:A){
        cont[c.x.x]++;
    }
    pos[0] = 0;
    for(int i = 1;i<n;i++)
        pos[i] = pos[i-1]+cont[i-1];
    for(auto c:A){
        B[pos[c.x.x]] = c;
        pos[c.x.x]++;
    }

    A = B;
}

bool check(int idx,string &s,string &t){
    int n = s.size();
    int m = t.size();
    for(int i = idx,j = 0;j<m && i<n;i++,j++){
        if(s[i]>t[j])return true;
        else if(s[i]<t[j])return false;
    }
    return true;
}


signed main(){__
    int n;
    while(cin>>n){
        cin.ignore();
        vector<string>s (n);
        for(int i = 0;i<n;i++)
            getline(cin,s[i]);
        
        string text;
        getline(cin,text);
        vector<vector<int>> ans(n);
        int N;
        text+=char(31);
        N =text.size();
        vector<int> p(N);
        vector<pair<char,int>> a(N);
        for(int i = 0;i<N;i++)a[i] = {text[i],i};
        sort(a.begin(),a.end());
        for(int i = 0;i<N;i++)
            p[i] = a[i].y; 
        vector<int> c(N);
        c[p[0]] = 0;
        for(int i = 1;i<N;i++){
            if(a[i].x == a[i-1].x)
                c[p[i]]= c[p[i-1]];
            else 
                c[p[i]] =c[p[i-1]]+1;
        }
        int k = 0;
        while((1<<k)<N){
            vector<pair<pair<int,int>,int>> A(N);
            for(int i = 0;i<N;i++)
                A[i] = {{c[i],c[(i+(1<<k))%N]},i};
            radix_sort(A);
            for(int i = 0;i<N;i++)
                p[i] = A[i].y;
            c[p[0]] = 0;
            for(int i =1;i<N;i++){
                auto x = A[i].first;
                auto y = A[i-1].first;
                if(x == y)c[p[i]]= c[p[i-1]];
                else c[p[i]] = c[p[i-1]]+1;
            }
            k++;
        }
        k = 0;
        vector<int> lcp(N);
        for(int i = 0;i<N-1;i++){
            int x = c[i];
            int j = p[x-1];
            while(text[i+k] == text[j+k])k++;
            lcp[x] = k;
            k = max(k-1,0ll);
        }
        // for(int i = 0;i<N;i++)cout<<lcp[i]<<" "<<p[i]<<" "<<text.substr(p[i],N-p[i])<<endl;
        // cout<<endl;


        for(int i = 0;i<n;i++){
            string t = s[i];
            int l= 0,r = N+1;
            int m = t.size();
            while(l+1<r){
                int mid = (l+r)>>1;
                if(check(p[mid],text,t))
                    r = mid;
                else l = mid;
            }
            // cout<<r<<endl;
            bool flag = true;
            for(int j = p[r],k = 0;k<m;j++,k++)
                if(text[j]!= t[k]){flag = false;break;}
            if(flag){
                while(1){
                    ans[i].push_back(p[r]);
                    r++;
                    if(r>=N || lcp[r]<s[i].size())break;
                }
            }
            sort(ans[i].begin(),ans[i].end());
            for(auto x:ans[i])cout<<x<<" ";
            cout<<endl;
        }
    }
   
}