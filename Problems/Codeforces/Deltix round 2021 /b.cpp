#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    set<int> st;
    for(int i = 0;i<=n-3;i++){
        if(s[i]=='a' && s[i+1]=='b' && s[i+2]=='c')st.insert(i);
    }
    while(q--){
        int pos;
        char c;
        cin>>pos>>c;
        pos--;
        if(s[pos] == 'a'){
            if(st.count(pos))st.erase(pos);
        }
        if(s[pos] == 'b'){
            if(st.count(pos-1))st.erase(pos-1);
        }
        if(s[pos] == 'c'){
            if(st.count(pos-2))st.erase(pos-2);
        }


        if(c == 'a'){
            if(pos+2<n && s[pos+1]== 'b' && s[pos+2]=='c')st.insert(pos);
        }
        if(c == 'b'){
            if(pos+1<n && pos-1>=0 && s[pos-1] == 'a' && s[pos+1] == 'c')st.insert(pos-1);
        }
        if(c == 'c'){
            if(pos-1>=0 && pos-2>=0 && s[pos-2] == 'a' && s[pos-1] == 'b')st.insert(pos-2);
        }
        s[pos] = c;
        cout<<st.size()<<endl;
    }
    return 0;
}