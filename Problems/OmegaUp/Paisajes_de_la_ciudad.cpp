#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> r(n,-1);
    vector<int> l(n,-1);
    stack<pair<int,int>> s;
    for(int i = 0;i<n;i++){
        int c;
        cin>>c;
        while(!s.empty() && s.top().first<c){r[s.top().second] = i; s.pop();}
        if(!s.empty())
            l[i] = s.top().second;
        s.push({c,i});
    }
    vector<int> ans(n);
    for(int i = 0;i<n;i++){
        int lf,rg;
        if(l[i] == -1)lf = i;
        else lf = (i-1)-l[i];
        if(r[i] == -1)rg = n-(i+1);
        else rg = r[i]-(i+1);
        ans[i] = rg+lf+1;
    }
    for(auto c:ans)cout<<c<<" ";
    cout<<endl;
    return 0;
}