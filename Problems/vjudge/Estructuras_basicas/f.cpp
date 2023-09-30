#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4*10e5;
set<char> st[MAXN];
void build(int v,int L,int R,string s){
    if(L == R)st[v].insert(s[i]);
    int m = (L+R)/2;
    build(v*2,L,m,s);
    build(v*2+1,m+1,R,s);
    st[v].insert(st[v*2].begin(),st[v*2].end());
    st[v].insert(st[v*2+1].begin(),st[v*2+1].end());
}
void update(int v,int sl,int sr,int pos, int c){
    if(sl == sr)st[v].remove(c)
}
int main(){
    int n,q,pos,a,b;
    string s,c;
    cin>>s;
    cin>>q;
    n = s.size();
    build(0,0,n-1,s);
    for(int i = 0;i<q;i++){
        cin>>type;
        if(type==1)cin>>pos>>c,update(0,0,n-1,pos,c);
        if(type==2)cin>>a>>b,cout<<query(0,0,n-1,--a,--b)<<endl;
    }
    return 0;
}