#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
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


int main(){__
    int n,q;
    string s;
    cin>>s;
    s+= '$';
    n = s.size();
    vector<int> p(n);
    vector<pair<char,int>> a(n);
    for(int i = 0;i<n;i++)a[i] = {s[i],i};
    sort(a.begin(),a.end());
    for(int i = 0;i<n;i++)
        p[i] = a[i].y; 
    vector<int> c(n);
    c[p[0]] = 0;
    for(int i = 1;i<n;i++){
        if(a[i].x == a[i-1].x)
            c[p[i]]= c[p[i-1]];
        else 
            c[p[i]] =c[p[i-1]]+1;
    }
    int k = 0;
    while((1<<k)<n){
        vector<pair<pair<int,int>,int>> A(n);
        for(int i = 0;i<n;i++)
            A[i] = {{c[i],c[(i+(1<<k))%n]},i};
        radix_sort(A);
        for(int i = 0;i<n;i++)
            p[i] = A[i].y;
        c[p[0]] = 0;
        for(int i =1;i<n;i++){
            auto x = A[i].first;
            auto y = A[i-1].first;
            if(x == y)c[p[i]]= c[p[i-1]];
            else c[p[i]] = c[p[i-1]]+1;
        }
        k++;
    }
    cin>>q;
    string t;
    // for(int i =0;i<n;i++)cout<<i<<"  "<<p[i]<<" "<<s.substr(p[i],n-p[i])<<endl;
    for(int i = 0;i<q;i++){
        cin>>t;
        int l= 1,r = n-1;
        int m = t.size();
        while(l<r){
            int mid = (l+r)>>1;
            if(check(p[mid],s,t))
                r = mid;
            else l = mid+1;
        }
        bool flag = true;
        for(int j = p[l],k = 0;k<m;j++,k++)
            if(s[j]!= t[k]){flag = false;break;}
        
        if(flag)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}