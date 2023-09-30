#include <bits/stdc++.h>
using namespace std;
int main(){
    string s,t;
    cin>>s>>t;
    int n = s.size();
    int m = t.size();
    set<string> ss;
    set<string> st;
    for(int i = 0;i<n;i++){
        for(int j = i;j<n;j++){
            ss.insert(s.substr(i,(j-i)+1));
        }
    }
    for(int i = 0;i<m;i++){
        for(int j = i;j<m;j++){
            st.insert(t.substr(i,(j-i)+1));
        }
    }
    set<string>sst;
    for(auto c:st)
        sst.insert(c);
    for(auto c:ss)
        sst.insert(c);
    set<string> final;
    for(auto c:sst){
        if(ss.count(c) && st.count(c))continue;
        final.insert(c);
    }
    cout<<final.size()<<endl;
    return 0;
}