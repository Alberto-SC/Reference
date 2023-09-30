#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
vector<int>ps;
vector<int>qs;
int n;
bool check(int d,int s){
    multiset<int> st;
    int cont = 0;
    // cout<<"D "<<d<<endl;
    for(auto c:qs)st.insert(c);
    for(int i = 0;i<ps.size();i++){
        if(ps[i]>s)continue;
        int y = ps[i]+d;
        int x = s-ps[i];
        auto it = st.upper_bound(min(y,x));
        if(it== st.begin())continue;
        it--;
        // cout<<*it<<endl;
        if(abs(ps[i]-(*it))<=d){
            st.erase(it);
            cont++;
        }
    }
    // cout<<cont<<endl;
    if(cont>=n)return true;
    return false;
}

int main(){__
    int p,q,s;
    cin>>n>>p>>q>>s;
    ps.resize(p);
    qs.resize(q);
    for(auto &c:ps)cin>>c;
    for(auto &c:qs)cin>>c;
    sort(ps.rbegin(),ps.rend());
    int l = -1,r = s+1;
    while(l+1<r){
        int m = (l+r)>>1;
        if(!check(m,s))l = m;
        else  r = m;
        // cout<<endl;
    }
    if(r == s+1)return cout<<-1<<endl,0;
    cout<<r<<endl;
}