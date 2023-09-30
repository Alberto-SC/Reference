#include <bits/stdc++.h>
using namespace std;
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,m;
    cin>>n>>m;
    vector<int> v(m);
    string s(m,'0');
    vector<int> need;
    for(int i = 0;i<m;i++){
        s[i] = '1';
        int x;
        cout<<"? "<<s<<endl;
        cin>>x;
        v[i] = x;
        s[i] = '0';
    }
    s = string(m,'1');
    int mx = 0,mn = 1e12;
    vector<int> z(m);
    for(int i = 0;i<m;i++){
        s[i] = '0';
        int x;
        cout<<"? "<<s<<endl;
        cin>>x;
        z[i] = x;
        mx = max(mx,x);
        mn = min(mn,x);
        s[i] = '1';
    }

    if(mn == mx){
        int sum = accumulate(v.begin(),v.end(),0);
        cout<<"! "<<sum<<endl;
        return 0;
    }
    string t(m,'0');
    set<int> st;
    for(int i = 0;i<m;i++)st.insert(i);
    for(int i = 0;i<m;i++){
        if(z[i]==mx){
            t[i] = '1';
            st.erase(i);
            need.push_back(i);
        }
        else if(mx-v[i]== z[i]){
            t[i] = '1';
            st.erase();
            need.push_back(i);
        }
    }
    vector<int> rem;
    for(auto c:st){
        rem.push_back(c);
    }
    sort(rem.begin(),rem.end(),[&](int a,int b){
        return v[a]>v[b];
    });


    for(int i = 0;i<rem.size();i++){
        1
    }
    

    return 0;
}